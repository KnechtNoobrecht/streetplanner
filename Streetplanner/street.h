#ifndef STREET_H
#define STREET_H

#include <QMainWindow>
#include <city.h>

class Street : public QMainWindow
{
public:
    Street(City*, City*, QString color = "");
    void draw(QGraphicsScene& scene);
    void drawRed(QGraphicsScene& scene);
    City* origin;
    City* target;
    QString color;
};

#endif // STREET_H
