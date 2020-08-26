#include "AreaWidget.h"

AreaWidget::AreaWidget(MainModel * modelIn,QWidget *parent) : QWidget(parent)
{
    model=modelIn;
    modelGraphic=modelIn;
    creaturesTexture =  QPixmap("texture/Untitled.bmp");
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
    painter = new QPainter(this);
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
    painter->end();
}

void AreaWidget::paintCreature(int x,int y)
{
    painter->drawPixmap(x-5, y-5, creaturesTexture );
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter->drawPixmap(x-5, y-5, creaturesTexture );
    painter->drawPoint(x,y);
}

void AreaWidget::paintFood(int x,int y)
{
    painter->setPen(QPen(QColor(102,95,69), 0, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(102,95,69), Qt::SolidPattern));
    painter->drawPoint(x,y);
}
