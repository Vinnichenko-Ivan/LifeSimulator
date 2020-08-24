#pragma once
#include <QDebug>
#include "public/IOldingCreatures.h"
#include "struct/Cordinate.h"

class Creature: public IOldingCreatures
{

    public:
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
};

