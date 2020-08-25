#ifndef CREATECREATURE_H
#define CREATECREATURE_H

class Creature;
class Cordinate;
class CreateCreature
{
public:
    virtual void addNewCreature(Creature * creature, Cordinate * cordinate)=0;
    virtual std::pair<int,int> getSizeArena()=0;
};
#endif // CREATECREATURE_H
