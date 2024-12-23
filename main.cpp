#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //ctrl + i 自动对齐
    //F4 在头文件和源文件快速切换
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
