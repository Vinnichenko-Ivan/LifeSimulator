#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWindow=new CentralWindow(this);
    setCentralWidget(centralWindow);
    displayCreatures = new QMenu("Creatures");
    file = new QMenu("File");
    display = new QMenu("Display");
    statistic = new QMenu("Statistic");
    saveFile = new QMenu("Save");
    loadFile = new QMenu("Load");
    saveAll = new QAction("Save all");
    addAll = new QAction("Add all");
    replaceAll = new QAction("Replace sll");
    displayCreaturesVisionZone = new QAction("Vision Zone");
    displayCreaturesVisionZone->setCheckable(true);
    displayCreaturesVisionZone->setChecked(centralWindow->arena->displayVizionZone);
    displayCreaturesAxis = new QAction("Axis");
    displayCreaturesAxis->setCheckable(true);
    displayCreaturesAxis->setChecked(centralWindow->arena->displayCreaturesAxis);
    displayCreaturesHp = new QAction("Hill point");
    displayCreaturesHp->setCheckable(true);
    displayCreaturesHp->setChecked(centralWindow->arena->displayCreaturesHp);
    displayCreaturesEnergy =new QAction("Energy");
    displayCreaturesEnergy->setCheckable(true);
    displayCreaturesEnergy->setChecked(centralWindow->arena->displayCreaturesEnergy);
    saveStastistic =new QAction("Save");
    helpWindow = new QAction("Help");
    file->addAction(helpWindow);
    file->addMenu(saveFile);
    file->addMenu(loadFile);
    loadFile->addAction(addAll);
    loadFile->addAction(replaceAll);
    saveFile->addAction(saveAll);
    menuBar()->addMenu(file);
    menuBar()->addMenu(display);
    menuBar()->addMenu(statistic);
    statistic->addAction(saveStastistic);
    display->addMenu(displayCreatures);
    displayCreatures->addAction(displayCreaturesVisionZone);
    displayCreatures->addAction(displayCreaturesAxis);
    displayCreatures->addAction(displayCreaturesHp);
    displayCreatures->addAction(displayCreaturesEnergy);
    connect(displayCreaturesVisionZone,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayCreaturesVizionZoneTurn(i);});
    connect(displayCreaturesAxis,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayCreaturesAxisTurn(i);});
    connect(displayCreaturesHp,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayCreaturesHpTurn(i);});
    connect(displayCreaturesEnergy,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayCreaturesEnergyTurn(i);});
    connect(saveStastistic,&QAction::triggered,centralWindow->handlerStatistic,&HandlerStatistic::save);
    connect(saveAll,&QAction::triggered,centralWindow->serDeserSistem,&SerDeserSistem::saveAll);
    connect(replaceAll,&QAction::triggered,centralWindow->serDeserSistem,&SerDeserSistem::loadAndReplaceAll);
    connect(addAll,&QAction::triggered,centralWindow->serDeserSistem,&SerDeserSistem::loadAndAddAll);
}
