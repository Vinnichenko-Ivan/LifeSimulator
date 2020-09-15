
#ifndef CREATURESGENERATOR_H
#define CREATURESGENERATOR_H
#include <math.h>
#include <QObject>
#include <vector>
#include "../MainModel/struct/Culture.h"
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
    QVector<Culture*>cultures;
    QVector<Creature*>creaturesCultures;
    explicit CreaturesGenerator(CreateCreature * createCreatureIn,QObject *parent = nullptr);
    CreateCreature * createCreature;
    int wight,height;
    int numberThisCulture;
    void updateSizeArena();
    void updateCultures();
    Culture * thisCulture;
    virtual std::vector<std::pair<std::string,int>>getCultureCreatures()override;
    virtual void setCultureCreatures(int i)override;
    virtual std::pair<std::string,int> getSetCultureCreatures()override;
signals:
public:
    int id=0;
    void addCreature();
};

#endif
