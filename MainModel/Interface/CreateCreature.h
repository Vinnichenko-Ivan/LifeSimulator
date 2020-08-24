#ifndef CREATECREATURE_H
#define CREATECREATURE_H

class Creature;

class CreateCreature
{
public:
    virtual void addNewCreature(Creature * creature)=0;
};
#endif // CREATECREATURE_H
