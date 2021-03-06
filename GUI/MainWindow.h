#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QChar>
#include "CentralWindow.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QMenu* file;
    QMenu* display;
    QMenu* displayCreatures;
    QMenu* statistic;
    QMenu* saveFile;
    QMenu* loadFile;
    QAction* displayCreaturesVisionZone;
    QAction* displayCreaturesAxis;
    QAction* displayCreaturesHp;
    QAction* displayCreaturesEnergy;
    QAction* saveStastistic;
    QAction* saveAll;
    QAction* replaceAll;
    QAction* addAll;
    QAction* helpWindow;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    CentralWindow * centralWindow;
signals:

};

#endif // MAINWINDOW_H
