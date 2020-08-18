#ifndef AREAWIDGET_H
#define AREAWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QDebug>
class AreaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AreaWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void widgetZone();
signals:

};

#endif // AREAWIDGET_H
