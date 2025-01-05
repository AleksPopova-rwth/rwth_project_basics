/**
 * @file Person.h
 * 
 * @brief Declaration of the Person class and its related functionality.
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Datum.h"
#include <string>

/**
 * @brief Class representing a person.
 *
 * This class stores all relevant information about a person that is relevant for the library,
 * including:
 *  - Name
 *  - Date of birth
 */
class Person
{
public:
	/**
     * @brief Constructor for the Person class.
     *
     * @param initName The name of the person. Default is an empty string.
     * @param initGeburtsdatum The date of birth of the person. Default is the current date.
     */
    Person(std::string initName = "", Datum initGeburtsdatum = Datum());

    /**
     * @brief Destructor for the Person class.
     */
    ~Person();

    /**
     * @brief Accessor function to retrieve the name of the person.
     *
     * @return std::string The name of the person.
     */
    std::string getName() const;

    /**
     * @brief Accessor function to retrieve the date of birth of the person.
     *
     * @return Datum The date of birth of the person.
     */
    Datum getGeburtsdatum() const;

private:
    std::string name;       /**< Name of the person. */
    Datum geburtsdatum;     /**< Date of birth of the person. */
};

#endif /* PERSON_H_ */
