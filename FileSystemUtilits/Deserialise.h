#ifndef DESERIALISE_H
#define DESERIALISE_H
#include <QJsonDocument>
#include <QJsonObject>
class Deserialise
{
    virtual bool desirialise (QJsonObject & document)
    {
        return 0;
    }
};

#endif // DESIRIALISE_H
