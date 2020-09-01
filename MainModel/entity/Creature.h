#pragma once
#include <QDebug>
#include <QVector>
#include<vector>
#include "public/IOldingCreatures.h"
#include "public/IDoingCreatures.h"
#include "public/IVisionCreatures.h"
#include "struct/Path.h"
#include "struct/Condithions.h"
#include "struct/VisiableEntity.h"
class Condithions;
class Creature: public IOldingCreatures,
        public IDoingCreatures,
        public IVisionCreatures
{
public:
    Condithions condithions = Condithions(0);
    std::vector<VisiableEntity> visionCreatures;
    std::vector<VisiableEntity> visionFoods;
    int id;
    int angle=0;
    Creature(Condithions condithionsIn): id(id) {
        condithions=condithionsIn;
        id=condithions.id;
    }
    ~Creature()
    {
    }

    virtual void visionCreaturesUpdate(std::vector<VisiableEntity>visionCreaturesIn) override
    {
        visionCreatures=visionCreaturesIn;
    }

    virtual void visionFoodsUpdate(std::vector<VisiableEntity>visionFoodsIn)override
    {
        visionFoods=visionFoodsIn;
    }

    virtual void update(Condithions condithionsIn) override
    {
        condithions=condithionsIn;
    }

    virtual Path going() override
    {

        if(visionCreatures.size()>0)
        {
            angle+=visionCreatures[0].angle;
        }
        else
        {
            angle=(angle+5)%360;
        }
        return Path(1,angle);
    }
};

