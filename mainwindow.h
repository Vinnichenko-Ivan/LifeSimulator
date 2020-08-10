#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <MainModel/MainModel.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void pauseButtonSlot();

private:
    QPushButton *pauseButton;
    Ui::MainWindow *ui;
    MainModel model;
};
#endif // MAINWINDOW_H
