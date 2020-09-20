#ifndef AFRAIDCREATURES_H
#define AFRAIDCREATURES_H
#include "../../MainModel/entity/Creature.h"
#include <math.h>
class AfraidCreatures:  public Creature
{
public:

    AfraidCreatures(Condithions condithionsIn):Creature(condithionsIn)
    {
    }

    virtual Creature* copyForBehavior()override
    {
        return new AfraidCreatures(condithions);
    }

    virtual Path going() override
    {
        speed=10;
        bool enemyNear=0;
        int enemyNumber=0;
        int nearEnemy=900;
        for(int i=0;i<visionCreatures.size();i++)
        {
            if(nearEnemy>visionCreatures[i].lenght&&visionCreatures[i].typeCreature!=condithions.typeCreature)
            {
                enemyNear=1;
                nearEnemy=visionCreatures[i].lenght;
                enemyNumber=i;
            }
        }
        if(enemyNear)
        {
            angle= (int)(-visionCreatures[enemyNumber].angle);
            if(std::abs(visionCreatures[enemyNumber].angle<180))
            {
                speed=10;
            }
        }
        else if(visionFoods.size()>0)
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

#endif // AFRAIDCREATURES_H
