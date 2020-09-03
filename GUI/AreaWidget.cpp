#include "AreaWidget.h"
#define PI 3.14159265
AreaWidget::AreaWidget(MainModel * modelIn,QWidget *parent) : QWidget(parent)
{
    model=modelIn;
    modelGraphic=modelIn;
    creaturesTexture =  QPixmap(creature_xpm);
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
        paintCreature(n->x,n->y,n->angle);
    }
    for(auto * n:model->cordinatesFoods)
    {
        paintFood(n->x,n->y);
    }
    if(displayVizionZone)
    {
        for(int i=0;i<model->cordinatesCreatures.size();i++)
        {
            paintVisionZone(model->cordinatesCreatures[i]->x,model->cordinatesCreatures[i]->y,model->condithionsCreature[i]->visionLenght);
        }
    }
    painter->end();
}

void AreaWidget::paintCreature(double x,double y,double angle)
{
    //painter->drawPixmap(x-4, y-6, creaturesTexture );
    painter->setPen(QPen(QColor(102,95,69,127), 0, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(102,95,69,127), Qt::SolidPattern));
    //painter->translate(4,6);
    int helpX=-4,helpY=-6;
    //angle=(int)(360+180-angle)%360;
    double angleRad=angle* PI / (double)180;
    double newX=(x)*std::cos(angleRad)+(y)*std::sin(angleRad)+helpX;//+((2)*std::cos(angleRad)+(2)*std::sin(angleRad));
    double newY= (-x)*std::sin(angleRad)+(y)*std::cos(angleRad)+helpY;//-((3)*std::cos(angleRad)+(3)*std::sin(angleRad));
    painter->rotate(angle);
    painter->drawPixmap(newX, newY ,creaturesTexture );
    painter->rotate(-angle);
    //painter->translate(-4,-6);
    painter->drawPoint(x,y);
}

void AreaWidget::paintFood(int x,int y)
{
    painter->setPen(QPen(QColor(102,95,69), 0, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(102,95,69), Qt::SolidPattern));
    painter->drawPoint(x,y);
}

void AreaWidget::paintVisionZone(int x,int y,int radius)
{
    painter->setPen(QPen(QColor(102,95,69,127), 0, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(102,95,69,127), Qt::SolidPattern));
    painter->drawEllipse(x-radius/2,y-radius/2,radius,radius);
}

void AreaWidget::displayVizionZoneTurn(bool in)
{
    displayVizionZone=in;
}

