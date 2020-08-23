#include "GeneratorsSettingWidget.h"

GeneratorsSettingWidget::GeneratorsSettingWidget(QWidget *parent) : QWidget(parent)
{

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
