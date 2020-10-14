
#ifndef CENTRALWINDOW_H
#define CENTRALWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "../MainModel/MainModel.h"
#include "AreaWidget.h"
#include "GeneratorsSettingWidget.h"
#include "SettingWidget.h"
#include "StatisticWidget.h"
#include "StatisticWidget.h"
#include "../Generators/CreaturesGenerator.h"
#include "../Generators/FoodGenerator.h"
#include "Statistic/HandlerStatistic.h"
#include "../FileSystemUtilits/SerDeserSistem.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QPen>
#include <Qt>
#include <QTimer>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
QT_BEGIN_NAMESPACE
namespace Ui { class CentralWindow; }
QT_END_NAMESPACE

class CentralWindow : public QWidget
{
    Q_OBJECT

public:
    CentralWindow(QWidget *parent = nullptr);
    void graphicUpdate();
    void graphicStart();
    void graphicStop();
private slots:

signals:
    void paused();

public:
    CreaturesGenerator * creaturesGenerator;
    FoodGenerator * foodGenerator;
    MainModel * model;
    AreaWidget* arena;
    SettingWidget* settings;
    StatisticWidget* statistics;
    GeneratorsSettingWidget* generatoesSetting;
    HandlerStatistic * handlerStatistic;
    SerDeserSistem * serDeserSistem;
    QTimer * timer;
    QMenuBar * menuBar;
};
#endif // CentralWindow_H


