#include "AreaWidget.h"

AreaWidget::AreaWidget(QWidget *parent) : QWidget(parent)
{

}

void AreaWidget::paintEvent(QPaintEvent *event)
{

    QPainter p(this);
    QPen pen;
    pen.setColor(Qt::lightGray);
    p.drawLine(0,0,100,500);//рисует эту линию на QMainwindow,а не на QWIdget
    p.drawRect(0,100,100,100);
    p.setPen(pen);
    p.end();
    render(this);
}
