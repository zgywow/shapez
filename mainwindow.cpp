#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "popup.h"

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

    QPushButton * restartBtn = new QPushButton("Restart", this);
    restartBtn->move(350,350);


    QPushButton * exitBtn = new QPushButton("Exit", this);
    //移动btn2
    exitBtn->move(350, 380);
    // 连接函数的参数分别是：信号的接收者，发送的信号(函数地址)，信号的接收者，处理的槽函数(函数地址)
    // 点击exitBtn来关闭窗口,并出现确认弹窗
    connect(exitBtn, &QPushButton::clicked, this, &MainWindow::onExitClicked);

    //实现自定义信号时，信号只需要声明不需要实现（返回值为void），可以重载
    //槽函数就需要声明并实现（返回值也是void，写在public/private slots下）
    //可以用emit触发信号,例如
    //connect(object, &Object::signal, slot, &Slot::react);
    //emit object->(signal);
}

void MainWindow::onExitClicked()
{
    Popup *popup = new Popup(this, "Are you sure you want to exit?");
    if (popup->exec() == QDialog::Accepted) {
        close();  // 用户点击确认退出游戏
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
