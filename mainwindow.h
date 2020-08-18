#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <MainModel/MainModel.hpp>
#include <GUI/AreaWidget.h>
#include <GUI/UpPanelWidget.h>
#include <GUI/GeneratorsSettingWidget.h>
#include <GUI/SettingWidget.h>
#include <GUI/StatisticWidget.h>
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
    void pauseButtonSlot();
signals:
    void paused();

private:
    QPushButton *pauseButton;
    MainModel model;
    bool onPauseSymbol=0;
    AreaWidget* arena;
    UpPanelWidget* upPanel;
    SettingWidget* settings;
    StatisticWidget* statistics;
    GeneratorsSettingWidget* generatoesSetting;
    QTimer * timer;

};
#endif // MAINWINDOW_H
