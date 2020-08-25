#ifndef FOOD_HPP
#define FOOD_HPP
#include <QDebug>
#include "public/IOldingFood.h"

class Food: public IOldingFood
{
public:
    int id;
    int age=0;
    Food(int idIn)
    {
        id=idIn;
    }
    virtual void update() override
    {
        age++;
        qDebug()<<"my age: "<<age<< " my_id: "<<id;
    }
    virtual bool isDead() const override
    {
        if(age>180)
        {
            return true;
        }
        return false;
    }
};

#endif // FOOD_HPP
