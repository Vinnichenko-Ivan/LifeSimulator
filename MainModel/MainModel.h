#pragma once

#include "entity/Creature.h"
#include <QObject>

#include <QVector>
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

    virtual void addNewCreature(Creature * creature) override;

    void pause();
    void start();
    void stop();
    void update();
    void oldingCreatures();

private:
    QVector<Creature*> creatures;
    QVector<IOldingCreatures *> oldingCreaturesInterface;
    QTimer * timer;
    CreateCreature * createCreature;    
    bool isPaused=false;

};
