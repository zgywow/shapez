#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Widget.h"
#include <QToolBar>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 重置窗口大小
    resize(1200, 675);

    connect(ui->newGameBtn, &QPushButton::clicked, this, &MainWindow::onNewGameBtnClicked);
    connect(ui->continueGameBtn, &QPushButton::clicked, this, &MainWindow::onContinueGameBtnClicked);
    connect(ui->exitBtn, &QPushButton::clicked, this, &MainWindow::onExitBtnClicked);
    connect(ui->helpBtn, &QPushButton::clicked, this,&MainWindow::showHelpDialog);

}

void MainWindow::onNewGameBtnClicked()
{
    // 当点击“新游戏”按钮时，隐藏主菜单并显示游戏界面
    // 隐藏主菜单按钮
    ui->newGameBtn->hide();
    ui->continueGameBtn->hide();
    ui->exitBtn->hide();
    ui->helpBtn->hide();

    // 创建 Widget 实例并传递父级
    widget = new Widget(this);
    // 将 Widget 设置为 MainWindow 的中心部件
    setCentralWidget(widget);  // 使用 setCentralWidget 将 Widget 嵌入 MainWindow

}

void MainWindow::onContinueGameBtnClicked()
{
    // 当点击“新游戏”按钮时，隐藏主菜单并显示游戏界面
    // 隐藏主菜单按钮
    ui->newGameBtn->hide();
    ui->continueGameBtn->hide();
    ui->exitBtn->hide();
    ui->helpBtn->hide();

    // 创建 Widget 实例并传递父级
    widget = new Widget(this);
    // 将 Widget 设置为 MainWindow 的中心部件
    setCentralWidget(widget);  // 使用 setCentralWidget 将 Widget 嵌入 MainWindow
}

void MainWindow::showHelpDialog()
{
    // 创建一个消息框
    QMessageBox *msgBox = new QMessageBox(this);

    // 设置消息框的标题和内容
    msgBox->setWindowTitle("帮助");
    msgBox->setText(
        "欢迎来到异形工厂！\n\n"
        "你可以通过拖拽各种工具在地图上搭建自己的工厂，完成任务，升级工厂，以赢取最后的奖杯🏆\n\n"
        "开采器：将开采器放在矿石上可以开采对应矿石\n"
        "传送带：开采器开采的矿石将通过传送带运送至交付中心\n"
        "切割机：切割机只能切割圆形矿石，切割后的矿石将分为两路进行运输\n"
        "垃圾桶：通过在传送带传送方向后面紧接垃圾桶，可以将不需要的矿石回收\n"
        "铁铲：当你摆错或需要重新搭建工厂时，可以通过铁铲将你已经摆放的工具清除\n\n"
        "注：\n"
        "你可以通过键盘上的\"W\" \"A\" \"S\" \"D\"在拖拽时改变对应工具的方向\n"
        "对于传送带，你可以通过同时按下其中两个或两个键加上\"R\"来刻画它的各种转向\n"
        "只有输出及运送物品的方向正确，工厂才能正常运行，否则会停滞\n\n"
        "每个新关卡开始时，你可以选择升级开采器、传送带、切割机中的一个，以提升它们的速率\n"
        "通过消耗金币，你可以在商店中升级交付中心，提升矿石价值或者清除障碍\n\n"
        "根据每一关的任务，你需要开采一定数量的特定矿石，通过三关后即可获胜\n\n"
        "感谢游玩"
        );

    // 设置透明背景
    //msgBox->setStyleSheet("QMessageBox { background-color: transparent; }");

    // 设置消息框为适应内容自动调整大小
    msgBox->adjustSize();

    // 计算居中位置
    QPoint mainWindowPos = this->mapToGlobal(this->rect().center());
    QPoint dialogPos = mainWindowPos - QPoint(msgBox->width() / 2, msgBox->height() / 2);

    // 将消息框移到居中位置
    msgBox->move(dialogPos);

    // 显示消息框
    msgBox->exec();
}


// 点击退出按钮时弹出确认框
void MainWindow::onExitBtnClicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Exit",
                                  "确认要退出游戏吗",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        close();  // 用户点击“是”时关闭窗口
    }
}

void MainWindow::showMainMenu()
{
    // 显示主菜单（隐藏游戏界面时，恢复显示）
    ui->newGameBtn->show();
    ui->continueGameBtn->show();
    ui->exitBtn->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
