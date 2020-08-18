
#pragma once
#include <QDebug>
#include <IOldingCreatures>
class Creature:public IOldingCreatures
{

    public:
        long long int age=0;
        virtual void update() override
        {
            age++;
            qDebug()<<"my age ";
            qDebug()<<age;
        }
        virtual bool is_dead()const override
        {
            return false;
        }
};

