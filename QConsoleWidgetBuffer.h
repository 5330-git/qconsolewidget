#ifndef QCONSOLEWIDGETBUFFER_H
#define QCONSOLEWIDGETBUFFER_H

/*
* Decoded by Utf-8
* Versions
*   v-1.0.0 2023/4/27
* Author:
*   Anton :blog address --> https://blog.csdn.net/yyy11280335?spm=1000.2115.3001.5343
*
* Introduction:
*   本文件用于实现控制台io模拟控件的界面
*   This file is created to realize the console like io widget uer interface
*/

#include <streambuf>
#include <vector>
#include <QObject>
#include <QColor>

// Forward Declaration
namespace AntonaQConsoleWidget{
    class QConsoleWidget;
    class ConsoleInBuffer;
    class ConsoleOutBuffer;
    class ConsoleErrBuffer;
}

// Details:
namespace AntonaQConsoleWidget{
    class ConsoleInBuffer:public std::streambuf{
    private:
        std::vector<std::streambuf::char_type> buffer;
    protected:
        QConsoleWidget* widget_ptr = nullptr;

        virtual std::streambuf::int_type overflow(std::streambuf::int_type c)override;
        virtual std::streambuf::int_type underflow()override;
        virtual std::streambuf::int_type pbackfail(std::streambuf::int_type c)override;
        virtual int sync()override;
    public:
        ConsoleInBuffer(QConsoleWidget* ptr);
        ConsoleInBuffer()=delete;
        virtual ~ConsoleInBuffer(){};
    };



    class ConsoleOutBuffer:public QObject,public std::streambuf{
        Q_OBJECT
    protected:
        QConsoleWidget* widget_ptr = nullptr;
        QColor fontColor;

        virtual std::streamsize xsputn(const char_type* s, std::streamsize n)override;
        virtual std::streambuf::int_type overflow(std::streambuf::int_type c)override;
    public:
        ConsoleOutBuffer()=delete;
        ConsoleOutBuffer(QConsoleWidget* ptr,QColor defaultColor = QColor(Qt::black));
        virtual ~ConsoleOutBuffer(){};
        void setFontColor(const QColor& color);
    signals:
        void sig_output_c(std::streambuf::int_type c,QColor color);
        void sig_output_str(QString str,QColor color);
    };


    class ConsoleErrBuffer:public ConsoleOutBuffer{
    public:
        ConsoleErrBuffer(QConsoleWidget* ptr,QColor defaultColor = QColor(Qt::red));
        ConsoleErrBuffer()=delete;
    };
}
#endif
