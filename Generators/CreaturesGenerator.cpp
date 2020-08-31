#include "CreaturesGenerator.h"

CreaturesGenerator::CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent) : QObject(parent)
{
    createCreature=createCreatureIn;
}

void CreaturesGenerator::updateSizeArena()
{
    std::pair<int,int> size = createCreature->getSizeArenaForCreatures();
    wight=size.first;
    height=size.second;
}

void CreaturesGenerator::addCreature()
{
    Condithions * condithions = new Condithions(id);
    Creature * creature=new Creature(*condithions);
    updateSizeArena();
    int x=rand()%wight;
    int y=rand()%height;
    Cordinate * cordinate= new Cordinate(x,y);
    qDebug()<<"add Creature with id: "<<id<< "cordinates x:"<<x<<" y:"<<y;
    createCreature->addNewCreature(creature,cordinate,condithions);
    id++;
}
