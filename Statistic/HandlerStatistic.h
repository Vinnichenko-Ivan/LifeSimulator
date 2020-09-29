#ifndef HANDLERSTATISTIC_H
#define HANDLERSTATISTIC_H
#include "../MainModel/struct/StatisticData.h"
#include "../MainModel/MainModel.h"
#include <QFile>
#include <QObject>
class HandlerStatistic:public QObject
{
    Q_OBJECT
public:
    explicit HandlerStatistic(StatisticData * dataIn,MainModel * modelIn,QObject * parent = nullptr);
    MainModel * model;
    StatisticData * data;
    QVector <StatisticData> dataData;
    void update();
    void save();
    signals:

};

#endif // HANDLERSTATISTIC_H
