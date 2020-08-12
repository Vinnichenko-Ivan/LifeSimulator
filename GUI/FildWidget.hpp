
#include <QWidget>
#include <QObject>
#ifndef FILDWIDGET_HPP
#define FILDWIDGET_HPP


class FildWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FildWidget(QWidget *parent = nullptr);


};

 FildWidget::FildWidget(QWidget *parent) : QWidget(parent)
{

}
#endif // FILDWIDGET_HPP
