#include "MainModel.h"
#define PI 3.14159265
MainModel::~MainModel()
{
    for (auto n:creatures)
    {
        delete n;
    }
    for (auto n:foods)
    {
        delete n;
    }
    for (auto n:cordinatesCreatures)
    {
        delete n;
    }
    for (auto n:cordinatesFoods)
    {
        delete n;
    }
}
void MainModel::addNewCreature(Creature * creature,Cordinate * cordinate,Condithions* condithions)
{
    if(creatures.size()<maxCountCreatures||limitationCreatures==0||reproductIfMax)
    {
        statisticData->countCreateCreatures++;
        creatures.push_back(creature);
        oldingCreaturesInterface.push_back(creature);
        doings.push_back(creature);
        iVisionCreatures.push_back(creature);
        cordinatesCreatures.push_back(cordinate);
        condithionsCreature.push_back(condithions);
    }
}

void MainModel::addNewFood(Food * food, Cordinate * cordinate)
{
    if(foods.size()<maxCountFood||limitationFood==0)
    {
        foods.push_back(food);
        oldingFoodInterface.push_back(food);
        cordinatesFoods.push_back(cordinate);
    }
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
    cultures.push_back(new Culture(QColor(255,0,0),"default"));
    cultures.push_back(new Culture(QColor(0,255,0),"default1"));
    cultures.push_back(new Culture(QColor(0,0,255),"default2"));
    statisticData=new StatisticData;
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
        long long int allAges=0;
        for(auto * n : condithionsCreature)
        {
            n->update();
            allAges+=n->age;
        }
        for(int i=0;i<condithionsCreature.size();i++)
        {
            if(condithionsCreature[i]->isDead())
            {
                killCreatures(i);
            }
        }

        for(int i=0;i<creatures.size();i++)
        {
            creatures[i]->update(*condithionsCreature[i]);
            cellDivision(i);
        }
        if(creatures.size()>0)
        {
            statisticData->averageAge=allAges/condithionsCreature.size();
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
            goToNewCordinate(cordinatesCreatures[i],condithionsCreature[i],path);
        }
    }
}

void MainModel::feedingCreatures()
{
    if(isPaused)
    {

    }
    else
    {
        for(int i=0;i< doings.size();i++)
        {
            bool bite=doings[i]->bite();
            if(bite)
            {
                for(int j=0;j<cordinatesFoods.size();j++)
                {
                    if(std::abs(getAngleToCord(cordinatesCreatures[i],cordinatesFoods[j]))<63)
                    {

                        if(getLenghtToCord(cordinatesCreatures[i],cordinatesFoods[j])<7)
                        {
                            condithionsCreature[i]->energy+=foods[j]->energy;
                            killFood(j);
                        }
                    }
                }
            }
            if(bite)
            {
                for(int j=0;j<cordinatesCreatures.size();j++)
                {
                    if(std::abs(getAngleToCord(cordinatesCreatures[i],cordinatesCreatures[j]))<63&&i!=j)
                    {

                        if(getLenghtToCord(cordinatesCreatures[i],cordinatesCreatures[j])<10)
                        {
                            condithionsCreature[j]->hp-=condithionsCreature[i]->damage;
                            if(condithionsCreature[j]->hp<1)
                            {
                                condithionsCreature[i]->energy+=condithionsCreature[j]->energy*0.8;
                                condithionsCreature[j]->energy=0;
                            }
                        }
                    }
                }
            }
        }
    }
}

void MainModel::update()
{
    recountFoodCordinate();
    oldingCreatures();
    visionCreaturesToCreatures();
    visionFoodsToCreatures();
    goingCreatures(); //return (degree+540-currentAzimut)%360-180;
    feedingCreatures();
    statistic();
    if(limitationCreatures)
    {
        if(creatures.size()>maxCountCreatures)
        {
            if(killLimitOldCreatures)
            {
                for(int i = creatures.size()-maxCountCreatures;i>0;i--)
                {
                    killCreatures(0);
                }
            }
        }
    }

    if(limitationFood)
    {
        while(maxCountFood< foods.size())
        {
            killFood(foods.size()-1);
        }
    }

}

void  MainModel::pause()
{
    isPaused = !isPaused;
}

void MainModel::recountCordinate()
{
    for(auto*n:cordinatesCreatures)
    {
        n->x=std::min(n->x,(double)wight);
        n->y=std::min(n->y,(double)height);
        n->x=std::max(n->x,(double)0);
        n->y=std::max(n->y,(double)0);
    }
}
void MainModel::recountFoodCordinate()
{
    for(auto*n:cordinatesFoods)
    {
        n->x=std::min(n->x,(double)wight);
        n->y=std::min(n->y,(double)height);
        n->x=std::max(n->x,(double)0);
        n->y=std::max(n->y,(double)0);
    }
}

void MainModel::goToNewCordinate(Cordinate * oldCordinate,Condithions* cond,Path path)
{
    if(path.path>cond->maxLenght)
    {
      path.path=cond->maxLenght;
    }
    if(path.path<-cond->maxLenght)
    {
      path.path=-cond->maxLenght;
    }
    if(path.angle>cond->maxAngleD)
    {
       path.angle=cond->maxAngleD;
    }
    if(path.angle<-cond->maxAngleD)
    {
       path.angle=-cond->maxAngleD;
    }
    oldCordinate->angle= int(oldCordinate->angle+path.angle+360)%360;
    oldCordinate->x+=std::sin( (double)oldCordinate->angle * PI / (double)180)*path.path;
    oldCordinate->y-=std::cos( (double)oldCordinate->angle * PI / (double)180)*path.path;

}

