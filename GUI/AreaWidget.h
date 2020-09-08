#ifndef AREAWIDGET_H
#define AREAWIDGET_H
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QDebug>
#include <QImage>
#include <QtGui>
#include <math.h>
//#include "texture/creature.xpm"
#include "../MainModel/MainModel.h"
#include "../MainModel/public/ArenaGraphic.h"
#include "../MainModel/entity/struct/Cordinate.h"
class AreaWidget : public QWidget
{
    Q_OBJECT
private:
    MainModel * model;
    void paintCreature(double x,double y,double angle);
    void paintFood(int x,int y);
    void paintCreatureVisionZone(int x,int y,int radius);
    void paintCreatureAxis(double x,double y,double angle);
    void paintCreaturesHp(int x,int y, double percent);
    void paintCreaturesEnergy(int x,int y, double percent);
public:
    bool displayVizionZone=0;
    bool displayCreaturesAxis=0;
    bool displayCreaturesHp=1;
    bool displayCreaturesEnergy=1;
    explicit AreaWidget(MainModel * modelIn, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    int wight, height;
    QPainter * painter;
    ArenaGraphic* modelGraphic;
    QPixmap  creaturesTexture;

    void displayCreaturesVizionZoneTurn(bool in);
    void displayCreaturesAxisTurn(bool in);
    void displayCreaturesHpTurn(bool in);
    void displayCreaturesEnergyTurn(bool in);
signals:

};

#endif // AREAWIDGET_H
