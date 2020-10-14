#include "SerDeserSistem.h"

SerDeserSistem::SerDeserSistem(MainModel* modelIn,QObject *parent) : QObject(parent)
{
    model=modelIn;
}

void SerDeserSistem::saveAll()
{
    qDebug()<<"ISaveAll";
    QFileDialog saver;
           saveFileName= saver.getSaveFileName(nullptr,
                                                            tr("Save Project Files"),
                                                            QString());
    QDir dir=saver.directory();
    qDebug()<<saveFileName;
    if(!dir.cd(saveFileName))
    {
        dir.mkdir(saveFileName);
    }
    QDir::setCurrent(dir.currentPath());
    saveCordinatesCreatures();
    saveCondithionsCreatures();
    saveCreatures();
    saveProFile();
}

void SerDeserSistem::saveCordinatesCreatures()
{
    QJsonArray cordinatesCreatures;
    for(auto n:model->cordinatesCreatures)
    {
        cordinatesCreatures.append(n->serialise());
    }
    QFile jsonFile(saveFileName+"/cordinatesCreatures.json");
    if(!jsonFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия для записи";
    }
    jsonFile.write(QJsonDocument(cordinatesCreatures).toJson(QJsonDocument::Indented));
    jsonFile.close();
}

void SerDeserSistem::saveCondithionsCreatures()
{
    QJsonArray condithionsCreatures;
    for(auto n:model->condithionsCreature)
    {
        condithionsCreatures.append(n->serialise());
    }
    QFile jsonFile(saveFileName+"/condithionsCreatures.json");
    if(!jsonFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия для записи";
    }
    jsonFile.write(QJsonDocument(condithionsCreatures).toJson(QJsonDocument::Indented));
    jsonFile.close();
}

void SerDeserSistem::saveCreatures()
{
    QJsonArray condithionsCreatures;
    for(auto n:model->creatures)
    {
        condithionsCreatures.append(n->serialise());
    }
    QFile jsonFile(saveFileName+"/creatures.json");
    if(!jsonFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия для записи";
    }
    jsonFile.write(QJsonDocument(condithionsCreatures).toJson(QJsonDocument::Indented));
    jsonFile.close();
}

void SerDeserSistem::saveProFile()
{
    QFile jsonFile(saveFileName+"/pro.pro");
    if(!jsonFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия для записи";
    }
    jsonFile.write("HI");
    jsonFile.close();
}

void SerDeserSistem::loadAndAddAll()
{
    QFileDialog loader;
    saveFileName= loader.getOpenFileName (nullptr,
                                                     tr("Save Project Files"),
                                                     QString());
    QDir dir=loader.directory();
    saveFileName.remove(saveFileName.size()-8,8);
    qDebug() << saveFileName+"/creatures.json";
    QFile creaturesFiles(saveFileName+"/creatures.json");
    QFile creaturesCondithionsFiles(saveFileName+"/condithionsCreatures.json");
    QFile creaturesCordinatesFiles(saveFileName+"/cordinatesCreatures.json");
    if (!creaturesFiles.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Project crashed!!! Permission?";
        return;
    }

    if (!creaturesCondithionsFiles.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Project crashed!!! Permission?";
        return;
    }

    if (!creaturesCordinatesFiles.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Project crashed!!! Permission?";
        return;
    }

    QByteArray creaturesFilesB = creaturesFiles.readAll();
    QByteArray creaturesCondithionsFilesB = creaturesCondithionsFiles.readAll();
    QByteArray creaturesCordinatesFilesB = creaturesCordinatesFiles.readAll();
    QJsonDocument creaturesJson(QJsonDocument::fromJson(creaturesFilesB));
    QJsonDocument creaturesCondithionsJson(QJsonDocument::fromJson(creaturesCondithionsFilesB));
    QJsonDocument creaturesCordinatesJson(QJsonDocument::fromJson(creaturesCordinatesFilesB));
    QJsonArray creaturesFilesArray = creaturesJson.array();
    QJsonArray creaturesCondithionsFilesArray = creaturesCondithionsJson.array();
    QJsonArray creaturesCordinatesFilesArray = creaturesCordinatesJson.array();
    if(creaturesFilesArray.size()!=creaturesCondithionsFilesArray.size()||creaturesCondithionsFilesArray.size()!=creaturesCordinatesFilesArray.size())
    {
        qDebug()<<"Project crashed!!!";
        return;
    }

    for(int i = 0; i < creaturesFilesArray.size(); i++)
    {
        QJsonObject creatures=creaturesFilesArray[i].toObject();
        QJsonObject cordinates=creaturesCordinatesFilesArray[i].toObject();
        QJsonObject condithions=creaturesCondithionsFilesArray[i].toObject();
        Cordinate * cordinate = new Cordinate();
        Condithions * condithion = new Condithions();
        Creature * creature;

        if(!cordinate->desirialise(cordinates))
        {
            qDebug()<<"error desirialise(cordinates)";
            return;
        }

        if(!condithion->desirialise(condithions))
        {
            qDebug()<<"error desirialise(condithions)";
            return;
        }

        int numberCulture=-1;
        QString buff = condithions.take("cultures").toString();
        for(int j = 0;j<model->cultures.size();j++)
        {
            if(QString::fromStdString( model->cultures[j]->getNameOfCulture())==buff)
            {
                numberCulture=j;
            }
            qDebug()<<QString::fromStdString( model->cultures[j]->getNameOfCulture())<<" "<<buff;
        }

        if(numberCulture==-1)
        {
            qDebug()<<"error numberCulture==-1";
            return;
        }
        else
        {
            creature = model->culturesCreatures[numberCulture]->copyForBehavior();
            condithion->culture = model->cultures[numberCulture];
        }

        if(!creature->desirialise(creatures))
        {
            qDebug()<<"error desirialise(creatures)";
            return;
        }
        model->addNewCreature(creature,cordinate,condithion);
    }
}

