#include "MainModel.h"

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
    if(onPause)
    {

    }
    else
    {
        qDebug()<<"i old: "<<oldingCreaturesInterface.size()<< " creatures";
        oldingCreaturesInterface[0]->update();
//        for(auto n :oldingCreaturesInterface)
//        {
//            n->update();
//        }
    }
}

void MainModel::update()
{
    qDebug() << Q_FUNC_INFO;
    oldingCreatures();
}
void  MainModel::pauseLife()
{
    if(onPause)
    {
        onPause=0;
    }
    else
    {
        onPause=1;
    }
}

