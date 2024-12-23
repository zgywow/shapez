#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // //重置窗口大小
    // resize(800, 600);

    // 设置为固定大小
    setFixedSize(800, 600);

    //设置窗口标题
    setWindowTitle("SHAPEZ");

    // // 创建按钮
    // QPushButton * btn1 = new QPushButton;
    // // 让btn1对象依赖在myWindow中
    // btn1->setParent(this);
    // // 显示文本
    // btn1->setText("Start");

    QPushButton * startBtn = new QPushButton("Start", this);
    startBtn->move(350,320);

    QPushButton * exitBtn = new QPushButton("Exit", this);
    //移动btn2
    exitBtn->move(350, 340);
    // 连接函数的参数分别是：信号的接收者，发送的信号(函数地址)，信号的接收者，处理的槽函数(函数地址)
    // 点击exitBtn来关闭窗口
    connect(exitBtn, &QPushButton::clicked, this, &MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}
