#pragma once

#include "entity/Creature.h"
#include <QObject>

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
public:
    explicit MainModel(QObject * parent = nullptr);

    virtual void addNewCreature(Creature creature) override;
    virtual void addNewCreatures(std::vector<Creature> creatures) override;

    void pauseLife();
    void addCreature(Creature newCreature);
    void start();
    void stop();
    void update();
    void oldingCreatures();

private:
    std::vector<Creature> creatures;
    std::vector<IOldingCreatures *> oldingCreaturesInterface;
    QTimer * timer;
    CreateCreature * createCreature;    
    bool isPaused=false;

};
