#ifndef MAP_H
#define MAP_H

#include <QGraphicsScene>
#include <QVector>
#include <QPointer>
#include "city.h"
#include "abstractmap.h"
#include "street.h"
#include <QObject>
/**
 * @brief The Map class represents a map that contains cities and streets.
 * It inherits from the AbstractMap class and provides implementations
 * for its virtual methods.
 */
class Map : public AbstractMap
{
public:
    /**
     *  @brief Constructs a new Map object.
    */
    Map();
    /** @brief Destroys the Map object.
    */
    ~Map();

    // Überschreiben Sie die abstrakten Methoden der Basis-Klasse
    /** @brief Adds a city to the map.
     *
     * @param city The city to be added.
     */
    void addCity(City* city) override;
    /**
     *  @brief Draws the map on the given QGraphicsScene.
     *
     * @param scene The QGraphicsScene to draw the map on.
     */
    void draw(QGraphicsScene& scene);
    /**
     *  @brief Adds a street to the map.
     *
     * @param street The street to be added.
     * @return true if the street was added successfully.
     * @return false if the street could not be added.
     */
    bool addStreet(Street* street ) override;
    /**
     * @brief Finds a city by its name.
     *
     * @param cityName The name of the city to find.
     * @return A pointer to the city if found, otherwise nullptr.
     */
    virtual City* findCity(const QString cityName) const override;
    /**
     * @brief Gets a list of streets connected to a given city.
     *
     * @param city The city for which to get the street list.
     * @return A QVector of pointers to streets connected to the city.
     */
    virtual QVector<Street*> getStreetList(const City* city) const override;

    /**
     * @brief Gets the city on the opposite end of a given street from a given city.
     *
     * @param street The street to check.
     * @param city The city from which to find the opposite city.
     * @return A pointer to the opposite city.
     */
    virtual City* getOppositeCity(const Street* street, const City* city) const override;
    /**
     * @brief Gets the length of a given street.
     *
     * @param street The street for which to get the length.
     * @return The length of the street.
     */
    virtual double getLength(const Street* street) const override;

private:
    QVector<City*> cities;
    QVector<Street*> streets;
    QGraphicsScene* scene;


};

#endif // MAP_H
