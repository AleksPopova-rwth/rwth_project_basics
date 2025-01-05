#include "map.h"
#include <QDebug>

Map::Map()
{
}

Map::~Map()
{
    qDeleteAll(cities);
    qDeleteAll(streets);
}

void Map::addCity(City* city)
{
    if (city) {
        cities.append(city);
        qDebug() << "City added:" << city->getName();
    }
}


void Map::draw(QGraphicsScene& scene)
{
    for (City* city : cities) {
        if (city) {
            city->draw(scene);
        }
    }

    for (Street* street : streets) {
        if (street)
        {
            street->draw(scene);
        }
    }
}

bool Map::addStreet(Street* street)
{
    if (street && cities.contains(street->getCity1()) && cities.contains(street->getCity2())) {
        streets.append(street);
        qDebug() << "Street added between:" << street->getCity1()->getName() << " and " << street->getCity2()->getName();
        return true;
    } else {
        qDebug() << "Cannot add street, one or both cities not in map";
        return false;
    }
}




City* Map::findCity(const QString cityName) const
{
    for (City* city : cities) {
        if (city->getName() == cityName) {
            return city;
        }
    }
    qDebug() << "City not found:" << cityName;
    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> streetList;
    for (Street* street : streets) {
        if (street->getCity1() == city || street->getCity2() == city) {
            streetList.append(street);
        }
    }
    return streetList;
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getCity1() == city) {
        return street->getCity2();
    } else if (street->getCity2() == city) {
        return street->getCity1();
    }
    return nullptr;
}

double Map::getLength(const Street* street) const
{
    return street->getLength();
}
