#include "StatisticWidget.h"

StatisticWidget::StatisticWidget(QWidget *parent) : QWidget(parent)
{

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
    Background();
}
