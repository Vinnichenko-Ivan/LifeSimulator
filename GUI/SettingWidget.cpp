#include "SettingWidget.h"

SettingWidget::SettingWidget(QWidget *parent) : QWidget(parent)
{

}
void SettingWidget::widgetZone()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(p);
    render(this);
}
void SettingWidget::paintEvent(QPaintEvent *event)
{
    widgetZone();
}
