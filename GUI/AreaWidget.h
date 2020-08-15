#ifndef AREAWIDGET_H
#define AREAWIDGET_H

#include <QWidget>
#include <QPainter>
class AreaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AreaWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
signals:

};

#endif // AREAWIDGET_H
