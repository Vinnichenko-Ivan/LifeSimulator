#include "CreaturesGenerator.h"

CreaturesGenerator::CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent) : QObject(parent)
{
    createCreature=createCreatureIn;
    updateCultures();
    thisCulture=cultures[0];
    numberThisCulture=0;
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
    Creature * copyCreatures =creaturesCultures[numberThisCulture]->copyForBehavior();
    qDebug()<<creaturesCultures[numberThisCulture];
    Creature * creature=copyCreatures;
    qDebug()<<creature;
    updateSizeArena();
    int x=rand()%wight;
    int y=rand()%height;
    Cordinate * cordinate= new Cordinate(x,y);
    condithions->typeCreature="default";
    condithions->culture=thisCulture;
    condithions->typeCreature=thisCulture->getNameOfCulture();
    qDebug()<<"add Creature with id: "<<id<< "cordinates x:"<<x<<" y:"<<y;
    createCreature->addNewCreature(creature,cordinate,condithions);
    id++;
    createCreature->setId(id);
}

std::vector<std::pair<std::string,int>> CreaturesGenerator::getCultureCreatures()
{
    std::vector<std::pair<std::string,int>> listCreatures;
    for(int i=0;i<cultures.size();i++)
    {
        listCreatures.push_back(std::pair<std::string,int>(cultures[i]->getNameOfCulture(),i));
    }
    return listCreatures;
}

void CreaturesGenerator::setCultureCreatures(int i)
{
    thisCulture=cultures[i];
    numberThisCulture=i;
}

std::pair<std::string,int> CreaturesGenerator::getSetCultureCreatures()
{
    return std::pair<std::string,int>(thisCulture->getNameOfCulture(),numberThisCulture);
}

void CreaturesGenerator::updateCultures()
{
    cultures=createCreature->getCultures();
    creaturesCultures=createCreature->getCreatures();
}
