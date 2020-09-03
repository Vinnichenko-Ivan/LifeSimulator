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
            paintCreatureVisionZone(model->cordinatesCreatures[i]->x,model->cordinatesCreatures[i]->y,model->condithionsCreature[i]->visionLenght);
        }
    }
    if(displayCreaturesAxis)
    {
        for(auto * n:model->cordinatesCreatures)
        {
            paintCreatureAxis(n->x,n->y,n->angle);
        }
    }
    if(displayCreaturesXp)
    {
        for(int i=0;i<model->cordinatesCreatures.size();i++)
        {
            paintCreaturesXp(model->cordinatesCreatures[i]->x,model->cordinatesCreatures[i]->y,(double)model->condithionsCreature[i]->xp/(double)model->condithionsCreature[i]->maxXp);
        }
    }
    if(displayCreaturesEnergy)
    {
        for(int i=0;i<model->cordinatesCreatures.size();i++)
        {
            paintCreaturesEnergy(model->cordinatesCreatures[i]->x,model->cordinatesCreatures[i]->y,(double)model->condithionsCreature[i]->energy/(double)model->condithionsCreature[i]->maxEnergy);
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

void AreaWidget::paintCreatureVisionZone(int x,int y,int radius)
{
    painter->setPen(QPen(QColor(102,95,69,127), 0, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(102,95,69,127), Qt::SolidPattern));
    painter->drawEllipse(x-radius,y-radius,radius*2,radius*2);
}

void AreaWidget::displayCreaturesVizionZoneTurn(bool in)
{
    displayVizionZone=in;
}

void AreaWidget::displayCreaturesAxisTurn(bool in)
{
    displayCreaturesAxis=in;
}
void AreaWidget::paintCreatureAxis(double x,double y,double angle)
{
    int lenght=15;
    int helpX=0,helpY=0;
    double angleRad=angle* PI / (double)180;
    double newX=(x)*std::cos(angleRad)+(y)*std::sin(angleRad)+helpX;//+((2)*std::cos(angleRad)+(2)*std::sin(angleRad));
    double newY= (-x)*std::sin(angleRad)+(y)*std::cos(angleRad)+helpY;//-((3)*std::cos(angleRad)+(3)*std::sin(angleRad));
    painter->rotate(angle);
    painter->setPen(QPen(QColor(0,0,255,127), 1, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(0,0,255,127), Qt::SolidPattern));
    painter->drawLine(newX,newY,newX+lenght,newY);
    painter->drawLine(newX+lenght,newY,newX+lenght-3,newY+3);
    painter->drawLine(newX+lenght,newY,newX+lenght-3,newY-3);
    painter->setPen(QPen(QColor(0,255,0,127), 1, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(0,255,0,127), Qt::SolidPattern));
    painter->drawLine(newX,newY,newX,newY+lenght);
    painter->drawLine(newX,newY+lenght,newX+3,newY+lenght-3);
    painter->drawLine(newX,newY+lenght,newX-3,newY+lenght-3);
    painter->rotate(-angle);
}

void AreaWidget::displayCreaturesXpTurn(bool in)
{
    displayCreaturesXp=in;
}

void AreaWidget::displayCreaturesEnergyTurn(bool in)
{
    displayCreaturesEnergy=in;
}

void AreaWidget::paintCreaturesXp(int x,int y, double percent)
{
    int lenght=10;
    int up=-13;
    int xEq=x-lenght/2+lenght*percent;
    painter->setPen(QPen(QColor(255,0,0,127), 1, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(255,0,0,127), Qt::SolidPattern));
    painter->drawLine(x-lenght/2,y+up,xEq,y+up);
    painter->setPen(QPen(QColor(255,255,255,127), 1, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(255,255,255,127), Qt::SolidPattern));
    painter->drawLine(xEq,y+up,x+lenght/2,y+up);
}

void AreaWidget::paintCreaturesEnergy(int x,int y, double percent)
{
    int lenght=10;
    int up=-15;
    int xEq=x-lenght/2+lenght*percent;
    painter->setPen(QPen(QColor(0,0,255,127), 1, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(0,0,255,127), Qt::SolidPattern));
    painter->drawLine(x-lenght/2,y+up,xEq,y+up);
    painter->setPen(QPen(QColor(255,255,255,127), 1, Qt::SolidLine, Qt::FlatCap));
    painter->setBrush(QBrush(QColor(255,255,255,127), Qt::SolidPattern));
    painter->drawLine(xEq,y+up,x+lenght/2,y+up);
}
