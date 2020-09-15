#ifndef BEHAVIOR_H
#define BEHAVIOR_H
#include "../MainModel/entity/Creature.h"
class Behavior
{
public:
    Behavior(Creature* creatureIn);
    virtual Path going();
    virtual bool bite();
    Creature* creature;
};

#endif // BEHAVIOR_H
