#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pauseButton = new QPushButton("=", this);
    ui->setupUi(this);
    pauseButton->setGeometry(QRect(QPoint(100, 100),
    QSize(50, 50)));
    connect(pauseButton,   &QPushButton::clicked, this,  &MainWindow::pauseButtonSlot);
}

void MainWindow::pauseButtonSlot()
{
 // меняем текст
 pauseButton->setText("Example");
 // изменяем размер кнопки
 pauseButton->resize(100,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

