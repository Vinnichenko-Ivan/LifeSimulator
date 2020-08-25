#include "FoodGenerator.h"


FoodGenerator::FoodGenerator(CreateFood * createFoodIn,QObject *parent) : QObject(parent)
{
    createFood=createFoodIn;
}

void FoodGenerator::updateSizeArena()
{
    std::pair<int,int> size = createFood->getSizeArenaForFood();
    wight=size.first;
    height=size.second;
}

void FoodGenerator::addFood()
{
    Food * food=new Food(id);
    updateSizeArena();
    int x=rand()%wight;
    int y=rand()%height;
    Cordinate * cordinate= new Cordinate(x,y);
    qDebug()<<"add Food with id: "<<id<< "cordinates x:"<<x<<" y:"<<y;
    createFood->addNewFood(food,cordinate);
    id++;
}
