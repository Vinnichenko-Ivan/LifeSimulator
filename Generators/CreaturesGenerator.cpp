#include "CreaturesGenerator.h"

CreaturesGenerator::CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent) : QObject(parent)
{
    createCreature=createCreatureIn;
}

void CreaturesGenerator::addCreature()
{
    createCreature->addNewCreature(new Creature(id));
    id++;
}
