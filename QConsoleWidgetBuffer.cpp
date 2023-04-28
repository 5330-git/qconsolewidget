#include "QConsoleWidget.h"
#include "QConsoleWidgetBuffer.h"

namespace AntonaQConsoleWidget{
    std::streambuf::int_type ConsoleInBuffer::overflow(std::streambuf::int_type c){
        size_t read_pos = this->gptr()-this->eback();
        // 将buffer扩大到原来的二倍
        size_t pre_size = this->buffer.size();
        this->buffer.resize(this->buffer.size()*2);
        // 将输入缓冲区的三个指针和输出缓冲区的三个指针重定向
            // 写入缓冲区的指针pbase,pptr,epptr
        this->setp(&(buffer[pre_size-1]),&(buffer.back()));
            // 输出，读取缓冲区的指针eback,gptr,egptr
        this->setg(&(buffer.front()),&(buffer[read_pos]),this->pptr());

        // 字符c是溢出的，还未存到内存中，因此需要调用sputc将其放回内存中
        this->sputc(c);
        return c;
    }

    std::streambuf::int_type ConsoleInBuffer::underflow(){
        // 缓冲区无数据可取
        // 把互斥量user_inputable释放掉，使得窗口可以接收用户的输入


        QMutexLocker locker(&(this->widget_ptr->userInputAcceptable_mutex));
        // 修改标记变量，使得可以接收键盘输入
        this->widget_ptr->userInputAcceptable = true;
        this->widget_ptr->waitForConsume.wait(&(this->widget_ptr->userInputAcceptable_mutex));

        // 读取缓存区指针重定向(扩展读取上限(因为overflow调用时无法确定所有插入数据的大小，因此需要在插入后调整上限)

        this->setg(this->eback(),this->gptr(),this->pptr());
        return traits_type::to_int_type(*gptr());
    }
    std::streambuf::int_type ConsoleInBuffer::pbackfail(std::streambuf::int_type c){
        if(c != EOF){
            if(this->gptr()>this->eback()){
                // 有位置可放回
                this->gbump(-1);        // 将gptr移动到上一个位置
                *(this->gptr()) = c;
            }
            // EOF 会导致后续任何对istream的操作都无效，因此我们不主动返回EOF
        }
        return c;
    }
    int ConsoleInBuffer::sync(){
        // 对于放置区来说，去向重置放置位置
        // 将输入缓冲区的三个指针和输出缓冲区的三个指针重定向
            // 写入缓冲区的指针pbase,pptr,epptr
        this->setp(&(buffer.front()),&(buffer.back()));
            // 输出，读取缓冲区的指针eback,gptr,egptr
                // 即将可读的内容清空
        this->setg(&(buffer.front()),&(buffer.front()),this->pptr());
        // 刷新成功，返回0
        return 0;
    }

    ConsoleInBuffer::ConsoleInBuffer(QConsoleWidget* ptr){
        this->widget_ptr = ptr;
        // 初始化缓冲区大小为16
        this->buffer.resize(16);
        this->setp(&(buffer.front()),&(buffer.back()));
        this->setg(&(buffer.front()),&(buffer.front()),this->pptr());
    }

    std::streamsize ConsoleOutBuffer::xsputn(const char_type* s, std::streamsize n){
        // 多线程下，子线程不能直接访问主线程的QPlainTextEdit对象，必须使用信号与槽进行辅助
        std::string str;    // 中间涉及编码转换，先使用std::string进行接收
        for(int i = 0;i<n;++i){
            if(s[i] != '\r'){
                // windows下的换行符是\r\n,而Qt下的换行符是\n需要转换
                str.append(1,s[i]);
            }
        }

        // 发送信号到主线程
        emit this->sig_output_str(QString::fromStdString(str),this->fontColor);
        return n;       // 表示已经处理过的字符数目
    }
    std::streambuf::int_type ConsoleOutBuffer::overflow(std::streambuf::int_type c){
        // 缓冲区溢出，用于处理控制符endl
        emit this->sig_output_c(c,this->fontColor);
        // 注意父类的overflow永远返回EOF,这样流就会结束
        return c;
    }
    ConsoleOutBuffer::ConsoleOutBuffer(QConsoleWidget* ptr,QColor defaultColor){
        this->widget_ptr = ptr;
        this->fontColor = defaultColor;
    }
    ConsoleErrBuffer::ConsoleErrBuffer(QConsoleWidget* ptr,QColor defaultColor)
        :ConsoleOutBuffer(ptr,defaultColor){
        ;
    }
    void ConsoleOutBuffer::setFontColor(const QColor& color){
        this->fontColor = color;
    }
}
