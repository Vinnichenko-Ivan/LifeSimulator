#ifndef AREAWIDGET_H
#define AREAWIDGET_H
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QDebug>
#include <QImage>
#include <math.h>
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
public:
    explicit AreaWidget(MainModel * modelIn, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    int wight, height;
    QPainter * painter;
    ArenaGraphic* modelGraphic;
    QPixmap  creaturesTexture;
signals:

};

#endif // AREAWIDGET_H
