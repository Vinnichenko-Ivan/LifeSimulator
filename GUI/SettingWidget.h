#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H
#include "../MainModel/MainModel.h"
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QPainter>
#include <QDebug>
#include <QSpinBox>
#include <QCheckBox>
class SettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingWidget(MainModel * mainModelIn,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event) override;
    void Background();
    MainModel * mainModel;
    QPushButton *pauseButton;
    QGridLayout * layout;
    QCheckBox * limitCreatures;
    QCheckBox * limitFood;
    QCheckBox * reproductIfMax;
    QSpinBox * countLimitCreatures;
    QSpinBox * countLimitFood;
    void pauseButtonSlot();
private:
    bool onPauseSymbol=0;
signals:
    void paused();

};

#endif // SETTINGWIDGET_H
