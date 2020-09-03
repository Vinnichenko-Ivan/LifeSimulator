#include <QApplication>
#include <QTimer>
#include <QDebug>
#include <QtGlobal>
#include <vector>
#include <iostream>
#include "GUI/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.setMinimumSize(800,600);
    mainWindow.show();
    return a.exec();
}
//TODO:fix generator food(pause)
