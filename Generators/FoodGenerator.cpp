#include "FoodGenerator.h"
#include <QDebug>

FoodGenerator::FoodGenerator(CreateFood * createFoodIn,QObject *parent) : QObject(parent)
{
    foodTimer = new QTimer();
    createFood=createFoodIn;
    connect(foodTimer, &QTimer::timeout, this, &FoodGenerator::addFood);
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

void FoodGenerator::setPeriod(int periodIn)
{
    period=periodIn;
    start();
}

void FoodGenerator::start()
{
    if(pauseFlag==false&&period != 0)
    {
       foodTimer->start(1000/period);
    }
    else
    {
        foodTimer->stop();
    }
}
void FoodGenerator::stop()
{
    foodTimer->stop();
}
void FoodGenerator::pause()
{
    pauseFlag=!pauseFlag;
    if(pauseFlag)
    {
       stop();
    }
    else
    {
        start();
    }
}
