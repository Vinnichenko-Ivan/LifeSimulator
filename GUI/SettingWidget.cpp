#include "SettingWidget.h"

SettingWidget::SettingWidget(MainModel * mainModelIn,QWidget *parent) : QWidget(parent)
{
    mainModel = mainModelIn;
    layout = new QGridLayout();
    limitCreatures = new QCheckBox("limit Creatures",this);
    limitFood = new QCheckBox("limit Food",this);
    reproductIfMax = new QCheckBox("reproduct if max",this);
    countLimitCreatures= new QSpinBox(this);
    countLimitFood= new QSpinBox(this);
    pauseButton = new QPushButton("=");
    connect(pauseButton,   &QPushButton::clicked, this,  &SettingWidget::pauseButtonSlot);
    connect(countLimitCreatures,QOverload<int>::of(&QSpinBox::valueChanged),
            [=](int i){mainModel->setCountLimitCreatures(i);});
    connect(countLimitFood,QOverload<int>::of(&QSpinBox::valueChanged),
            [=](int i){mainModel->setCountLimitFood(i);});
    connect(limitFood,QOverload<int>::of(&QCheckBox::stateChanged),
            [=](bool i){mainModel->setLimitFood(i);});
    connect(limitCreatures,QOverload<int>::of(&QCheckBox::stateChanged),
            [=](bool i){mainModel->setLimitCreatures(i);});
    connect(reproductIfMax,QOverload<int>::of(&QCheckBox::stateChanged),
            [=](bool i){mainModel->stopReproductIfMax(i);});
    limitFood->setChecked(true);
    countLimitFood->setMaximum(10000);
    countLimitFood->setValue(500);
    countLimitCreatures->setMaximum(100);
    countLimitCreatures->setValue(25);
    layout->addWidget(pauseButton,4,0);
    layout->addWidget(limitCreatures,1,0);
    layout->addWidget(limitFood,3,0);
    layout->addWidget(countLimitCreatures,1,1);
    layout->addWidget(reproductIfMax,2,0,1,2);
    layout->addWidget(countLimitFood,3,1);
    setLayout(layout);
}
void SettingWidget::Background()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(p);
}
void SettingWidget::paintEvent(QPaintEvent *event)
{
    Background();
}

void SettingWidget::pauseButtonSlot()
{
     // меняем текст
     if(onPauseSymbol)
     {
         onPauseSymbol=0;
         pauseButton->setText("=");
     }
     else
     {
         onPauseSymbol=1;
         pauseButton->setText(">");
     }
     paused();
     qDebug() << "paused";
}
