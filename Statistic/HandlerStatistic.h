#ifndef HANDLERSTATISTIC_H
#define HANDLERSTATISTIC_H
#include "../MainModel/struct/StatisticData.h"

class HandlerStatistic
{
public:
    HandlerStatistic(StatisticData * dataIn);
    StatisticData * data;
};

#endif // HANDLERSTATISTIC_H
