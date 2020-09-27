#ifndef HANDLERSTATISTIC_H
#define HANDLERSTATISTIC_H
#include "../MainModel/struct/StatisticData.h"
#include "../MainModel/MainModel.h"
class HandlerStatistic
{
public:
    HandlerStatistic(StatisticData * dataIn,MainModel * modelIn);
    MainModel * model;
    StatisticData * data;
    void update();
};

#endif // HANDLERSTATISTIC_H
