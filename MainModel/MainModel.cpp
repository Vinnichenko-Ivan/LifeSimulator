#include "MainModel.h"

#include <QTimer>
#include <QDebug>

#include "entity/public/IOldingCreatures.h"

void MainModel::addNewCreature(Creature creature)
{
    addCreature(creature);
}

void MainModel::addNewCreatures(std::vector<Creature> creatures)
{
    qDebug()<<"addNewCreatures";
    for(Creature some: creatures)
    {
        addCreature(some);
    }
}

MainModel::MainModel( QObject *parent): QObject(parent){
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainModel::update);
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

void  MainModel::pauseLife()
{
    isPaused = !isPaused;
}

