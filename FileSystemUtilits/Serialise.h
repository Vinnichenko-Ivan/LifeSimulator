#ifndef SERIALISE_H
#define SERIALISE_H
#include <QJsonDocument>
#include <QJsonObject>
class Serialise
{
    virtual QJsonObject serialise()
    {
        qDebug()<<"serialise functhion no override";
    }
};
#endif // SERIALISE_H
