#ifndef UPPANELWIDGET_H
#define UPPANELWIDGET_H

#include <QWidget>
#include <QWidget>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QMenu>
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
