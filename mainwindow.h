#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "Widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT // Q_OBJECT宏，允许类中使用信号和槽的机制

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showHelpDialog();
    void onNewGameBtnClicked();
    void onContinueGameBtnClicked();
    void onExitBtnClicked();
    void showMainMenu();  // 显示主菜单
    void showGameWidget();  // 显示游戏界面

private:
    Ui::MainWindow *ui;
    Widget *widget;
};
#endif // MAINWINDOW_H
