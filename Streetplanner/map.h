#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <city.h>
#include <street.h>
#include <abstractmap.h>
#include <sstream>

class Map : public AbstractMap
{
public:
    void addCity(City*);
    void addCity(QString cityname, int x, int y);
    bool addStreet(Street*);
    void addStreet(QString origin, QString target);
    void draw(QGraphicsScene& scene);
    City* findCity(const QString cityName) const;
    QVector<Street*> getStreetList(const City* city) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    QVector<City*> getCityList();
    void clear();


private:
    QList<City*> cities;
    QList<Street*> streets;

};

#endif // MAP_H
