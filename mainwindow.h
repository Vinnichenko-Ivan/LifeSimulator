
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <MainModel/MainModel.h>
#include <GUI/AreaWidget.h>
#include <GUI/UpPanelWidget.h>
#include <GUI/GeneratorsSettingWidget.h>
#include <GUI/SettingWidget.h>
#include <GUI/StatisticWidget.h>
#include <GUI/StatisticWidget.h>
#include <Generators/CreaturesGenerator.h>
#include <Generators/FoodGenerator.h>
#include <QHBoxLayout>
#include <QPainter>
#include <QPen>
#include <Qt>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void graphicUpdate();
    void graphicStart();
    void graphicStop();
private slots:

signals:
    void paused();

private:
    CreaturesGenerator * creaturesGenerator;
    FoodGenerator * foodGenerator;
    MainModel * model;
    AreaWidget* arena;
    UpPanelWidget* upPanel;
    SettingWidget* settings;
    StatisticWidget* statistics;
    GeneratorsSettingWidget* generatoesSetting;
    QTimer * timer;

};
#endif // MAINWINDOW_H


