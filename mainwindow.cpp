#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    srand ( time(NULL) );
    model = new MainModel(this);
    creaturesGenerator = new CreaturesGenerator(model,this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::graphicUpdate);
    arena=new AreaWidget(model,this);
    upPanel= new UpPanelWidget(this);
    settings= new SettingWidget(this);
    statistics=new StatisticWidget(this);
    generatoesSetting=new GeneratorsSettingWidget(this);
    QGridLayout * layout = new QGridLayout(this);//15 на 35
    layout->addWidget(upPanel,0,0,1,15);
    layout->addWidget(arena,1,0,34,12);
    layout->addWidget(statistics,1,12,10,3);
    layout->addWidget(generatoesSetting,11,12,10,3);
    layout->addWidget(settings,21,12,14,3);
    setLayout(layout);
    connect(generatoesSetting->addCreatureButton,   &QPushButton::clicked, creaturesGenerator,  &CreaturesGenerator::addCreature);
    connect(settings->pauseButton,   &QPushButton::clicked, model,  &MainModel::pause);
   // connect(this, &MainWindow::paused, model, &MainModel::pause);
    graphicStart();
}

void MainWindow::graphicUpdate()
{
   arena->update();
   upPanel->update();
   settings->update();
   statistics->update();
   generatoesSetting->update();
}

void MainWindow::graphicStart() {
    timer->start(1000 / 24);
}

void MainWindow::graphicStop() {
    timer->stop();
}
