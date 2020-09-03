#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include "CentralWindow.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QMenu* file;
    QMenu* display;
    QMenu* displayCreatures;
    QAction* displayCreaturesVisionZone;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    CentralWindow * centralWindow;
signals:

};

#endif // MAINWINDOW_H
