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
    displayCreaturesXp = new QAction("Xill point");
    displayCreaturesXp->setCheckable(true);
    displayCreaturesXp->setChecked(false);
    displayCreaturesEnergy =new QAction("Energy");
    displayCreaturesEnergy->setCheckable(true);
    displayCreaturesEnergy->setChecked(false);
    menuBar()->addMenu(file);
    menuBar()->addMenu(display);
    display->addMenu(displayCreatures);
    displayCreatures->addAction(displayCreaturesVisionZone);
    displayCreatures->addAction(displayCreaturesAxis);
    displayCreatures->addAction(displayCreaturesXp);
    displayCreatures->addAction(displayCreaturesEnergy);
    connect(displayCreaturesVisionZone,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayCreaturesVizionZoneTurn(i);});
    connect(displayCreaturesAxis,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayCreaturesAxisTurn(i);});
    connect(displayCreaturesXp,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayCreaturesXpTurn(i);});
    connect(displayCreaturesEnergy,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayCreaturesEnergyTurn(i);});
}
