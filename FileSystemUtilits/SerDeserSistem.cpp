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
    saveFood();
    saveFoodCord();
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
    loadCreatures();
    loadFood();
}

void SerDeserSistem::loadAndReplaceAll()
{
    QFileDialog loader;
    saveFileName= loader.getOpenFileName (nullptr,
                                                     tr("Save Project Files"),
                                                     QString());
    saveFileName.remove(saveFileName.size()-8,8);
    model->clearCreatures();
    model->clearFood();
    loadCreatures();
    loadFood();
}

void SerDeserSistem::saveFood()
{
    QJsonArray food;
    for(auto n:model->foods)
    {
        food.append(n->serialise());
    }
    QFile jsonFile(saveFileName+"/food.json");
    if(!jsonFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия для записи";
    }
    jsonFile.write(QJsonDocument(food).toJson(QJsonDocument::Indented));
    jsonFile.close();
}

void SerDeserSistem::saveFoodCord()
{
    QJsonArray foodCord;
    for(auto n:model->cordinatesFoods)
    {
        foodCord.append(n->serialise());
    }
    QFile jsonFile(saveFileName+"/foodCordinates.json");
    if(!jsonFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ошибка открытия для записи";
    }
    jsonFile.write(QJsonDocument(foodCord).toJson(QJsonDocument::Indented));
    jsonFile.close();
}

void SerDeserSistem::loadFood()
{
    qDebug() << saveFileName+"/food.json";
    QFile foodsFiles(saveFileName+"/food.json");
    QFile foodsCordFiles(saveFileName+"/foodCordinates.json");
    if (!foodsCordFiles.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Project crashed!!! Permission?";
        return;
    }

    if (!foodsFiles.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Project crashed!!! Permission?";
        return;
    }

    QByteArray foodsFilesB = foodsFiles.readAll();
    QByteArray foodsCordinatesFilesB = foodsCordFiles.readAll();
    QJsonDocument foodsJson(QJsonDocument::fromJson(foodsFilesB));
    QJsonDocument foodsCordinatesJson(QJsonDocument::fromJson(foodsCordinatesFilesB));
    QJsonArray foodsFilesArray = foodsJson.array();
    QJsonArray foodsCordinatesFilesArray = foodsCordinatesJson.array();

    if(foodsFilesArray.size()!=foodsCordinatesFilesArray.size())
    {
        qDebug()<<"Project crashed!!!";
        return;
    }

    for(int i = 0; i < foodsFilesArray.size(); i++)
    {
        QJsonObject foods=foodsFilesArray[i].toObject();
        QJsonObject cordinates=foodsCordinatesFilesArray[i].toObject();
        Cordinate * cordinate = new Cordinate();
        Food * food = new Food(0);

        if(!cordinate->desirialise(cordinates))
        {
            qDebug()<<"error desirialise(cordinates)";
            return;
        }

        if(!food->desirialise(foods))
        {
            qDebug()<<"error desirialise(food)";
            return;
        }
        model->addNewFood(food,cordinate);
    }
}

void SerDeserSistem::loadCreatures()
{
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
