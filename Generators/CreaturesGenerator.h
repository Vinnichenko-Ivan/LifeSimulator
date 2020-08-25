
#ifndef CREATURESGENERATOR_H
#define CREATURESGENERATOR_H
#include <math.h>
#include <QObject>
#include <vector>
#include "../MainModel/public/CreateCreature.h"
#include "../MainModel/entity/Creature.h"
#include "../MainModel/entity/struct/Cordinate.h"

class CreaturesGenerator : public QObject

{
    Q_OBJECT
public:
    explicit CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent = nullptr);
    CreateCreature * createCreature;
    int wight,height;
    void updateSizeArena();
signals:
public:
    int id=0;
    void addCreature();
};

#endif
