#include "MainModel.h"
#define PI 3.14159265
void MainModel::addNewCreature(Creature * creature,Cordinate * cordinate)
{
    creatures.push_back(creature);
    oldingCreaturesInterface.push_back(creature);
    doings.push_back(creature);
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
        for(int i=0;i< doings.size();i++)
        {
            Path path =doings[i]->going();
            goToNewCordinate(cordinates[i],path);
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
        n->x=std::min(n->x,(double)wight-10);
        n->y=std::min(n->y,(double)height-10);
    }
}
void MainModel::goToNewCordinate(Cordinate * oldCordinate,Path path)
{
    oldCordinate->x+=std::sin( (double)path.angle * PI / (double)180)*path.path;
    oldCordinate->y+=std::cos( (double)path.angle * PI / (double)180)*path.path;
}
