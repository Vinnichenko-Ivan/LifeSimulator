#include "CreaturesGenerator.h"

CreaturesGenerator::CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent) : QObject(parent)
{
    createCreature=createCreatureIn;
    std::vector<Creature> creatures;
    Creature creature1;
    creature1.id=1;
    Creature creature2;
    creature2.id=2;
    createCreature->addNewCreature(creature1);
    createCreature->addNewCreature(creature2);
}
