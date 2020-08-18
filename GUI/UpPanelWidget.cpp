#include "UpPanelWidget.h"

UpPanelWidget::UpPanelWidget(QWidget *parent) : QWidget(parent)
{

}

void UpPanelWidget::widgetZone()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::green);
    setAutoFillBackground(true);
    setPalette(p);
    render(this);
}

void UpPanelWidget::paintEvent(QPaintEvent *event)
{
    widgetZone();
}
