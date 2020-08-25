#ifndef AREAWIDGET_H
#define AREAWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QDebug>
#include "../MainModel/MainModel.h"
#include "../MainModel/public/ArenaGraphic.h"
#include "../MainModel/entity/struct/Cordinate.h"
class AreaWidget : public QWidget
{
    Q_OBJECT
private:
    MainModel * model;
    void paintCreature(int x,int y);
public:
    explicit AreaWidget(MainModel * modelIn, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    int wight, height;
    ArenaGraphic* modelGraphic;
signals:

};

#endif // AREAWIDGET_H
