#ifndef CONDITHIONS_H
#define CONDITHIONS_H
#include<QDebug>
struct Condithions
{
    Condithions(int id): id(id){}
    int xp=100;
    int energy=500;
    int visionLenght=150;
    int id;
    int maxXp=100;
    int maxEnergy=1000;
    int damage=1;
    long long int age=0;
    void update()
    {
        age++;
        energy--;
        if(xp>maxXp)
        {
            xp=maxXp;
        }
        if(energy>maxEnergy)
        {
            energy=maxEnergy;
        }
        if(energy<0)
        {
            energy=0;
            xp--;
        }
        qDebug()<<"my age: "<<age<< " my_id: "<<id<<"my energy: "<<energy<<"my xp: "<<xp;
    }
    bool isDead()
    {
        if(xp<1)
        {
            qDebug()<<"my age: "<<age<< " my_id: "<<id<<"and i... i all.";
            return true;
        }
        return false;
    }
};
#endif // CONDITHIONS_H
