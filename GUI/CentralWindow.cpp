#include "CentralWindow.h"
//#include "./ui_CentralWindow.h"

CentralWindow::CentralWindow(QWidget *parent)
    : QWidget(parent)
{

    srand ( time(NULL) );
    model = new MainModel(this);
    creaturesGenerator = new CreaturesGenerator(model,this);
    foodGenerator = new FoodGenerator(model,this);
    timer = new QTimer(this);    
    arena=new AreaWidget(model,this);
    settings= new SettingWidget(model,this);
    handlerStatistic = new HandlerStatistic(model->statisticData,model,this);
    statistics=new StatisticWidget(handlerStatistic,this);
    generatoesSetting=new GeneratorsSettingWidget(foodGenerator,creaturesGenerator,this);
    QGridLayout * layout = new QGridLayout(this);//15 на 35
    layout->addWidget(arena,1,0,34,12);
    layout->addWidget(statistics,1,12,10,3);
    layout->addWidget(generatoesSetting,11,12,10,3);
    layout->addWidget(settings,21,12,14,3);
    setLayout(layout);
    connect(timer, &QTimer::timeout, this, &CentralWindow::graphicUpdate);
    connect(generatoesSetting->addCreatureButton,   &QPushButton::clicked, creaturesGenerator,  &CreaturesGenerator::addCreature);
    connect(generatoesSetting->addFoodButton,   &QPushButton::clicked, foodGenerator,  &FoodGenerator::addFood);
    connect(settings->pauseButton,   &QPushButton::clicked, model,  &MainModel::pause);
    connect(settings->pauseButton,   &QPushButton::clicked, foodGenerator,  &FoodGenerator::pause);
    connect(model,&MainModel::updateStatisticInHandler,handlerStatistic,&HandlerStatistic::update);
    graphicStart();
}

void CentralWindow::graphicUpdate()
{
   arena->update();
   settings->update();
   statistics->update();
   generatoesSetting->update();
}

void CentralWindow::graphicStart() {
    timer->start(1000 / 24);
}

void CentralWindow::graphicStop() {
    timer->stop();
}




