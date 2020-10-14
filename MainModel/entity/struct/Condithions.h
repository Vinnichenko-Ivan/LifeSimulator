#ifndef CONDITHIONS_H
#define CONDITHIONS_H
#include<QDebug>
#include<QColor>
#include<QString>
#include <string>
#include "../../struct/Culture.h"
#include "../../../FileSystemUtilits/Serialise.h"
#include "../../../FileSystemUtilits/Deserialise.h"
struct Condithions: public Serialise,
        public Deserialise

{
    Culture *culture;
    Condithions(int id=0, Culture *cultureIn=nullptr): id(id)
    {
        culture=cultureIn;
    }
    std::string typeCreature="-";
    int hp=100;
    int energy=500;
    int visionLenght=100;
    int id;
    int maxHp=100;
    int maxEnergy=1000;
    int damage=10;
    int energyToHp=10;
    double maxLenght=3;
    double maxAngleD=10;
    long long int age=0;
    void update()
    {
        age++;
        energy--;
        if(hp>maxHp)
        {
            hp=maxHp;
        }
        if(energy>maxEnergy)
        {
            energy=maxEnergy;
        }
        if(energy<0)
        {
            energy=0;
            hp--;
        }
        if(hp!=maxHp&&energy>=maxEnergy/2+energyToHp)
        {
            energy-=energyToHp;
            hp++;
        }
        qDebug()<<"my age: "<<age<< " my_id: "<<id<<"my energy: "<<energy<<"my Hp: "<<hp<<"myCulture: "<<QString::fromStdString(  typeCreature);
    }
    bool isDead()
    {
        if(hp<1)
        {
            qDebug()<<"my age: "<<age<< " my_id: "<<id<<"and i... i all.";
            return true;
        }
        return false;
    }

    virtual QJsonObject serialise() override
    {
        QJsonObject  obj = QJsonObject();
        obj.insert("type","condithions");
        obj.insert("typeCreature",QString::fromStdString(typeCreature));
        obj.insert("cultures",QString::fromStdString(culture->getNameOfCulture()));
        obj.insert("hp",hp);
        obj.insert("energy",energy);
        obj.insert("visionLenght",visionLenght);
        obj.insert("id",id);
        obj.insert("maxHp",maxHp);
        obj.insert("maxEnergy",maxEnergy);
        obj.insert("damage",damage);
        obj.insert("energyToHp",energyToHp);
        obj.insert("maxLenght",maxLenght);
        obj.insert("maxAngleD",maxAngleD);
        obj.insert("age",age);
        return obj;
    }

    virtual bool desirialise (QJsonObject & document) override
    {
        if(document.take("type").toString().toStdString()!="condithions")
        {
            qDebug()<<"NOT CONDITHION";
            return 0;
        }
        typeCreature = document.take("typeCreature").toString().toStdString();
        hp = document.take("hp").toInt();
        energy = document.take("energy").toInt();
        visionLenght = document.take("visionLenght").toInt();
        id = document.take("id").toInt();
        maxHp = document.take("maxHp").toInt();
        maxEnergy = document.take("maxEnergy").toInt();
        damage = document.take("damage").toInt();
        energyToHp = document.take("energyToHp").toInt();
        maxLenght = document.take("maxLenght").toDouble();
        maxAngleD = document.take("maxAngleD").toDouble();
        age = document.take("age").toInt();
        return 1;
    }
};
#endif // CONDITHIONS_H
