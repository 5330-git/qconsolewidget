#include "QConsoleWidget.h"

namespace AntonaQConsoleWidget{
    bool QConsoleWidget::isLawfulKey(QKeyEvent* event){
        // 该函数用于检查用户输入的按键是否需要接受
        if(!(this->isEditablePosition())){
            // 非可插入行，
            switch(event->key()){
            case Qt::Key_Control:
                return true;
                break;
            case Qt::Key_Shift:
                return true;
                break;
            }

            switch(event->modifiers()){

            case Qt::Key_Control:
                return true;
                break;
            case Qt::ControlModifier:
                if(event->key() == Qt::Key_C){
                    return true;
                }
                return false;
                break;

            default:
                return false;

            }
        }
        // 可插入行设置
            // 一般的组合
        else if(event->key() == Qt::Key_Backspace &&
                this->textCursor() == this->editable_flag_cursor){
            // 可插入行行首不可退格
            return false;
        }
            // 有选中文本的组合
        else if(this->textCursor().hasSelection()){
            // 获取选择区域的锚点位置，检查是否在不可编辑区域内
            int anchor_position = this->textCursor().anchor();
            if(anchor_position < this->editable_flag_cursor.position()){
                // 锚点在不可编辑区域内，因此只能执行文本拷贝有关的操作即ctrl+c
                if(event->modifiers() == Qt::ControlModifier && event->key()==Qt::Key_C){
                    return true;
                }
                else if(event->key() == Qt::Key_Control){
                    return true;
                }
                else if(event->key() == Qt::Key_Shift){
                    return true;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }

    void QConsoleWidget::keyPressEvent(QKeyEvent* event){

        // 检查是否有编辑权
        if(!this->userInputAcceptable){
            // 无编辑权，将按键事件丢弃
            return ;
        }

        QTextCharFormat user_fmt;
        user_fmt.setForeground(QBrush(this->userInputColor));
        this->mergeCurrentCharFormat(user_fmt);
        if(event->key() == Qt::Key_Up){
            // 用户按上方向键，向前回滚消息
                // 首先将可视光标移动到可编辑区域之首
            this->moveToEditablePositionStart();
            // 此时插入文本的颜色一定要设定为用户输入颜色
            QTextCharFormat rollback_fmt;
            rollback_fmt.setForeground(QBrush(this->userInputColor));
            this->mergeCurrentCharFormat(rollback_fmt);
            QTextCursor curs = this->textCursor();
                // 以固定锚点的方式移动光标，选中用户的输入,将其删除
            curs.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
            curs.removeSelectedText();
            // 向前读取历史输入
            QString str = this->storage.readForward();

            this->mergeCurrentCharFormat(rollback_fmt);
            this->insertPlainText(str);


            return ;
        }
        if(event->key() == Qt::Key_Down){
            // 用户按下方向键，向后回滚消息
            this->moveToEditablePositionStart();
            QTextCharFormat rollback_fmt;
            rollback_fmt.setForeground(QBrush(this->userInputColor));
            this->mergeCurrentCharFormat(rollback_fmt);

            QTextCursor curs = this->textCursor();
            curs.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
            curs.removeSelectedText();
            // 此时插入文本的颜色一定要设定为用户输入颜色

            QString str = this->storage.readBackward();

            this->mergeCurrentCharFormat(rollback_fmt);
            this->insertPlainText(str);

            return ;
        }
        if(!this->isLawfulKey(event)){
            this->moveToEditablePositionEnd();
            return ;
        }

        if(event->key() == Qt::Key_Return){
            // 核心逻辑，用户回车后
                // 获取正在编辑的文本块，将用户输入的部分读取出来
            QTextBlock edit_block = this->textCursor().block();
            QString user_input_str;
            QString block_text = edit_block.text();
            int begin_edit_pos = this->editable_flag_cursor.positionInBlock();
            QStringRef ref(&block_text,begin_edit_pos,block_text.size()-begin_edit_pos);
            user_input_str.append(ref);
                // 将用户输入放入历史容器
            // 回车时需要设置相关位置，这里采用手动方式进行换行
            this->insertPlainText("\n");
            this->fixEditablePosition();    // 固定可编辑区域起始点
            this->document()->clearUndoRedoStacks();    // 清空撤销历史，不允许用户撤销不可编辑区的输入
            if(!ref.size()){
                // 如果用户没有输入就不存储数据，和唤醒等待的线程
                return;
            }
            this->storage.push(user_input_str);



            // 生产者-消费者模型部分，向输入流缓冲区放置数据
            this->userInputAcceptable_mutex.lock();
            user_input_str+='\n';           // 回车换行符需要放入输入流缓冲区
            std::ostream put_data(this->getInBuffer());
            put_data<<user_input_str.toStdString();
                // 将标记变量归为假，直到由输入流再次修改为真
            this->userInputAcceptable = false;
            this->userInputAcceptable_mutex.unlock();
                // 唤醒所有等待输入的线程
            this->waitForConsume.wakeAll();

            return;
        }
        // 其它的键盘输入，调用基类的版本进行处理
        this->QPlainTextEdit::keyPressEvent(event);
    }

    bool QConsoleWidget::event(QEvent* event){
        // 输入法事件不被keyPressEvent解决，需要在event中进行处理
        if(event->type() == QEvent::InputMethod){
            if(!this->isEditablePosition()||!this->userInputAcceptable){
                return true;
            }
        }
        return this->QPlainTextEdit::event(event);
    }

    bool QConsoleWidget::isEditablePosition()const{
        // 如果可视光标在标记光标之前出现就表示可视光标所在位置不可被编辑
        return this->textCursor() >= this->editable_flag_cursor;
    }

    void QConsoleWidget::fixEditablePosition(){
        // 将可视光标的当前位置设置为新的可编辑区域起始点
        this->editable_flag_cursor = this->textCursor();
        this->editable_flag_cursor.setKeepPositionOnInsert(true);
    }

    void QConsoleWidget::moveToEditablePositionStart(){
        QTextCursor cur = this->editable_flag_cursor;
        cur.setKeepPositionOnInsert(false);
        this->setTextCursor(cur);
    }

    void QConsoleWidget::moveToEditablePositionEnd(){
        QTextCursor cur = this->textCursor();
        cur.movePosition(QTextCursor::End);
        this->setTextCursor(cur);
    }

    QConsoleWidget::QConsoleWidget(QWidget* parent):QPlainTextEdit(parent){
        this->outbuffer = new  ConsoleOutBuffer(this);
        this->inbuffer = new ConsoleInBuffer(this);
        this->errbuffer = new ConsoleErrBuffer(this);
        this->userInputColor = QColor(Qt::black);
        this->setContextMenuPolicy(Qt::NoContextMenu);      // 禁用右键菜单
        // 连接信号与槽
        connect(this->outbuffer,&ConsoleOutBuffer::sig_output_str,this,&QConsoleWidget::slot_outputString);
        connect(this->outbuffer,&ConsoleOutBuffer::sig_output_c,this,&QConsoleWidget::slot_outputChar);

        connect(this->errbuffer,&ConsoleErrBuffer::sig_output_str,this,&QConsoleWidget::slot_outputString);
        connect(this->errbuffer,&ConsoleErrBuffer::sig_output_c,this,&QConsoleWidget::slot_outputChar);
        this->fixEditablePosition();            // 可编辑位置初始化
    }

    QConsoleWidget::~QConsoleWidget(){
        // 唤醒所有的被阻塞输入的线程
        this->waitForConsume.wakeAll();
        delete this->outbuffer;
        delete this->inbuffer;
        delete this->errbuffer;
    }
    void QConsoleWidget::setUserInputColor(const QColor& color){
        this->userInputColor = color;
    }
    void QConsoleWidget::setOutputColor(const QColor& color){
        this->outbuffer->setFontColor(color);
    }
    void QConsoleWidget::setErrColor(const QColor& color){
        this->errbuffer->setFontColor(color);
    }
    void QConsoleWidget::slot_outputChar(int char_code,QColor color){
        this->moveToEditablePositionEnd();
        this->fixEditablePosition();

        QChar c(char_code);

        QTextCharFormat fmt;
        fmt.setForeground(QBrush(color));
        this->mergeCurrentCharFormat(fmt);

        // 输出字符
        this->moveToEditablePositionEnd();
        this->insertPlainText(c);
        this->fixEditablePosition();
        this->document()->clearUndoRedoStacks();



    }
    void QConsoleWidget::slot_outputString(QString str,QColor color){
        this->moveToEditablePositionEnd();
        this->fixEditablePosition();

        QTextCharFormat fmt;
        fmt.setForeground(QBrush(color));
        this->mergeCurrentCharFormat(fmt);

        // 输出字符

        this->insertPlainText(str);
        this->fixEditablePosition();
        this->document()->clearUndoRedoStacks();



    }
    void QConsoleWidget::slot_clearContents(){
        this->clear();
        this->fixEditablePosition();
    }

}
