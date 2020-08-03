#include <QApplication>
#include <QTimer>
#include <QDebug>
#include "mainwindow.h"
#include "MainModel/MainModel.hpp"
//#include "MainModel/entity/Creature.hpp"

#include <QtGlobal>
#include <vector>
#include <iostream>
MainModel mainModel;
int main(int argc, char *argv[])
{

    mainModel.creatures.push_back(new Creature);
    mainModel.update();
    QTimer *timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, &mainModel, &MainModel::update);
    timer->start(1000);


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
