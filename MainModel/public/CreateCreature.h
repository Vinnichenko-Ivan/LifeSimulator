#ifndef CREATECREATURE_H
#define CREATECREATURE_H

class Creature;
class Cordinate;
class Condithions;
class CreateCreature
{
public:
    virtual void addNewCreature(Creature * creature, Cordinate * cordinate, Condithions* condithions)=0;
    virtual std::pair<int,int> getSizeArenaForCreatures()=0;
};
#endif // CREATECREATURE_H
