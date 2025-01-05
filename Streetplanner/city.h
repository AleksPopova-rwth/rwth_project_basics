#ifndef CITY_H
#define CITY_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>

/**
 * @brief The City class represents a city with a name and coordinates.
 */

class City
{
public:
    /**
     * @brief Constructs a new City object.
     *
     * @param name The name of the city.
     * @param x The x-coordinate of the city.
     * @param y The y-coordinate of the city.
     */
    City(QString name, int x, int y);
    /**
     * @brief Draws the city on the given QGraphicsScene.
     *
     * @param scene The QGraphicsScene to draw the city on.
     */
    void draw(QGraphicsScene& scene);
    /**
     * @brief Gets the name of the city.
     *
     * @return The name of the city.
     */
    QString getName() const;
    /**
     * @brief Gets the x-coordinate of the city.
     *
     * @return The x-coordinate of the city.
     */
    int getX() const;
    /**
     * @brief Gets the y-coordinate of the city.
     *
     * @return The y-coordinate of the city.
     */
    int getY() const;

private:
    QString name;
    int x;
    int y;
};



#endif // CITY_H
