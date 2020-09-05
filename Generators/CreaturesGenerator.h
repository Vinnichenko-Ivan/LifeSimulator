
#ifndef CREATURESGENERATOR_H
#define CREATURESGENERATOR_H
#include <math.h>
#include <QObject>
#include <vector>
#include "../MainModel/public/CreateCreature.h"
#include "../MainModel/entity/Creature.h"
#include "../MainModel/entity/struct/Cordinate.h"
#include "../MainModel/entity/struct/Condithions.h"
#include "public/ICreatureGenerator.h"

class CreaturesGenerator : public QObject,
        public ICreatureGenerator

{
    Q_OBJECT
public:
    explicit CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent = nullptr);
    CreateCreature * createCreature;
    int wight,height;
    void updateSizeArena();
    std::vector<std::string> cultureCreatures;
    std::string thisCulture="default";
    virtual std::vector<std::string>getCultureCreatures()override;
    virtual void setCultureCreatures(std::string in)override;
    virtual std::string getSetCultureCreatures()override;
signals:
public:
    int id=0;
    void addCreature();
};

#endif
