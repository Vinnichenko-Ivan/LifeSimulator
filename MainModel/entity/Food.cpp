#include "Food.h"

#include <QDebug>

Food::Food(int idIn)
{
    id=idIn;
}

void Food::update()
{
    age++;
    qDebug()<<"my age: "<<age<< " my_id: "<<id;
}

bool Food::isDead() const
{
    if(age>180)
    {
        return true;
    }
    return false;
}
