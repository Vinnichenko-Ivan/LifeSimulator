#include "AreaWidget.h"

AreaWidget::AreaWidget(QWidget *parent) : QWidget(parent)
{

}

void AreaWidget::Background()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(p);
    render(this);
}
void AreaWidget::paintEvent(QPaintEvent *event)
{
    Background();
}
