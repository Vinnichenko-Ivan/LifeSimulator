#ifndef CREATECREATURE_H
#define CREATECREATURE_H
#include "../../MainModel/entity/Creature.h"
class CreateCreature
{
    public:
        virtual Creature createRandomCreature()=0;
        virtual Creature createEmpertyCreature()=0;
        virtual Creature createSettingCreature()=0;
        virtual bool updateCreate()=0;
};
#endif // CREATECREATURE_H
