#include "AreaWidget.h"

AreaWidget::AreaWidget(MainModel * modelIn,QWidget *parent) : QWidget(parent)
{
    model=modelIn;
    modelGraphic=modelIn;
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
    wight=geometry().width();
    height=geometry().height();
    modelGraphic->updateArenaSize(wight,height);
    for(auto * n:model->cordinatesCreatures)
    {
        paintCreature(n->x,n->y);
    }
    for(auto * n:model->cordinatesFoods)
    {
        paintFood(n->x,n->y);
    }
}

void AreaWidget::paintCreature(int x,int y)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(x-5, y-5, 10, 10);
    painter.drawPoint(x,y);
}

void AreaWidget::paintFood(int x,int y)
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(102,95,69), 0, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(QColor(102,95,69), Qt::SolidPattern));
    painter.drawPoint(x,y);
}
