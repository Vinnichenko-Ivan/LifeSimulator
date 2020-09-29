#include "HandlerStatistic.h"

HandlerStatistic::HandlerStatistic(StatisticData * dataIn,MainModel * modelIn,QObject * parent): QObject(parent)
{
    model=modelIn;
    data=dataIn;
}

void HandlerStatistic::update()
{
    dataData.push_back(*data);
}

void HandlerStatistic::save()
{
    qDebug()<<"save";
    QFile file1("statistic.dat");
    if(!file1.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия для записи";
    }
    QTextStream writeStream(&file1);
    writeStream<<"creatures";
    for(auto n:data->creaturesCultures)
    {
        writeStream<<"\t"<<QString::fromStdString(n.first);
    }
    writeStream<<"\n";
    for(auto n:dataData)
    {
        writeStream<<n.countLivesCreatures;
        for(auto l:n.creaturesCultures)
        {
            writeStream<<"\t"<<l.second;
        }
        writeStream<<"\n";
    }
}
