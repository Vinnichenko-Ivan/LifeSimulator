#include "MainModel.h"

#include <QTimer>
#include <QDebug>

#include "entity/public/IOldingCreatures.h"

void MainModel::addNewCreature(Creature * creature)
{
    creatures.push_back(creature);
    oldingCreaturesInterface.push_back(creature);
}

MainModel::MainModel( QObject *parent): QObject(parent){
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainModel::update);
    start();
}


void MainModel::start() {
    timer->start(1000 / 24);
}

void MainModel::stop() {
    timer->stop();
}

void MainModel::oldingCreatures()
{
    if(isPaused)
    {

    }
    else
    {
        for(auto * n : oldingCreaturesInterface)
        {
            n->update();
        }
    }
}

void MainModel::update()
{
    oldingCreatures();
}

void  MainModel::pause()
{
    isPaused = !isPaused;
}

