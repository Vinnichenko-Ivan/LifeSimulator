#ifndef FOODGENERATOR_H
#define FOODGENERATOR_H

#include <math.h>
#include <QObject>
#include <QTimer>
#include <vector>
#include "public/IFoodGenerator.h"
#include "../MainModel/public/CreateFood.h"
#include "../MainModel/entity/Food.h"
#include "../MainModel/entity/struct/Cordinate.h"

class QTimer;
class FoodGenerator : public QObject,
        public IFoodGenerator
{
    Q_OBJECT
public:
    explicit FoodGenerator(CreateFood * createFoodIn,QObject *parent = nullptr);
    CreateFood * createFood;
    QTimer * foodTimer;
    int wight,height;
    void updateSizeArena();
    int id=0;
    int period=0;
    void addFood();
    void start();
    void stop();
    bool pauseFlag=0;
    void pause();
    virtual void setPeriod(int periodIn) override;
signals:

};

#endif // FOODGENERATOR_H
