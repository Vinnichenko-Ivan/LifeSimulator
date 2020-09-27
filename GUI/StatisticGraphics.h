#ifndef STATISTICGRAPHICS_H
#define STATISTICGRAPHICS_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QPointF>
#include <QGridLayout>
#include "../Statistic/HandlerStatistic.h"

class StatisticGraphics : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticGraphics(HandlerStatistic * handlerStatisticIn,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    void update();
    void updateCultures();
    HandlerStatistic * handlerStatistic;
    QGridLayout * layout;
    QtCharts::QChartView* chartView;
    QtCharts::QChart* chartCultures;
    QtCharts::QValueAxis *axisX;
    QtCharts::QValueAxis *axisY;
    QtCharts::QLineSeries *series;
    QVector <std::pair<QtCharts::QLineSeries *,std::string>> seriesCultures;
signals:

};

#endif // STATISTICGRAPHICS_H
