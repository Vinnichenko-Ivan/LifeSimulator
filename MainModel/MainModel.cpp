#include "MainModel.h"
#define PI 3.14159265
void MainModel::addNewCreature(Creature * creature,Cordinate * cordinate)
{
    creatures.push_back(creature);
    oldingCreaturesInterface.push_back(creature);
    doings.push_back(creature);
    cordinatesCreatures.push_back(cordinate);
}

void MainModel::addNewFood(Food * food, Cordinate * cordinate)
{
    foods.push_back(food);
    oldingFoodInterface.push_back(food);
    cordinatesFoods.push_back(cordinate);
}
void MainModel::updateArenaSize(int wightNew,int heightNew)
{
    wight=wightNew;
    height=heightNew;
    recountCordinate();
}

std::pair<int,int> MainModel::getSizeArenaForCreatures()
{
   return std::pair<int,int>(wight,height);
}

std::pair<int,int> MainModel::getSizeArenaForFood()
{
   return std::pair<int,int>(wight,height);
}

MainModel::MainModel( QObject *parent): QObject(parent){
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainModel::update);
    start();
}


void MainModel::start() {
    timer->start(1000 / 24);
}

void MainModel::stop() {
    timer->stop();
}

void MainModel::oldingCreatures()
{
    if(isPaused)
    {

    }
    else
    {
        for(int i=0;i<oldingCreaturesInterface.size();i++)
        {
            if(oldingCreaturesInterface[i]->isDead())
            {
                killCreatures(i);
            }
        }
        for(auto * n : oldingCreaturesInterface)
        {
            n->update();
        }
    }
}

void MainModel::goingCreatures()
{
    if(isPaused)
    {

    }
    else
    {
        for(int i=0;i< doings.size();i++)
        {
            Path path =doings[i]->going();
            goToNewCordinate(cordinatesCreatures[i],path);
        }
    }
}

void MainModel::update()
{
    oldingCreatures();
    goingCreatures();
}

void  MainModel::pause()
{
    isPaused = !isPaused;
}

void MainModel::recountCordinate()
{
    for(auto*n:cordinatesCreatures)
    {
        n->x=std::min(n->x,(double)wight-5);
        n->y=std::min(n->y,(double)height-5);
        n->x=std::max(n->x,(double)-5);
        n->y=std::max(n->y,(double)-5);
    }
}
void MainModel::goToNewCordinate(Cordinate * oldCordinate,Path path)
{
    oldCordinate->x+=std::sin( (double)path.angle * PI / (double)180)*path.path;
    oldCordinate->y+=std::cos( (double)path.angle * PI / (double)180)*path.path;
}
void MainModel::killCreatures(int number)
{
    creatures.erase(creatures.begin()+number);
    oldingCreaturesInterface.erase(oldingCreaturesInterface.begin()+number);
    doings.erase(doings.begin()+number);
    cordinatesCreatures.erase(cordinatesCreatures.begin()+number);
}

void MainModel::killFood(int number)
{
    foods.erase(foods.begin()+number);
    oldingFoodInterface.erase(oldingFoodInterface.begin()+number);
    cordinatesFoods.erase(cordinatesFoods.begin()+number);
}
