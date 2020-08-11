#include <QApplication>
#include <QTimer>
#include <QDebug>
#include <QtGlobal>
#include <vector>
#include <iostream>
#include "mainwindow.h"
#include "MainModel/public/IOldingCreatures.hpp"
#include "MainModel/entity/Creature.cpp"
#include "MainModel/MainModel.hpp"
//#include "MainModel/entity/Creature.hpp"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(800,600);
    w.show();
    return a.exec();
}
