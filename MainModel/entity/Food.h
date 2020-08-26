#ifndef FOOD_HPP
#define FOOD_HPP

#include "public/IOldingFood.h"

class Food: public IOldingFood
{
public:
    int id;
    int age=0;
    Food(int idIn);
    virtual void update() override;
    virtual bool isDead() const override;
};

#endif // FOOD_HPP
