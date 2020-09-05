#include "CreaturesGenerator.h"

CreaturesGenerator::CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent) : QObject(parent)
{
    createCreature=createCreatureIn;
    cultureCreatures.push_back("default");
    cultureCreatures.push_back("default1");
    cultureCreatures.push_back("default2");
    cultureCreatures.push_back("default3");
}

void CreaturesGenerator::updateSizeArena()
{

    std::pair<int,int> size = createCreature->getSizeArenaForCreatures();
    wight=size.first;
    height=size.second;
}

void CreaturesGenerator::addCreature()
{
    id=createCreature->getId();
    Condithions * condithions = new Condithions(id);
    Creature * creature=new Creature(*condithions);
    updateSizeArena();
    int x=rand()%wight;
    int y=rand()%height;
    Cordinate * cordinate= new Cordinate(x,y);
    condithions->typeCreature=thisCulture;
    qDebug()<<"add Creature with id: "<<id<< "cordinates x:"<<x<<" y:"<<y;
    createCreature->addNewCreature(creature,cordinate,condithions);
    id++;
    createCreature->setId(id);
}

std::vector<std::string> CreaturesGenerator::getCultureCreatures()
{
    return cultureCreatures;
}

void CreaturesGenerator::setCultureCreatures(std::string in)
{
    thisCulture=in;
}

std::string CreaturesGenerator::getSetCultureCreatures()
{
    return thisCulture;
}
