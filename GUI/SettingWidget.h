#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <QDebug>
class SettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    QPushButton *pauseButton;
    QGridLayout * layout;
    void pauseButtonSlot();
private:
    bool onPauseSymbol=0;
signals:
    void paused();

};

#endif // SETTINGWIDGET_H
