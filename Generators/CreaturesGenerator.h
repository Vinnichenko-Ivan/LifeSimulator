
#ifndef CREATURESGENERATOR_H
#define CREATURESGENERATOR_H

#include <QObject>
#include <vector>
#include "../MainModel/Interface/CreateCreature.h"
#include "../MainModel/entity/Creature.h"
#include "public/CreateCreature.h"

class CreaturesGenerator : public QObject
       // public CreateCreature
{
    Q_OBJECT
public:
    explicit CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent = nullptr);
    CreateCreature * createCreature;
signals:
public:
    int id=0;
    void addCreature();
};

#endif
