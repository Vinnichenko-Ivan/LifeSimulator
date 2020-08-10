#include <QTimer>
#include <QDebug>
#include "public/IOldingCreatures.hpp"
#include "entity/Creature.cpp"
#include "MainModel.hpp"



MainModel::MainModel(QObject *parent): QObject(parent) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainModel::update);
    Creature creature;
    addCreature(creature);
    start();
}

void MainModel::addCreature(Creature newCreature)
{
    creatures.push_back(newCreature);
    oldingCreaturesInterface.push_back(&creatures[creatures.size()-1]);
}

void MainModel::start() {
    timer->start(1000 / 24);
}

void MainModel::stop() {
    timer->stop();
}

void MainModel::oldingCreatures()
{
    for(auto * n : oldingCreaturesInterface)
    {
        n->update();
    }
}

void MainModel::update()
{
    //oldingCreatures();
    qDebug() << Q_FUNC_INFO;
    oldingCreatures();
}
