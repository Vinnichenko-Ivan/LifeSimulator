#pragma once
#include <algorithm>
#include <math.h>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <QVector>
#include "entity/Creature.h"
#include "public/CreateCreature.h"
#include "public/CreateFood.h"
#include "public/ArenaGraphic.h"
#include "entity/struct/Cordinate.h"
#include "entity/struct/Path.h"
#include "entity/public/IOldingFood.h"
#include "entity/public/IOldingCreatures.h"
#include "entity/public/IDoingCreatures.h"
#include "entity/Creature.h"
#include "entity/Food.h"
class QTimer;
class IOldingCreatures;

class MainModel: public QObject,
        public CreateCreature,
        public CreateFood,
        public ArenaGraphic
{
    Q_OBJECT

public:
    explicit MainModel(QObject * parent = nullptr);
    virtual void addNewCreature(Creature * creature,Cordinate * cordinate) override;
    virtual void addNewFood(Food * food, Cordinate * cordinate) override;
    virtual void updateArenaSize(int wightNew,int heightNew) override;
    virtual std::pair<int,int> getSizeArenaForCreatures() override;
    virtual std::pair<int,int> getSizeArenaForFood() override;
    void pause();
    void start();
    void stop();
    void update();
    void oldingCreatures();
    void goingCreatures();
    void recountCordinate();
    void goToNewCordinate(Cordinate * oldCordinate,Path path);
    void killCreatures(int number);
    void killFood(int number);
    QVector<Creature*> creatures;
    QVector<IOldingCreatures *> oldingCreaturesInterface;
    QVector<Cordinate *> cordinatesCreatures;
    QVector<IDoingCreatures *> doings;
    QVector<Food*> foods;
    QVector<IOldingFood *> oldingFoodInterface;
    QVector<Cordinate *> cordinatesFoods;
private: 
    QTimer * timer;
    CreateCreature * createCreature;    
    bool isPaused=false;
    int wight, height;
};
