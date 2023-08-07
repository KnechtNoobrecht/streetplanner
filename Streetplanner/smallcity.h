#ifndef City_H
#define City_H

#include "city.h"

class City : public City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene& scene);

    QString name;
    int x;
    int y;
};

#endif // City_H
