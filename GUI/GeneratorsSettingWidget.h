#ifndef GENERATORSSETTINGWIDGET_H
#define GENERATORSSETTINGWIDGET_H

#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <QDebug>
class GeneratorsSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GeneratorsSettingWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    QPushButton * addCreatureButton;
    QPushButton * addFoodButton;
    QGridLayout * layout;
    void addCreatureSlot();
    void addFoodSlot();
signals:
    void addCreature();
};

#endif // GENERATORSSETTINGWIDGET_H
