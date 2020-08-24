#pragma once
#include "entity/public/IOldingCreatures.h"
#include "entity/Creature.h"
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <vector>
#include "entity/Creature.h"
#include "Interface/CreateCreature.h"
#include "../Generators/public/CreateCreature.h"

class QTimer;

class IOldingCreatures;

class MainModel: public QObject,
        public CreateCreature
{
    Q_OBJECT
    virtual void addNewCreature(Creature creature) override
    {
        qDebug()<<"addNewCreature";
        addCreature(creature);
    }
    virtual void addNewCreatures(std::vector<Creature> creatures) override
    {
        qDebug()<<"addNewCreatures";
        for(Creature some:creatures)
        {
            addCreature(some);
        }
    }
private:
    std::vector<Creature> creatures;
    std::vector<IOldingCreatures *> oldingCreaturesInterface;
    QTimer * timer;
    CreateCreature * createCreature;
public:       
    bool onPause=0;
    explicit MainModel(QObject * parent = nullptr);
    void addCreature(Creature newCreature);
    void start();
    void stop();
    void update();
    void oldingCreatures();
public slots:
    void pauseLife();
};
