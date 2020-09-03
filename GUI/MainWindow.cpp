#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWindow=new CentralWindow(this);
    setCentralWidget(centralWindow);
}
