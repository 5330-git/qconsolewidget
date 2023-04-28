#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setUserInputColor(QColor(Qt::blue));
    this->thread_ptr = new IOThread(ui->plainTextEdit);
    connect(ui->start_btn,&QPushButton::clicked,this,[=](){
        qDebug()<<"启动运行";
        this->thread_ptr->start();
        qDebug()<<"开始运行";
    });

    connect(ui->end_btn,&QPushButton::clicked,this,[=](){
        this->thread_ptr->terminate();
        this->thread_ptr->wait();
    });

    connect(ui->clear_btn,&QPushButton::clicked,ui->plainTextEdit,&AntonaQConsoleWidget::QConsoleWidget::slot_clearContents);
}

MainWindow::~MainWindow()
{

    this->thread_ptr->terminate();
    this->thread_ptr->wait();
    delete this->thread_ptr;
    this->thread_ptr = nullptr;
    delete ui;
}

