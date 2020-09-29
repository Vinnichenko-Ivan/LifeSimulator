#ifndef MAINMODEL_H
#define MAINMODEL_H
#include <algorithm>
#include <math.h>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <QVector>
#include "struct/StatisticData.h"
#include "public/CreateCreature.h"
#include "public/CreateFood.h"
#include "public/ArenaGraphic.h"
#include "public/SettingsGraphic.h"
#include "entity/struct/Cordinate.h"
#include "entity/struct/Path.h"
#include "entity/struct/Condithions.h"
#include "entity/public/IOldingFood.h"
#include "entity/public/IOldingCreatures.h"
#include "entity/public/IDoingCreatures.h"
#include "entity/public/IVisionCreatures.h"
#include "entity/Creature.h"
#include "entity/Food.h"
#include "struct/Culture.h"
#include "../Behavior/CreturesExample/AggressiveCreature.h"
#include "../Behavior/CreturesExample/AfraidCreatures.h"
class QTimer;
class IOldingCreatures;

class MainModel: public QObject,
        public CreateCreature,
        public CreateFood,
        public ArenaGraphic,
        public SettingsGraphic
{
    Q_OBJECT

public:
    explicit MainModel(QObject * parent = nullptr);
    virtual void addNewCreature(Creature * creature,Cordinate * cordinate,Condithions* condithions) override;
    virtual void addNewFood(Food * food, Cordinate * cordinate) override;
    virtual void updateArenaSize(int wightNew,int heightNew) override;
    virtual std::pair<int,int> getSizeArenaForCreatures() override;
    virtual std::pair<int,int> getSizeArenaForFood() override;
    virtual void setId(int i)override;
    virtual int getId()override;
    virtual void setLimitCreatures(bool i)override;
    virtual void setLimitFood(bool i)override;
    virtual void setCountLimitCreatures(int i)override;
    virtual void setCountLimitFood(int i)override;
    virtual void stopReproductIfMax(bool i)override;
    virtual QVector<Culture*> getCultures()override;
    virtual QVector<Creature*> getCreatures()override;
    ~MainModel();
    void pause();
    void start();
    void stop();
    void update();
    void oldingCreatures();
    void goingCreatures();
    void visionCreaturesToCreatures();
    void visionFoodsToCreatures();
    void recountCordinate();
    void recountFoodCordinate();
    void goToNewCordinate(Cordinate * oldCordinate,Condithions* cond,Path path);
    void feedingCreatures();
    void killCreatures(int number);
    void killFood(int number);
    void cellDivision(int number);
    void statistic();
    double getAngleToCord(Cordinate* myCord, Cordinate* targetCord);
    double getLenghtToCord(Cordinate* myCord, Cordinate* targetCord);
    
    QVector<Creature*> creatures;
    QVector<IOldingCreatures *> oldingCreaturesInterface;
    QVector<IVisionCreatures *> iVisionCreatures;
    QVector<Cordinate *> cordinatesCreatures;
    QVector<IDoingCreatures *> doings;
    QVector<Food*> foods;
    QVector<IOldingFood *> oldingFoodInterface;
    QVector<Cordinate *> cordinatesFoods;
    QVector<Condithions*> condithionsCreature;
    StatisticData * statisticData;
    QVector<Culture*> cultures;
    QVector<Creature*> culturesCreatures;
signals:
    void updateStatisticInHandler();
private: 
    QTimer * timer;
    CreateCreature * createCreature;    
    bool isPaused=false;
    int wight, height;
    int id=0;
    int energyByKillCreature=250;
    int maxCountCreatures;
    int maxCountFood;
    bool limitationCreatures=0;
    bool limitationFood=0;
    bool killLimitOldCreatures=1;
    bool reproductIfMax=0;
};
#endif
