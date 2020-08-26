#include "GeneratorsSettingWidget.h"

GeneratorsSettingWidget::GeneratorsSettingWidget(IFoodGenerator * iFoodGeneratorIn,QWidget *parent) : QWidget(parent)
{
    iFoodGenerator=iFoodGeneratorIn;
    layout = new QGridLayout();
    addFoodByTimer = new QSpinBox(this);
    addFoodByTimer->setMinimum(0);
    addFoodByTimer->setMaximum(100);
    addFoodByTimer->setValue(0);
    addCreatureButton = new QPushButton("add creature",this);
    addFoodButton= new QPushButton("add food",this);
    connect(addCreatureButton,   &QPushButton::clicked, this,  &GeneratorsSettingWidget::addCreatureSlot);
    connect(addFoodButton,   &QPushButton::clicked, this,  &GeneratorsSettingWidget::addFoodSlot);
    connect(addFoodByTimer, QOverload<int>::of(&QSpinBox::valueChanged),
        [=](int i){reloadFoodTimer(i);});
    layout->addWidget(addFoodButton,0,1);
    layout->addWidget(addCreatureButton,0,0);
    layout->addWidget(addFoodByTimer,1,1);
    setLayout(layout);
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
