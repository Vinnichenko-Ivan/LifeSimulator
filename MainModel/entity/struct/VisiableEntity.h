#ifndef VISIABLEENTITY_H
#define VISIABLEENTITY_H
#include <string>
struct VisiableEntity
{
    VisiableEntity(double lenghtIn,double angleIn,std::string typeIn,std::string typeCreatureIn="")
    {
        type=typeIn;
        typeCreature=typeCreatureIn;
        angle=angleIn;
        lenght=lenghtIn;
    }
    std::string type;
    std::string typeCreature;
    double angle;
    double lenght;
};
#endif // VISIABLEENTITY_H
