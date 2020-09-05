#include "GeneratorsSettingWidget.h"

GeneratorsSettingWidget::GeneratorsSettingWidget(IFoodGenerator * iFoodGeneratorIn,ICreatureGenerator* iCreatureGeneratorIn,QWidget *parent) : QWidget(parent)
{
    iFoodGenerator=iFoodGeneratorIn;
    iCreatureGenerator=iCreatureGeneratorIn;
    layout = new QGridLayout();
    addFoodByTimer = new QSpinBox(this);
    addFoodByTimer->setMinimum(0);
    addFoodByTimer->setMaximum(1000);
    addFoodByTimer->setValue(0);
    cultureSetting = new QComboBox(this);
    addCreatureButton = new QPushButton("add creature",this);
    addFoodButton= new QPushButton("add food",this);
    connect(addCreatureButton,   &QPushButton::clicked, this,  &GeneratorsSettingWidget::addCreatureSlot);
    connect(addFoodButton,   &QPushButton::clicked, this,  &GeneratorsSettingWidget::addFoodSlot);
    connect(addFoodByTimer, QOverload<int>::of(&QSpinBox::valueChanged),
        [=](int i){reloadFoodTimer(i);});
   // connect(cultureSetting , &QComboBox::,this, &GeneratorsSettingWidget::setCuturalCreatures);
    connect(cultureSetting, QOverload<int>::of(&QComboBox::activated),
        [=](int index){ setCultureCreatures(index); });
    layout->addWidget(addFoodButton,0,1);
    layout->addWidget(addCreatureButton,0,0);
    layout->addWidget(addFoodByTimer,1,1);
    layout->addWidget(cultureSetting,1,0);
    setLayout(layout);
    updateCultureCreatures();
}

void GeneratorsSettingWidget::Background()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::yellow);
    setAutoFillBackground(true);
    setPalette(p);
}

void GeneratorsSettingWidget::paintEvent(QPaintEvent *event)
{
    Background();
}

void GeneratorsSettingWidget::addCreatureSlot()
{

}

void GeneratorsSettingWidget::addFoodSlot()
{

}
void GeneratorsSettingWidget::reloadFoodTimer(int period)
{
    iFoodGenerator->setPeriod(period);
}

void GeneratorsSettingWidget::updateCultureCreatures()
{
    cultures=iCreatureGenerator->getCultureCreatures();
    culture=iCreatureGenerator->getSetCultureCreatures();
    cultureSetting->clear();
    for(auto n:cultures)
    {
        cultureSetting->addItem(QString::fromStdString(n));
    }
}

void GeneratorsSettingWidget::setCultureCreatures(int i)
{
    iCreatureGenerator->setCultureCreatures(cultures[i]);
}
