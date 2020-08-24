#include "CreaturesGenerator.h"

CreaturesGenerator::CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent) : QObject(parent)
{
    createCreature=createCreatureIn;
    std::vector<Creature> creatures;

    createCreature->addNewCreature(new Creature(1));
    createCreature->addNewCreature(new Creature(2));
}
