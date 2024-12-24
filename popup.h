#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

class Popup : public QDialog
{
    Q_OBJECT

public:
    // 构造函数，接受父窗口和消息文本
    explicit Popup(QWidget *parent = nullptr, const QString &message = "");
    ~Popup();

private slots:
    // 点击“确认”按钮时触发的槽函数
    void onConfirmClicked();
    // 点击“取消”按钮时触发的槽函数
    void onCancelClicked();

private:
    // 弹窗的确认按钮
    QPushButton *confirmButton;
    // 弹窗的取消按钮
    QPushButton *cancelButton;
    // 显示提示消息的标签
    QLabel *messageLabel;
};

#endif // POPUP_H
