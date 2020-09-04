#ifndef CONDITHIONS_H
#define CONDITHIONS_H
#include<QDebug>
struct Condithions
{
    Condithions(int id): id(id){}
    int hp=100;
    int energy=500;
    int visionLenght=100;
    int id;
    int maxHp=100;
    int maxEnergy=1000;
    int damage=1;
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
        qDebug()<<"my age: "<<age<< " my_id: "<<id<<"my energy: "<<energy<<"my Hp: "<<hp;
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
};
#endif // CONDITHIONS_H
