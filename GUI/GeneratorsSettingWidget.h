#ifndef GENERATORSSETTINGWIDGET_H
#define GENERATORSSETTINGWIDGET_H

#include "../Generators/public/IFoodGenerator.h"
#include "../Generators/public/ICreatureGenerator.h"
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <QSpinBox>
#include <QDebug>
#include <QComboBox>
class GeneratorsSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GeneratorsSettingWidget(IFoodGenerator * iFoodGeneratorIn,ICreatureGenerator* iCreatureGeneratorIn,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    QPushButton * addCreatureButton;
    QPushButton * addFoodButton;
    QSpinBox * addFoodByTimer;
    QGridLayout * layout;
    IFoodGenerator * iFoodGenerator;
    ICreatureGenerator* iCreatureGenerator;
    QComboBox * cultureSetting;
    void addCreatureSlot();
    void addFoodSlot();
    void reloadFoodTimer(int period);
    void updateCultureCreatures();
    void setCultureCreatures(int i);
    std::pair<std::string,int> culture;
    std::vector<std::pair<std::string,int>> cultures;
signals:
    void addCreature();
};

#endif // GENERATORSSETTINGWIDGET_H
