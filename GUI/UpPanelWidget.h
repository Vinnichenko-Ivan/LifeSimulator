#ifndef UPPANELWIDGET_H
#define UPPANELWIDGET_H

#include <QWidget>
#include <QWidget>
#include <QPainter>
class UpPanelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UpPanelWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
signals:

};

#endif // UPPANELWIDGET_H
