#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QHBoxLayout>
#include <QPainter>
#include <QPen>
#include <Qt>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::graphicUpdate);
    arena=new AreaWidget();
    upPanel= new UpPanelWidget();
    settings= new SettingWidget();
    statistics=new StatisticWidget();
    generatoesSetting=new GeneratorsSettingWidget();
    pauseButton = new QPushButton("=");
    QGridLayout * layout = new QGridLayout();//15 на 35
    layout->addWidget(upPanel,0,0,1,15);
    layout->addWidget(arena,1,0,34,12);
    layout->addWidget(statistics,1,12,10,3);
    layout->addWidget(generatoesSetting,11,12,10,3);
    layout->addWidget(settings,21,12,14,3);
    //layout->addWidget(arena);
    //layout->addWidget(pauseButton);
    setLayout(layout);
    connect(pauseButton,   &QPushButton::clicked, this,  &MainWindow::pauseButtonSlot);
    connect(this,&MainWindow::paused,&model,&MainModel::pauseLife);
    graphicStart();
}

void MainWindow::graphicUpdate()// TODO: fix recursive repaint
{
   arena->update();
   upPanel->update();
   settings->update();
   statistics->update();
   generatoesSetting->update();
}

void MainWindow::pauseButtonSlot()
{
     // меняем текст
     if(onPauseSymbol)
     {
         onPauseSymbol=0;
         pauseButton->setText("=");
     }
     else
     {
         onPauseSymbol=1;
         pauseButton->setText(">");
     }
     paused();
     qDebug() << "paused";
}

void MainWindow::graphicStart() {
    timer->start(1000 / 24);
}

void MainWindow::graphicStop() {
    timer->stop();
}
