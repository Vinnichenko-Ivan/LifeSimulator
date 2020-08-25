#include "GeneratorsSettingWidget.h"

GeneratorsSettingWidget::GeneratorsSettingWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout();
    addCreatureButton = new QPushButton("add creature");
    addFoodButton= new QPushButton("add food");
    connect(addCreatureButton,   &QPushButton::clicked, this,  &GeneratorsSettingWidget::addCreatureSlot);
    connect(addFoodButton,   &QPushButton::clicked, this,  &GeneratorsSettingWidget::addFoodSlot);
    layout->addWidget(addFoodButton,0,1);
    layout->addWidget(addCreatureButton,0,0);
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
