#ifndef FOODGENERATOR_H
#define FOODGENERATOR_H

#include <math.h>
#include <QObject>
#include <vector>
#include "../MainModel/public/CreateFood.h"
#include "../MainModel/entity/Food.h"
#include "../MainModel/entity/struct/Cordinate.h"


class FoodGenerator : public QObject
{
    Q_OBJECT
public:
    explicit FoodGenerator(CreateFood * createFoodIn,QObject *parent = nullptr);
    CreateFood * createFood;
    int wight,height;
    void updateSizeArena();
    int id=0;
    void addFood();
signals:

};

#endif // FOODGENERATOR_H
