#include "AreaWidget.h"

AreaWidget::AreaWidget(QWidget *parent) : QWidget(parent)
{

}

void AreaWidget::widgetZone()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(p);
    render(this);
}
void AreaWidget::paintEvent(QPaintEvent *event)
{
    widgetZone();
}
