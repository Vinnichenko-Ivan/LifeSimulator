#pragma once
#include "entity/public/IOldingCreatures.h"
#include "entity/Creature.h"
#include <QObject>
#include <QTimer>
#include <QDebug>
#include "entity/Creature.h"
#include "../Generators/CreaturesGenerator.h"

class QTimer;

class IOldingCreatures;

class MainModel: public QObject
{
    Q_OBJECT

private:
    std::vector<Creature> creatures;
    std::vector<IOldingCreatures *> oldingCreaturesInterface;
    QTimer * timer;

public:       
    CreaturesGenerator creatureGenerator;
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
