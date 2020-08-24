//#ifndef CREATURESGENERATOR_H
//#define CREATURESGENERATOR_H

//#include <QObject>
//#include "../MainModel/entity/Creature.h"
//#include "public/CreateCreature.h"

//class CreaturesGenerator : public QObject,
//        public CreateCreature
//{
//    Q_OBJECT
//public:
//    explicit CreaturesGenerator(QObject *parent = nullptr);

//signals:
//public:
//    virtual Creature createRandomCreature() override
//    {
//        Creature creature;
//        return creature;
//    }
//    virtual Creature createEmpertyCreature() override
//    {
//        Creature creature;
//        return creature;
//    }
//    virtual Creature createSettingCreature() override
//    {
//        Creature creature;
//        return creature;
//    }
//    virtual bool updateCreate() override
//    {
//        return 1;
//    }
//};

//#endif

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
//    virtual Creature createRandomCreature() override
//    {
//        Creature creature;
//        return creature;
//    }
//    virtual Creature createEmpertyCreature() override
//    {
//        Creature creature;
//        return creature;
//    }
//    virtual Creature createSettingCreature() override
//    {
//        Creature creature;
//        return creature;
//    }
//    virtual bool updateCreate() override
//    {
//        return 1;
//    }
};

#endif
