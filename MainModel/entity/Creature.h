#pragma once
#include <QDebug>
#include "public/IOldingCreatures.h"
#include "public/IDoingCreatures.h"
#include "struct/Cordinate.h"
#include "struct/Path.h"
class Creature: public IOldingCreatures,
        public IDoingCreatures
{
public:
    Creature(int id): id(id) {}
    int angle=0;
    int id;
    Cordinate cordinate;
    long long int age=0;
    virtual void update() override
    {
        age++;
        qDebug()<<"my age: "<<age<< " my_id: "<<id;
    }
    virtual bool is_dead() const override
    {
        return false;
    }

    virtual Path going() override
    {
        qDebug()<<"i Go "<<1<<"my angle:"<<angle << " my_id: "<<id;
        angle=(angle+5)%360;
        return Path(1,angle);
    }
};