double MainModel::getAngleToCord(Cordinate* myCord, Cordinate* targetCord)
{
    int degreeOntarget=((int)((int)-1*(std::atan2((targetCord->x-myCord->x),(targetCord->y-myCord->y))/PI*180)+180)%360);
    return -((int)(myCord->angle+540-degreeOntarget)%360-180)%180;
}

double MainModel::getLenghtToCord(Cordinate* myCord, Cordinate* targetCord)
{
    return sqrt((myCord->x-targetCord->x)*(myCord->x-targetCord->x)+(myCord->y-targetCord->y)*(myCord->y-targetCord->y));
}

void MainModel::killCreatures(int number)
{
    delete creatures[number];
    delete condithionsCreature[number];
    delete cordinatesCreatures[number]; 
    iVisionCreatures.erase(iVisionCreatures.begin()+number);
    creatures.erase(creatures.begin()+number);
    oldingCreaturesInterface.erase(oldingCreaturesInterface.begin()+number);
    doings.erase(doings.begin()+number);
    cordinatesCreatures.erase(cordinatesCreatures.begin()+number);
    condithionsCreature.erase(condithionsCreature.begin()+number);
}

void MainModel::killFood(int number)
{
    delete foods[number];
    delete cordinatesFoods[number];
    foods.erase(foods.begin()+number);
    oldingFoodInterface.erase(oldingFoodInterface.begin()+number);
    cordinatesFoods.erase(cordinatesFoods.begin()+number);
}

void MainModel::visionCreaturesToCreatures()
{
    int lenght,angle;
    for(int i=0;i< iVisionCreatures.size();i++)
    {
        std::vector<VisiableEntity> vision;
        for(int j=0;j<cordinatesCreatures.size();j++)
        {
            if(j!=i)
            {
                lenght=getLenghtToCord(cordinatesCreatures[i],cordinatesCreatures[j]);
                if(lenght<=condithionsCreature[i]->visionLenght)
                {
                    angle=getAngleToCord(cordinatesCreatures[i],cordinatesCreatures[j]);
                    VisiableEntity iSeeEntity(lenght,angle,"creature");
                    iSeeEntity.typeCreature=condithionsCreature[j]->typeCreature;
                    vision.push_back(iSeeEntity);
                }
            }
        }
        iVisionCreatures[i]->visionCreaturesUpdate(vision);
    }
}

void MainModel::visionFoodsToCreatures()
{
    int lenght,angle;
    for(int i=0;i< iVisionCreatures.size();i++)
    {
        std::vector<VisiableEntity> vision;
        for(int j=0;j<cordinatesFoods.size();j++)
        {
            lenght=getLenghtToCord(cordinatesCreatures[i],cordinatesFoods[j]);
            if(lenght<=condithionsCreature[i]->visionLenght)
            {
                angle=getAngleToCord(cordinatesCreatures[i],cordinatesFoods[j]);
                VisiableEntity iSeeEntity(lenght,angle,"foods");
                vision.push_back(iSeeEntity);
            }
        }
        iVisionCreatures[i]->visionFoodsUpdate(vision);
    }
}

void MainModel::cellDivision(int number)
{
    if(creatures.size()<maxCountCreatures||limitationCreatures==0||reproductIfMax)
    {
        if(condithionsCreature[number]->energy>condithionsCreature[number]->maxEnergy*0.8&&condithionsCreature[number]->hp>15)
        {
            Condithions * condithion = new Condithions(id);
            Creature * creature = new Creature(*condithion);
            Cordinate * cordinate = new Cordinate(cordinatesCreatures[number]->x+rand()%10-5,cordinatesCreatures[number]->y+rand()%10-5);
            cordinate->angle=rand()%365;
            condithion->energy=condithionsCreature[number]->energy/2;
            condithionsCreature[number]->energy/=2;
            condithion->typeCreature=condithionsCreature[number]->typeCreature;
            condithion->culture=condithionsCreature[number]->culture;
            addNewCreature(creature,cordinate,condithion);
            id++;
        }
    }
}

void MainModel::setId(int i)
{
    id=i;
}

int MainModel::getId()
{
    return id;
}

void MainModel::setLimitCreatures(bool i)
{
    limitationCreatures=i;
}

void MainModel::setLimitFood(bool i)
{
    limitationFood=i;
}

void MainModel::setCountLimitCreatures(int i)
{
    maxCountCreatures=i;
}

void MainModel::setCountLimitFood(int i)
{
    maxCountFood=i;
}

void MainModel::stopReproductIfMax(bool i)
{
    reproductIfMax=i;
}

void MainModel::statistic()
{
    statisticData->countLivesCreatures=creatures.size();
    statisticData->countLivesFood=foods.size();
    statisticData->maxCountLivesCreatures=std::max(statisticData->maxCountLivesCreatures,statisticData->countLivesCreatures);
    statisticData->maxCountLivesFood=std::max(statisticData->maxCountLivesFood,statisticData->countLivesFood);
}

QVector<Culture*> MainModel::getCultures()
{
    return cultures;
}
