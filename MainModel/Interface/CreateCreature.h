#ifndef CREATECREATURE_H
#define CREATECREATURE_H
#include <vector>
#include "../../MainModel/entity/Creature.h"
class CreateCreature
{
    public:
        virtual void addNewCreature(Creature creature)=0;
        virtual void addNewCreatures(std::vector<Creature> creatures)=0;
};
#endif // CREATECREATURE_H
