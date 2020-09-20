#include "StatisticGraphics.h"

StatisticGraphics::StatisticGraphics(HandlerStatistic * handlerStatisticIn, QWidget *parent) : QWidget(parent)
{
    handlerStatistic = handlerStatisticIn;
    layout= new QGridLayout(this);
    chartView = new QtCharts::QChartView(this);
    chartCultures = new QtCharts::QChart();
    chartView->setChart(chartCultures);
    series = new QtCharts::QLineSeries();
    chartCultures->addSeries(series);
    chartCultures->legend()->hide();



    axisX= new QtCharts::QValueAxis();
    axisX->setTitleText("x, s");
    axisX->hide();
   // axisX->setLabelFormat("%i");
    //axisX->setTickCount(10);
    axisX->setMax(1000);
    axisY=new  QtCharts::QValueAxis();
    axisY->setTitleText("n");
    //axisY->setMax(250);
    //axisY->setLabelFormat("%g");
    //axisY->setTickCount(10);

    chartCultures->addAxis(axisX, Qt::AlignBottom);
    chartCultures->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);



    layout->setContentsMargins(1,1,1,1);
    layout->addWidget(chartView);
    setLayout(layout);

}

void StatisticGraphics::Background()
{

}
void StatisticGraphics::paintEvent(QPaintEvent *event)
{
    Background();
    update();
}

void StatisticGraphics::update()
{
    //QtCharts::QLineSeries * seriesA = new QtCharts::QLineSeries();
    *series<<QPointF(handlerStatistic->data->tickLives,handlerStatistic->data->countLivesCreatures);
    axisX->setMin(handlerStatistic->data->tickLives-1000);
    axisX->setMax(handlerStatistic->data->tickLives);
    axisY->setMax(std::max(handlerStatistic->data->maxCountLivesCreatures,10));
}
