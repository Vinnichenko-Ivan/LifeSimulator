#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWindow=new CentralWindow(this);
    setCentralWidget(centralWindow);
    displayCreatures = new QMenu("Creatures");
    file = new QMenu("File");
    display = new QMenu("Display");
    displayCreaturesVisionZone = new QAction("VisionZone");
    displayCreaturesVisionZone->setCheckable(true);
    displayCreaturesVisionZone->setChecked(false);
    menuBar()->addMenu(file);
    menuBar()->addMenu(display);
    display->addMenu(displayCreatures);
    displayCreatures->addAction(displayCreaturesVisionZone);
    connect(displayCreaturesVisionZone,QOverload<bool>::of(&QAction::toggled),
            [=](bool i){centralWindow->arena->displayVizionZoneTurn(i);});
}
