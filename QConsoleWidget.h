#ifndef QCONSOLEWIDGET_H
#define QCONSOLEWIDGET_H

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

#include "HistoryStorage.h"
#include <QPlainTextEdit>
#include <QKeyEvent>
#include "QConsoleWidgetBuffer.h"
#include <QTextBlock>
#include <QMutex>
#include <QWaitCondition>
#include <iostream>
#include <QStringRef>           // 使用该头文件需要在.pro文件中添加 QT      += core5compat

// Forward declaration
namespace AntonaQConsoleWidget{
    class QConsoleWidget;
}

// Details:
namespace AntonaQConsoleWidget{
    class QConsoleWidget:public QPlainTextEdit{
        Q_OBJECT
    public:
        friend class ConsoleInBuffer;
        friend class ConsoleOutBuffer;
    protected:
        QTextCursor editable_flag_cursor;
        HistoryStorage<QString> storage;
        bool userInputAcceptable;
        QMutex userInputAcceptable_mutex;
        QWaitCondition waitForConsume;
        ConsoleInBuffer* inbuffer;
        ConsoleOutBuffer* outbuffer;
        ConsoleErrBuffer* errbuffer;
        QColor userInputColor;

        bool isEditablePosition()const;
        void fixEditablePosition();
        void moveToEditablePositionStart();
        void moveToEditablePositionEnd();
        virtual bool isLawfulKey(QKeyEvent* event);
        virtual void keyPressEvent(QKeyEvent* event)override;
        virtual bool event(QEvent* event)override;
    public:
        inline ConsoleInBuffer* getInBuffer()const{
            return this->inbuffer;
        }
        inline ConsoleErrBuffer* getErrBuffer()const{
            return this->errbuffer;
        }
        inline ConsoleOutBuffer* getOutBuffer()const{
            return this->outbuffer;
        }


        QConsoleWidget(QWidget* parent = nullptr);
        virtual ~QConsoleWidget();
    public slots:
        void setUserInputColor(const QColor&color);
        void setOutputColor(const QColor&color);
        void setErrColor(const QColor&color);
        void slot_outputChar(int char_code,QColor color);
        void slot_outputString(QString str,QColor color);
        void slot_clearContents();
    };
}
#endif
