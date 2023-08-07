#ifndef CITY_H
#define CITY_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDebug>

class City : public QMainWindow
{
    Q_OBJECT
public:
    City(QString name, int x, int y);
    //~City();
    void draw(QGraphicsScene& scene);
    QString name;
    int x;
    int y;
private:

signals:

};

#endif // CITY_H
