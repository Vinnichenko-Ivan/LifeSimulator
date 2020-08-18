#include "GeneratorsSettingWidget.h"

GeneratorsSettingWidget::GeneratorsSettingWidget(QWidget *parent) : QWidget(parent)
{

}
void GeneratorsSettingWidget::widgetZone()
{
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::yellow);
    setAutoFillBackground(true);
    setPalette(p);
    render(this);
}
void GeneratorsSettingWidget::paintEvent(QPaintEvent *event)
{
    widgetZone();
}
