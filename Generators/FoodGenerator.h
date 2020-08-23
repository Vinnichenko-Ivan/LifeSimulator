#ifndef FOODGENERATOR_H
#define FOODGENERATOR_H

#include <QObject>

class FoodGenerator : public QObject
{
    Q_OBJECT
public:
    explicit FoodGenerator(QObject *parent = nullptr);

signals:

};

#endif // FOODGENERATOR_H
