#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include "ui_widget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onSettingBtnClicked();
    void onShopBtnClicked();
    void onToolClicked(const QString &toolName);

private:
    Ui::Widget *ui;  // 通过 UI 文件引用控件
    QLabel *operationDesc;  // 操作说明标签
};

#endif // WIDGET_H
