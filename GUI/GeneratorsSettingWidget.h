#ifndef GENERATORSSETTINGWIDGET_H
#define GENERATORSSETTINGWIDGET_H

#include <QWidget>
#include <QWidget>
#include <QPainter>
class GeneratorsSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GeneratorsSettingWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
signals:

};

#endif // GENERATORSSETTINGWIDGET_H
