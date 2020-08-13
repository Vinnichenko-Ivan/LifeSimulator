#ifndef AREAWIDGET_H
#define AREAWIDGET_H

#include <QWidget>
#include <QPainter>
class AreaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AreaWidget(QWidget *parent = nullptr);
    void testDraw();
signals:

};

#endif // AREAWIDGET_H
