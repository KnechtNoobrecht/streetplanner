#ifndef BIGTOWN_H
#define BIGTOWN_H

#include "city.h"

class BigTown : public City
{
public:
    BigTown(QString name, int x, int y);
    void draw(QGraphicsScene& scene);

    QString name;
    int x;
    int y;
};


#endif // BIGTOWN_H
