#include <QApplication>
#include <QTimer>
#include <QDebug>
#include <QtGlobal>
#include <vector>
#include <iostream>
#include "mainwindow.h"
#include "MainModel/MainModel.h"

//#define DEBUG 1
//#include "MainModel/entity/Creature.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setMinimumSize(800,600);
    w.show();
    return a.exec();
}
//TODO:fix generator food(pause)
