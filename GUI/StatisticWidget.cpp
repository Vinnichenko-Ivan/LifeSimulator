#include "StatisticWidget.h"

StatisticWidget::StatisticWidget(HandlerStatistic * handlerStatisticIn, QWidget *parent) : QWidget(parent)
{
    handlerStatistic = handlerStatisticIn;
    statisticGraphics = new StatisticGraphics(handlerStatistic,this);
    layout= new QGridLayout(this);
    livesCreatures = new QLabel();
    layout->setContentsMargins(1,1,1,1);
    layout->addWidget(statisticGraphics,0,0,9,0);
    layout->addWidget(livesCreatures,9,0);
    setLayout(layout);
}
void StatisticWidget::Background()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor(210,210,210));
    setAutoFillBackground(true);
    setPalette(p);
}
void StatisticWidget::paintEvent(QPaintEvent *event)
{
    livesCreatures->setText("lives creatures: "+QString::number(handlerStatistic->data->countLivesCreatures));
    Background();
}
