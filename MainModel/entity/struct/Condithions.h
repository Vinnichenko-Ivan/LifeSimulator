#ifndef CONDITHIONS_H
#define CONDITHIONS_H
struct Condithions
{
    Condithions(int id): id(id){}
    int xp=100;
    int energy=1000;
    int visionLenght=150;
    int id;
    long long int age=0;
    void update()
    {
        age++;
        energy--;
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
