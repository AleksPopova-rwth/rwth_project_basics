#ifndef STREET_H
#define STREET_H
#include <QGraphicsEllipseItem>
#include <cmath>

#include <QGraphicsScene>
#include <QPointer>
#include "city.h"
/**
 * @brief The Street class represents a street connecting two cities.
 *  The Street class models a street that connects two cities. It provides
 *  methods to draw the street on a QGraphicsScene, retrieve the cities
 *  it connects, and calculate its length.
 */
class Street
{
public:
    /**
     * @brief Constructor.
     *  Constructs a Street connecting two cities.
     *
     *  @param city1 Pointer to the first city.
     *  @param city2 Pointer to the second city.
     */
    Street(City* city1, City* city2);
    /**
     * @brief Draws the street on a QGraphicsScene.
     *  Draws the street on the provided QGraphicsScene.
     *
     *  @param scene Reference to the QGraphicsScene where the street will be drawn.
     */
    void draw(QGraphicsScene& scene) const;
    /**
     * @brief Gets the first city.
     *  Returns a pointer to the first city connected by the street.
     *
     *  @return Pointer to the first city.
     */
    City* getCity1() const;
    /**
     *  @brief Gets the second city.
     *  Returns a pointer to the second city connected by the street.
     *
     *  @return Pointer to the second city.
     */
    City* getCity2() const;
    /**
     * @brief Gets the length of the street.
     *  Returns the length of the street, calculated as the distance
     *  between the two cities.
     *
     *  @return Length of the street.
     */
    double getLength() const;
    /**
     * @brief Draws the street in red on a QGraphicsScene.
     *  Draws the street in red on the provided QGraphicsScene.
     *
     *  @param scene Reference to the QGraphicsScene where the street will be drawn in red.
     */
    void drawRed(QGraphicsScene& scene);


private:
    City* city1;
    City* city2;
    double length;

};

#endif // STREET_H
