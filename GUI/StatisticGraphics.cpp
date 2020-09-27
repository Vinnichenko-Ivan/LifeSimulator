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
    axisX->setMax(1000);

    axisY=new  QtCharts::QValueAxis();
    axisY->setTitleText("n");

    chartCultures->addAxis(axisX, Qt::AlignBottom);
    chartCultures->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    series->setName("all");
    layout->setContentsMargins(1,1,1,1);
    layout->addWidget(chartView);
    setLayout(layout);
    updateCultures();
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
    *series<<QPointF(handlerStatistic->data->tickLives,handlerStatistic->data->countLivesCreatures);
    for(auto n:handlerStatistic->data->creaturesCultures)
    {
        for(int i=0;i<seriesCultures.size();i++)
        {
            if(seriesCultures[i].second==n.first)
            {
                *seriesCultures[i].first<<QPointF(handlerStatistic->data->tickLives,n.second);
            }
        }
    }
    axisX->setMin(handlerStatistic->data->tickLives-1000);
    axisX->setMax(handlerStatistic->data->tickLives);
    axisY->setMax(std::max(handlerStatistic->data->maxCountLivesCreatures,10));
}

void StatisticGraphics::updateCultures()
{
    seriesCultures.clear();
    for(auto* n:handlerStatistic->model->cultures)
    {
        QtCharts::QLineSeries *buffSeries = new QtCharts::QLineSeries();
        chartCultures->addSeries(buffSeries);
        buffSeries->attachAxis(axisX);
        buffSeries->attachAxis(axisY);
        buffSeries->setColor(n->getColor());
        buffSeries->setName(QString::fromStdString(n->getNameOfCulture()));
        seriesCultures.push_back(std::pair<QtCharts::QLineSeries *,std::string>(buffSeries,n->getNameOfCulture()));
    }
}
