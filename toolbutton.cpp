#include "ToolButton.h"
#include <QIcon>
#include <QDebug>

ToolButton::ToolButton(QWidget *parent, const QString &toolName)
    : QToolButton(parent), toolName(toolName)
{
    // 设置按钮的文本和图标
    setText(toolName);
    setIcon(QIcon(":/image/" + toolName.toLower() + ".png"));  // 这里使用名称来设置图标
    setToolButtonStyle(Qt::ToolButtonTextBesideIcon);  // 设置文本和图标并排显示

    // 连接按钮的点击事件到槽函数
    connect(this, &QToolButton::clicked, this, &ToolButton::onClicked);
}

ToolButton::~ToolButton()
{
}

void ToolButton::onClicked()
{
    // 当按钮被点击时，发出 toolClicked 信号，传递工具名称
    emit toolClicked(toolName);
}
