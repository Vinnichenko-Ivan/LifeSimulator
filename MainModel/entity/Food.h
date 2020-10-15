#ifndef FOOD_HPP
#define FOOD_HPP

#include "public/IOldingFood.h"
#include "../../FileSystemUtilits/Serialise.h"
#include "../../FileSystemUtilits/Deserialise.h"

class Food: public IOldingFood,
        public Serialise,
        public Deserialise

{
public:
    int id;
    int energy=100;
    int age=0;
    Food(int idIn);
    virtual void update() override;
    virtual bool isDead() const override;

    virtual QJsonObject serialise() override
    {
        QJsonObject  obj = QJsonObject();
        obj.insert("type","food");
        obj.insert("age",age);
        obj.insert("energy",energy);
        return obj;
    }

    virtual bool desirialise (QJsonObject & document) override
    {
        if(document.take("type").toString().toStdString()!="food")
        {
            qDebug()<<"NOT Food";
            return 0;
        }
        age=document.take("age").toInt();
        energy=document.take("energy").toInt();
        return 1;
    }
};

#endif // FOOD_HPP
