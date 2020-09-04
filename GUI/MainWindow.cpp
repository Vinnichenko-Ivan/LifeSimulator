#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWindow=new CentralWindow(this);
    setCentralWidget(centralWindow);
    displayCreatures = new QMenu("Creatures");
    file = new QMenu("File");
    display = new QMenu("Display");
    displayCreaturesVisionZone = new QAction("Vision Zone");
    displayCreaturesVisionZone->setCheckable(true);
    displayCreaturesVisionZone->setChecked(false);
    displayCreaturesAxis = new QAction("Axis");
    displayCreaturesAxis->setCheckable(true);
    displayCreaturesAxis->setChecked(false);
    displayCreaturesHp = new QAction("Hill point");
    displayCreaturesHp->setCheckable(true);
    displayCreaturesHp->setChecked(false);
    displayCreaturesEnergy =new QAction("Energy");
    displayCreaturesEnergy->setCheckable(true);
    displayCreaturesEnergy->setChecked(false);
    helpWindow = new QAction("Help");
    file->addAction(helpWindow);
    menuBar()->addMenu(file);
    menuBar()->addMenu(display);
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
}
