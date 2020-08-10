#pragma once
#include "public/IOldingCreatures.hpp"
#include "entity/Creature.hpp"
#include <QObject>

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

    explicit MainModel(QObject * parent = nullptr);
    void addCreature(Creature newCreature);
    void start();
    void stop();
    void update();
    void oldingCreatures();


};
