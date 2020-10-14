#ifndef CORDINATE_H
#define CORDINATE_H
#include "../../../FileSystemUtilits/Serialise.h"
#include "../../../FileSystemUtilits/Deserialise.h"
struct Cordinate: public Serialise,
        public Deserialise
{
    Cordinate(double xIn=0,double yIn=0)
    {
        x=xIn;
        y=yIn;
    }
    double x,y;
    double angle;
    virtual QJsonObject serialise() override
    {
        QJsonObject  obj = QJsonObject();
        obj.insert("type","cordinates");
        obj.insert("x",x);
        obj.insert("y",y);
        obj.insert("angle",angle);
        return obj;
    }
    virtual bool desirialise (QJsonObject & document) override
    {
        if(document.take("type").toString().toStdString()!="cordinates")
        {
            qDebug()<<"NOT CORD";
            return 0;
        }
        x=document.take("x").toDouble();
        y=document.take("y").toDouble();
        angle=document.take("angle").toDouble();
        return 1;
    }
};
#endif // CORDINATE_H
