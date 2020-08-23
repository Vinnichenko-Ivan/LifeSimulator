#include "AreaWidget.h"

AreaWidget::AreaWidget(QWidget *parent) : QWidget(parent)
{

}

void AreaWidget::Background()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(p);
}
void AreaWidget::paintEvent(QPaintEvent *event)
{
    Background();
}
