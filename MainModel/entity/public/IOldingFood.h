#ifndef IOLDINGFOOD_H
#define IOLDINGFOOD_H

class IOldingFood
{
public:
    virtual void update()=0;
    virtual bool isDead() const=0;
    virtual ~IOldingFood(){}
};

#endif // IOLDINGFOOD_H
