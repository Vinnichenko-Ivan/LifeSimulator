#include "MainModel.h"

void MainModel::addNewCreature(Creature * creature,Cordinate * cordinate)
{
    creatures.push_back(creature);
    oldingCreaturesInterface.push_back(creature);
    cordinates.push_back(cordinate);
}

void MainModel::updateArenaSize(int wightNew,int heightNew)
{
    wight=wightNew;
    height=heightNew;
    recountCordinate();
}

std::pair<int,int> MainModel::getSizeArena()
{
   return std::pair<int,int>(wight,height);
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

void MainModel::recountCordinate()
{
    for(auto*n:cordinates)
    {
        n->x=std::min(n->x,wight-10);
        n->y=std::min(n->y,height-10);
    }
}
