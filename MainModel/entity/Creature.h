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
    std::vector<VisiableEntity> vision;
    int id;
    int angle=0;
    Creature(Condithions condithionsIn): id(id) {
        condithions=condithionsIn;
        id=condithions.id;
    }
    ~Creature()
    {
    }
    virtual void visionUpdate(std::vector<VisiableEntity>visionIn) override
    {
        vision=visionIn;
    }
    virtual void update(Condithions condithionsIn) override
    {
        condithions=condithionsIn;
    }

    virtual Path going() override
    {
        angle=(angle+5)%360;
        return Path(1,angle);
    }
};

