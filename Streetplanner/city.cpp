#include "city.h"

/*
City::~City()
{

}*/

City::City(QString name, int x, int y)
    : name(name), x(x), y(y)
{

}

/**
 * @brief Draws the city to a given scene.
 * Draws a light circle at the given coordinates and puts text next to it.
 * @param QGraphicsScene& scene you want the city drawn to
 */

void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(x,y,10,10,QPen(QColor(215,215,215,255)), QBrush(QColor(215,215,215,255), Qt::SolidPattern));
    QGraphicsTextItem* descriptionName = new QGraphicsTextItem;
    descriptionName->setPos(x+10,y-8);
    descriptionName->setPlainText(name);
    descriptionName->setFont(QFont(".AppleSystemUIFont", 14, 600));
    scene.addItem(descriptionName);
    QString debug = "City '%1' drawn at %2,%3";
    qDebug() << debug.arg(name).arg(x).arg(y);
}


