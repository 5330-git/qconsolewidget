#include "iothread.h"
#include "QConsoleWidget.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
IOThread::IOThread(QConsoleWidget* ptr){
    this->widget_ptr = ptr;
}

void th1_task(QConsoleWidget* ptr){
    std::ostream th1_out(ptr->getOutBuffer());
    for(int i = 0;i<50;++i){
        th1_out<<"我爱深北莫"<<endl;
    }
}

void th2_task(QConsoleWidget* ptr){
    std::ostream th1_out(ptr->getOutBuffer());
    for(int i = 0;i<50;++i){
        th1_out<<"I love SMBU"<<endl;
    }
}

void th3_task(QConsoleWidget* ptr){
    std::ostream th1_out(ptr->getOutBuffer());
    for(int i = 0;i<50;++i){
        th1_out<<"Я МГУ-ППИ люблю"<<endl;
    }
}

void IOThread::run(){

    std::ostream tout(this->widget_ptr->getOutBuffer());
    std::ostream terr(this->widget_ptr->getErrBuffer());
    std::istream tin(this->widget_ptr->getInBuffer());

    // 刷新上一次线程调用时的输入流的缓冲
    tin.sync();
    int int_arg = 0;
    long long_arg = 0;
    double double_arg = 0;
    string string_arg;
    bool bool_arg = false;
    tout<<"请输入int 型的变量: ";
    tin>>int_arg;
    tout<<"你输入的 int 型变量是： "<<int_arg<<endl;

    tout<<"请输入long 型的变量: ";
    tin>>long_arg;
    tout<<"你输入的 long 型变量是： "<<long_arg<<endl;
    tout<<"请输入double 型的变量: ";
    tin>>double_arg;
    tout<<"你输入的 double 型变量是： "<<double_arg<<endl;
    tout<<"请输入string 型的变量: ";
    tin>>string_arg;
    tout<<"你输入的 string 型变量是： "<<string_arg<<endl;

    tout<<"请输入bool 型的变量: (0或1，输入1测试错误流输出)";
    tin>>bool_arg;
    if(bool_arg){
        terr<<"错误流测试"<<endl;
    }
    else{
        tout<<"你输入的 int 型变量是： "<<bool_arg<<endl;
    }

    tout<<"以下进行多线程(std::thread)无锁输出测试"<<endl;
    tout<<"延时两秒（std::this_thread::sleep_for）"<<endl;
    this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::thread th1(th1_task,this->widget_ptr);
    std::thread th2(th2_task,this->widget_ptr);
    std::thread th3(th3_task,this->widget_ptr);
    th1.join();
    th2.join();
    th3.join();
}
