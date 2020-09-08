#ifndef STATISTICWIDGET_H
#define STATISTICWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QGridLayout>
#include "../Statistic/HandlerStatistic.h"
class StatisticWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticWidget(HandlerStatistic * handlerStatisticIn,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    QGridLayout* layout;
    QLabel * livesCreatures;
    HandlerStatistic * handlerStatistic;
signals:

};

#endif // STATISTICWIDGET_H
