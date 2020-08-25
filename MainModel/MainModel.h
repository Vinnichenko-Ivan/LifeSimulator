#pragma once
#include <algorithm>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <QVector>
#include "entity/Creature.h"
#include "public/CreateCreature.h"
#include "public/ArenaGraphic.h"
#include "../Generators/public/CreateCreature.h"
#include "entity/struct/Cordinate.h"
#include "entity/public/IOldingCreatures.h"
#include "entity/Creature.h"

class QTimer;
class IOldingCreatures;

class MainModel: public QObject,
        public CreateCreature,
        public ArenaGraphic
{
    Q_OBJECT

public:
    explicit MainModel(QObject * parent = nullptr);
    virtual void addNewCreature(Creature * creature,Cordinate * cordinate) override;
    virtual void updateArenaSize(int wightNew,int heightNew) override;
    virtual std::pair<int,int> getSizeArena() override;
    void pause();
    void start();
    void stop();
    void update();
    void oldingCreatures();
    void recountCordinate();
    QVector<Creature*> creatures;
    QVector<IOldingCreatures *> oldingCreaturesInterface;
    QVector<Cordinate *> cordinates;

private: 
    QTimer * timer;
    CreateCreature * createCreature;    
    bool isPaused=false;
    int wight, height;
};
