#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    FildWidget* arena=new FildWidget();
    pauseButton = new QPushButton("=");
    auto * layout = new QHBoxLayout();
    layout->addWidget(pauseButton);
    setLayout(layout);
    connect(pauseButton,   &QPushButton::clicked, this,  &MainWindow::pauseButtonSlot);
    connect(this,&MainWindow::paused,&model,&MainModel::pauseLife);
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
