#ifndef STATISTICWIDGET_H
#define STATISTICWIDGET_H

#include <QWidget>
#include <QWidget>
#include <QPainter>
class StatisticWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void widgetZone();
signals:

};

#endif // STATISTICWIDGET_H
