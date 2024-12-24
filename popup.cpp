#include "popup.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

// 构造函数，设置弹窗界面
Popup::Popup(QWidget *parent, const QString &message)
    : QDialog(parent)
{
    // 设置弹窗标题
    setWindowTitle("Confirm Action");

    // 设置固定大小
    setFixedSize(300, 150);

    // 创建并初始化显示消息的标签
    messageLabel = new QLabel(message, this);

    // 创建并初始化确认按钮和取消按钮
    confirmButton = new QPushButton("Confirm", this);
    cancelButton = new QPushButton("Cancel", this);

    // 创建垂直布局器，添加消息标签
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(messageLabel);

    // 创建水平布局器，添加确认按钮和取消按钮
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(confirmButton);
    hLayout->addWidget(cancelButton);

    // 将水平布局添加到垂直布局中
    vLayout->addLayout(hLayout);

    // 设置弹窗的布局为垂直布局
    setLayout(vLayout);

    // 连接按钮的点击信号到相应的槽函数
    connect(confirmButton, &QPushButton::clicked, this, &Popup::onConfirmClicked);
    connect(cancelButton, &QPushButton::clicked, this, &Popup::onCancelClicked);
}

// 析构函数，清理资源
Popup::~Popup()
{
}

// “确认”按钮的槽函数，点击时接受弹窗并关闭
void Popup::onConfirmClicked()
{
    accept();  // 返回 QDialog::Accepted，关闭弹窗
}

// “取消”按钮的槽函数，点击时拒绝弹窗并关闭
void Popup::onCancelClicked()
{
    reject();  // 返回 QDialog::Rejected，关闭弹窗
}
