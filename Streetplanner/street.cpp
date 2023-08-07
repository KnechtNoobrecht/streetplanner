#include "street.h"

Street::Street(City* origin, City* target, QString color) : origin(origin), target(target), color(color)
{

}

/**
 * @brief Draws a street to the given scene.
 * @param Scene you want the street drawn to.
 */
void Street::draw(QGraphicsScene& scene)
{
    if(color == "red")
        scene.addLine(origin->x+5, origin->y+5, target->x+5, target->y+5, QPen(QColor(249,44,71,255), 2));
    else
        scene.addLine(origin->x+5, origin->y+5, target->x+5, target->y+5, QPen(QColor(138,138,138,255), 2));
}

/**
 * @brief Draws a street to the given scene in red.
 * @param Scene you want the street drawn to.
 */
/*
void Street::drawRed(QGraphicsScene& scene)
{
    scene.addLine(origin->x+5, origin->y+5, target->x+5, target->y+5, QPen(QColor(29,44,71,255), 2));
}*/
