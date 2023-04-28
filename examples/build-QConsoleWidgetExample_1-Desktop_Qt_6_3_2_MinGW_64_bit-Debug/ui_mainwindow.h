/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QConsoleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *start_btn;
    QPushButton *end_btn;
    QPushButton *clear_btn;
    AntonaQConsoleWidget::QConsoleWidget *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *userinputColor_status;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        start_btn = new QPushButton(widget);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));

        verticalLayout->addWidget(start_btn);

        end_btn = new QPushButton(widget);
        end_btn->setObjectName(QString::fromUtf8("end_btn"));

        verticalLayout->addWidget(end_btn);

        clear_btn = new QPushButton(widget);
        clear_btn->setObjectName(QString::fromUtf8("clear_btn"));

        verticalLayout->addWidget(clear_btn);


        horizontalLayout->addWidget(widget);

        plainTextEdit = new AntonaQConsoleWidget::QConsoleWidget(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        userinputColor_status = new QStatusBar(MainWindow);
        userinputColor_status->setObjectName(QString::fromUtf8("userinputColor_status"));
        MainWindow->setStatusBar(userinputColor_status);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        start_btn->setText(QCoreApplication::translate("MainWindow", "StartThread", nullptr));
        end_btn->setText(QCoreApplication::translate("MainWindow", "EndThread", nullptr));
        clear_btn->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
