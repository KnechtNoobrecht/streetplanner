#include "map.h"
#include "city.h"
#include "bigtown.h"


/**
 * @brief Adds the given city to the map.
 * @param City* city you want to add to the map.
 */
void Map::addCity(City* city)
{
    cities.append(city);
    qDebug() << "Added " << city->name<< " to the Map.";
}


/**
 * @brief Convenience function of Map::addCity(City* city). Adds the given city to the map.
 * @param QString cityname: City name
 * @param int x: X-Coordinate of the city
 * @param int y: Y-Coordinate of the city
 */
void Map::addCity(QString cityname, int x, int y)
{
    cities.append(new City(cityname, x,y));
    qDebug() << "Added " << cityname<< " to the Map.";
}

/**
 * @brief Adds a given street to the map.
 * @param Street* street: Street you want to add to the map.
 * @return true: if successful, false: if unsuccessful
 */
bool Map::addStreet(Street* street)
{
    int foundBothCities = 0;
    for(City* city : cities)
    {
        if(city->name == street->origin->name || city->name == street->target->name)
            foundBothCities += 1;
    }
    if(foundBothCities == 2)
    {
        streets.append(street);
        return true;
    }
    qDebug() << street->origin->name << " oder " << street->target->name << " ist nicht in der Karte verzeichnet. Keine Straße hinzugefügt.";
    return false;
}


/**
 * @brief Adds a given street to the map by origin and target city name.
 * @param QString originStreet: Name of the origin city
 * @param QString targetStreet: Name of the target city
 */
void Map::addStreet(QString originStreet, QString targetStreet)
{
    City *originCity = nullptr;
    City *targetCity = nullptr;
    for(City* city : cities)
        if(city->name == originStreet)
            originCity = city;
        else if(city->name == targetStreet)
            targetCity = city;
    if(originCity != nullptr && targetCity != nullptr)
    {
        Street *street = new Street(originCity, targetCity);
        streets.append(street);
    }
}


/**
 * @brief Draws the content of the map to a given QGraphicsScene& scene.
 * @param QGraphiscene& scene that is drawn to.
 * Draws streets first, then cities, so cities are drawn on top of streets, which looks better.
 */
void Map::draw(QGraphicsScene& scene)
{
    scene.clear();
    for(Street* street : streets)
    {
        street->draw(scene);
    }
    for(City* city : cities)
    {
        city->draw(scene);
    }

}


/**
 * @brief Searches for cities by name in the map.
 * @param QString cityName: Name of the city you want to search for
 * @return pointer to the city if it is found, nullptr if not.
 */
City* Map::findCity(const QString cityName) const
{
    for(City* city : cities)
    {
        if(city->name == cityName)
            return city;
    }
    qDebug() << "findCity(): City" << cityName << "was not found.";
    return nullptr;
}


/**
 * @brief Returns a QVector<Street*> of all the streets connected to a given city.
 * @param city name of the city you want all the connected streets from
 * @return QVector<Street*> streetList: List of all the streets connected to a given city.
 */
QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> streetList;
    for(Street* street : streets)
    {
        if(street->origin->name == city->name || street->target->name == city->name)
            streetList.append(street);
    }
    return streetList;
}


/**
 * @brief Returns the opposite city of a given street connected to a given city.
 * @param street that is between both cities
 * @param city that is connected to the street you want to opposite of
 * @return pointer to the opposite city
 */
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if(street->origin->name == city->name)
        return street->target;
    else if(street->target->name == city->name)
        return street->origin;
    else
        return nullptr;
}


/**
 * @brief Returns the length of a given street
 * @param street you want the length of
 * @return double: length of the given street
 */
double Map::getLength(const Street* street) const
{
    return sqrt( pow((street->target->x - street->origin->x), 2) + pow((street->target->y - street->origin->y), 2) );
}

/**
 * @brief Returns a QVector<City*> of all the cities in the map
 * @return QVector<City*>
 */
QVector<City*> Map::getCityList()
{
    QVector<City*> cityList;
    for(City* city : cities)
    {
        cityList.append(city);
    }
    return cityList;
}

/**
 * @brief Removes all entries from the map
 */
void Map::clear()
{
    cities.clear();
    cities.shrink_to_fit();
    streets.clear();
    streets.shrink_to_fit();
}
