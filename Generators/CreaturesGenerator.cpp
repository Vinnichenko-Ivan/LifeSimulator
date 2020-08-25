#include "CreaturesGenerator.h"

CreaturesGenerator::CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent) : QObject(parent)
{
    createCreature=createCreatureIn;
}

void CreaturesGenerator::updateSizeArena()
{
    std::pair<int,int> size = createCreature->getSizeArena();
    wight=size.first;
    height=size.second;
}

void CreaturesGenerator::addCreature()
{

    Creature * creature=new Creature(id);
    updateSizeArena();
    int x=rand()%wight;
    int y=rand()%height;
    Cordinate * cordinate= new Cordinate(x,y);
    qDebug()<<"add Creature with id: "<<id<< "cordinates x:"<<x<<" y:"<<y;
    createCreature->addNewCreature(creature,cordinate);
    id++;
}
