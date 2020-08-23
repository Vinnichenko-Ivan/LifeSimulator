#include "SettingWidget.h"

SettingWidget::SettingWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout();
    pauseButton = new QPushButton("=");
    connect(pauseButton,   &QPushButton::clicked, this,  &SettingWidget::pauseButtonSlot);
    layout->addWidget(pauseButton,0,0);
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
