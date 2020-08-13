#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <MainModel/MainModel.hpp>
#include <GUI/AreaWidget.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
private slots:
    void pauseButtonSlot();
signals:
    void paused();

private:
    QPushButton *pauseButton;
    MainModel model;
    bool onPauseSymbol=0;
    AreaWidget* arena;

};
#endif // MAINWINDOW_H
