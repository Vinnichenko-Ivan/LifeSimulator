#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QWidget>
#include <QPainter>
class SettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void widgetZone();
signals:

};

#endif // SETTINGWIDGET_H
