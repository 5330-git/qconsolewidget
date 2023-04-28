#ifndef IOTHREAD_H
#define IOTHREAD_H

#include <QThread>
#include "QConsoleWidget.h"
using namespace AntonaQConsoleWidget;
class IOThread:public QThread{
    Q_OBJECT
protected:
    QConsoleWidget* widget_ptr = nullptr;
public:
    IOThread(QConsoleWidget* ptr);
    virtual void run()override;
};

#endif // IOTHREAD_H
