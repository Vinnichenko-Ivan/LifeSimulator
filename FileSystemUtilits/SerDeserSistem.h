#ifndef SERDESERSISTEM_H
#define SERDESERSISTEM_H

#include <QObject>
#include <QJsonArray>
#include <QDir>
#include <QFileDialog>
#include "../MainModel/MainModel.h"
class SerDeserSistem : public QObject
{
    Q_OBJECT
public:
    explicit SerDeserSistem(MainModel* modelIn,QObject *parent = nullptr);
    MainModel* model;
    void saveAll();
    void saveCordinatesCreatures();
    void saveCondithionsCreatures();
    void saveCreatures();
    void saveProFile();
    void loadAndAddAll();
    void loadAndReplaceAll();
    QString saveFileName;
signals:

};

#endif // SERDESERSISTEM_H
