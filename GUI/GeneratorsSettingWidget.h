#ifndef GENERATORSSETTINGWIDGET_H
#define GENERATORSSETTINGWIDGET_H

#include "../Generators/public/IFoodGenerator.h"
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <QSpinBox>
#include <QDebug>
class GeneratorsSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GeneratorsSettingWidget(IFoodGenerator * iFoodGeneratorIn,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    QPushButton * addCreatureButton;
    QPushButton * addFoodButton;
    QSpinBox * addFoodByTimer;
    QGridLayout * layout;
    IFoodGenerator * iFoodGenerator;
    void addCreatureSlot();
    void addFoodSlot();
    void reloadFoodTimer(int period);
signals:
    void addCreature();
};

#endif // GENERATORSSETTINGWIDGET_H
