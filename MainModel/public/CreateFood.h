#ifndef CREATEFOOD_H
#define CREATEFOOD_H
class Food;
class Cordinate;
class CreateFood
{
public:
    virtual void addNewFood(Food * food, Cordinate * cordinate)=0;
    virtual std::pair<int,int> getSizeArenaForFood()=0;
};
#endif // CREATEFOOD_H
