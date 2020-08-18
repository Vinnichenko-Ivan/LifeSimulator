#include "StatisticWidget.h"

StatisticWidget::StatisticWidget(QWidget *parent) : QWidget(parent)
{

}
void StatisticWidget::widgetZone()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::red);
    setAutoFillBackground(true);
    setPalette(p);
    render(this);
}
void StatisticWidget::paintEvent(QPaintEvent *event)
{
    widgetZone();
}
