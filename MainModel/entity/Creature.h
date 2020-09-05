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
    int speed=10;
    Creature(Condithions condithionsIn): id(id) {
        condithions=condithionsIn;
        id=condithions.id;
    }
    ~Creature()
    {
    }

    virtual bool bite() override
    {
        return 1;
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
        speed=10;
        if(visionFoods.size()>0)
        {
           int nearFood=0,nearLenght=900;
           for(int i=0;i<visionFoods.size();i++)
           {
               if(nearLenght>visionFoods[i].lenght)
               {
                   nearLenght=visionFoods[i].lenght;
                   nearFood=i;
               }
           }
           if(std::abs(visionFoods[nearFood].angle)>20&&visionFoods[nearFood].lenght<20)
           {
               speed=0;
           }
           angle=visionFoods[nearFood].angle;
        }
        else if(visionCreatures.size()>0)
        {
            int nearCreature=0,nearLenght=900;
            for(int i=0;i<visionCreatures.size();i++)
            {
                if(nearLenght>visionCreatures[i].lenght)
                {
                    nearLenght=visionCreatures[i].lenght;
                    nearCreature=i;
                }
            }
            if(std::abs(visionCreatures[nearCreature].angle)>20&&visionCreatures[nearCreature].lenght<20)
            {
                speed=0;
            }
            angle=visionCreatures[nearCreature].angle;
        }
        else
        {
            angle=(angle+1)%360;
        }
        return Path(speed,angle);
    }


};

