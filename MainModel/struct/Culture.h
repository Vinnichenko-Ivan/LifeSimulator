#ifndef CULTURE_H
#define CULTURE_H
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
        std::string nameOfCulture;
        QColor color;
        QPixmap pixmap;
    public:
        Culture(QColor colorIn)
        {
            pixmap = QPixmap(creature_xpm);
            QPainter * painter = new QPainter(&pixmap);
            painter->setPen(QPen(colorIn, 0, Qt::SolidLine, Qt::FlatCap));
            painter->setBrush(QBrush(colorIn, Qt::SolidPattern));
            painter->drawPoint(5,1);
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
