#ifndef CULTURE_H
#define CULTURE_H
//#include "../entity/struct/Condithions.h"
//#include "../entity/Creature.h"
#include <string>
#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <QPalette>
#include <QImage>
#include <QtGui>
#include "../../GUI/texture/creature.xpm"

struct Culture
{
    protected:
        //Creature* creature;
        std::string nameOfCulture;
        QColor color;
        QPixmap pixmap;
    public:
        Culture(QColor colorIn,std::string nameOfCultureIn)//,Creature* creatureIn)
        {
            //creature=creatureIn;
            nameOfCulture=nameOfCultureIn;
            pixmap = QPixmap(creature_xpm);
            //qDebug()<< QPixmap(creature_xpm);
            QPainter * painter = new QPainter(&pixmap);
            painter->setPen(QPen(colorIn, 0, Qt::SolidLine, Qt::FlatCap));
            painter->setBrush(QBrush(colorIn, Qt::SolidPattern));
            painter->drawPoint(1,4);
            painter->drawPoint(2,4);
            painter->drawPoint(6,4);
            painter->drawPoint(7,4);

            painter->drawPoint(1,5);
            painter->drawPoint(2,5);
            painter->drawPoint(3,5);
            painter->drawPoint(4,5);
            painter->drawPoint(5,5);
            painter->drawPoint(6,5);
            painter->drawPoint(7,5);

            painter->drawPoint(1,6);
            painter->drawPoint(2,6);
            painter->drawPoint(3,6);
            painter->drawPoint(5,6);
            painter->drawPoint(6,6);
            painter->drawPoint(7,6);

            painter->drawPoint(1,7);
            painter->drawPoint(2,7);
            painter->drawPoint(3,7);
            painter->drawPoint(4,7);
            painter->drawPoint(5,7);
            painter->drawPoint(6,7);
            painter->drawPoint(7,7);

            painter->drawPoint(1,8);
            painter->drawPoint(2,8);
            painter->drawPoint(3,8);
            painter->drawPoint(4,8);
            painter->drawPoint(5,8);
            painter->drawPoint(6,8);
            painter->drawPoint(7,8);

            painter->drawPoint(2,9);
            painter->drawPoint(3,9);
            painter->drawPoint(4,9);
            painter->drawPoint(5,9);
            painter->drawPoint(6,9);

            painter->drawPoint(2,10);
            painter->drawPoint(3,10);
            painter->drawPoint(4,10);
            painter->drawPoint(5,10);
            painter->drawPoint(6,10);

            painter->drawPoint(3,11);
            painter->drawPoint(4,11);
            painter->drawPoint(5,11);
        }
        std::string getNameOfCulture()
        {
            return nameOfCulture;
        }
        QColor getColor()
        {
            return color;
        }
        QPixmap getPixmap()
        {
            return pixmap;
        }

};
#endif // CULTURE_H
