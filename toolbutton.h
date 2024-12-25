#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QToolButton>
#include <QString>
#include <QIcon>
#include <QWidget>

class ToolButton : public QToolButton
{
    Q_OBJECT

public:
    // 构造函数，接受文本和图标路径
    explicit ToolButton(QWidget *parent = nullptr, const QString &toolName = "");
    ~ToolButton();

signals:
    // 定义一个信号，当按钮被点击时发出工具名称
    void toolClicked(const QString &toolName);

private slots:
    // 按钮点击事件的处理函数
    void onClicked();

private:
    QString toolName;  // 用于存储工具的名称
};

#endif // TOOLBUTTON_H
