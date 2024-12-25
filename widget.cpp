#include "Widget.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);  // 设置 UI

    // 连接 UI 中的按钮信号
    connect(ui->settingBtn, &QToolButton::clicked, this, &Widget::onSettingBtnClicked);
    connect(ui->shopBtn, &QToolButton::clicked, this, &Widget::onShopBtnClicked);

    // 操作说明显示区域
    operationDesc = new QLabel("Select a tool to see its description", this);

    // 连接工具按钮信号
    connect(ui->minerBtn, &QToolButton::clicked, this, [this]() { onToolClicked("Miner"); });
    connect(ui->beltBtn, &QToolButton::clicked, this, [this]() { onToolClicked("Belt"); });
    connect(ui->cutterBtn, &QToolButton::clicked, this, [this]() { onToolClicked("Cutter"); });
    connect(ui->trashBtn, &QToolButton::clicked, this, [this]() { onToolClicked("Trash"); });
    connect(ui->spadeBtn, &QToolButton::clicked, this, [this]() { onToolClicked("Spade"); });

    // 布局设置
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(ui->settingBtn);
    topLayout->addWidget(ui->shopBtn);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(ui->minerBtn);
    bottomLayout->addWidget(ui->beltBtn);
    bottomLayout->addWidget(ui->cutterBtn);
    bottomLayout->addWidget(ui->trashBtn);
    bottomLayout->addWidget(ui->spadeBtn);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    mainLayout->addWidget(operationDesc);

    setLayout(mainLayout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onSettingBtnClicked()
{
    QMessageBox::information(this, "Settings", "This is the settings window.");
}

void Widget::onShopBtnClicked()
{
    QMessageBox::information(this, "Shop", "This is the shop window.");
}

void Widget::onToolClicked(const QString &toolName)
{
    QString description;
    if (toolName == "Miner") {
        description = "This is the miner tool. Used for connecting components.";
    } else if (toolName == "Belt") {
        description = "This is the belt tool. Used for transporting items.";
    } else if (toolName == "Cutter") {
        description = "This is the cutter tool. Used for cutting items.";
    } else if (toolName == "Trash") {
        description = "This is the trash tool. Used for discarding items.";
    } else if (toolName == "Spade") {
        description = "This is the spade tool. Used for digging.";
    }

    operationDesc->setText(description);
}
