#include "StatisticWidget.h"

StatisticWidget::StatisticWidget(HandlerStatistic * handlerStatisticIn, QWidget *parent) : QWidget(parent)
{
    handlerStatistic = handlerStatisticIn;
    layout= new QGridLayout(this);
    livesCreatures = new QLabel();
    layout->addWidget(livesCreatures,0,0);
    setLayout(layout);
}
void StatisticWidget::Background()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::red);
    setAutoFillBackground(true);
    setPalette(p);
}
void StatisticWidget::paintEvent(QPaintEvent *event)
{
    livesCreatures->setText("lives creatures: "+QString::number(handlerStatistic->data->countLivesCreatures));
    Background();
}