void SerDeserSistem::loadAndReplaceAll()
{
    model->clearCreatures();
    QFileDialog loader;
    saveFileName= loader.getOpenFileName (nullptr,
                                                     tr("Save Project Files"),
                                                     QString());
    QDir dir=loader.directory();
    saveFileName.remove(saveFileName.size()-8,8);
    qDebug() << saveFileName+"/creatures.json";
    QFile creaturesFiles(saveFileName+"/creatures.json");
    QFile creaturesCondithionsFiles(saveFileName+"/condithionsCreatures.json");
    QFile creaturesCordinatesFiles(saveFileName+"/cordinatesCreatures.json");
    if (!creaturesFiles.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Project crashed!!! Permission?";
        return;
    }

    if (!creaturesCondithionsFiles.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Project crashed!!! Permission?";
        return;
    }

    if (!creaturesCordinatesFiles.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Project crashed!!! Permission?";
        return;
    }

    QByteArray creaturesFilesB = creaturesFiles.readAll();
    QByteArray creaturesCondithionsFilesB = creaturesCondithionsFiles.readAll();
    QByteArray creaturesCordinatesFilesB = creaturesCordinatesFiles.readAll();
    QJsonDocument creaturesJson(QJsonDocument::fromJson(creaturesFilesB));
    QJsonDocument creaturesCondithionsJson(QJsonDocument::fromJson(creaturesCondithionsFilesB));
    QJsonDocument creaturesCordinatesJson(QJsonDocument::fromJson(creaturesCordinatesFilesB));
    QJsonArray creaturesFilesArray = creaturesJson.array();
    QJsonArray creaturesCondithionsFilesArray = creaturesCondithionsJson.array();
    QJsonArray creaturesCordinatesFilesArray = creaturesCordinatesJson.array();
    if(creaturesFilesArray.size()!=creaturesCondithionsFilesArray.size()||creaturesCondithionsFilesArray.size()!=creaturesCordinatesFilesArray.size())
    {
        qDebug()<<"Project crashed!!!";
        return;
    }

    for(int i = 0; i < creaturesFilesArray.size(); i++)
    {
        QJsonObject creatures=creaturesFilesArray[i].toObject();
        QJsonObject cordinates=creaturesCordinatesFilesArray[i].toObject();
        QJsonObject condithions=creaturesCondithionsFilesArray[i].toObject();
        Cordinate * cordinate = new Cordinate();
        Condithions * condithion = new Condithions();
        Creature * creature;

        if(!cordinate->desirialise(cordinates))
        {
            qDebug()<<"error desirialise(cordinates)";
            return;
        }

        if(!condithion->desirialise(condithions))
        {
            qDebug()<<"error desirialise(condithions)";
            return;
        }

        int numberCulture=-1;
        QString buff = condithions.take("cultures").toString();
        for(int j = 0;j<model->cultures.size();j++)
        {
            if(QString::fromStdString( model->cultures[j]->getNameOfCulture())==buff)
            {
                numberCulture=j;
            }
            qDebug()<<QString::fromStdString( model->cultures[j]->getNameOfCulture())<<" "<<buff;
        }

        if(numberCulture==-1)
        {
            qDebug()<<"error numberCulture==-1";
            return;
        }
        else
        {
            creature = model->culturesCreatures[numberCulture]->copyForBehavior();
            condithion->culture = model->cultures[numberCulture];
        }

        if(!creature->desirialise(creatures))
        {
            qDebug()<<"error desirialise(creatures)";
            return;
        }
        model->addNewCreature(creature,cordinate,condithion);
    }
}
