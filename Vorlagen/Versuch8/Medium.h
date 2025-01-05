/*!
 * @file Medium.h
 * 
 * @brief Declaration of the Medium class and its related functionality.
 */

#ifndef MEDIUM_H_
#define MEDIUM_H_

#include "Datum.h"
#include "Person.h"

/**
 * @brief Base class for all types of media.
 *
 * This class serves as a base class for objects that describe various types of media,
 * such as books or DVDs.
 */
class Medium {
public:
	/**
     * @brief Constructor for the Medium class.
     *
     * @param initTitel The title of the medium.
     */
    Medium(std::string initTitel);

    /**
     * @brief Virtual destructor for the Medium class.
     */
    virtual ~Medium();

    /**
     * @brief Output function for displaying information about the medium.
     *
     * This function prints all information about the medium to the console.
     */
    virtual void ausgabe() const = 0;

    /**
     * @brief Function to borrow the medium.
     *
     * @param person The person who wants to borrow the medium.
     * @param ausleihdatum The date when the medium is borrowed.
     *
     * @return True if borrowing restrictions are met and the medium can be borrowed, false otherwise.
     */
    virtual bool ausleihen(Person person, Datum ausleihdatum);

    /**
     * @brief Function to return the medium to the library.
     */
    void zurueckgeben();

    /*!
     * @brief Function to retrieve the ID of the medium.
     *
     * @return The ID of the medium.
     */
    unsigned int getID();

protected:
    /**
     * @brief Static variable to generate unique IDs for each medium.
     */
    static unsigned int currentID;

    /**
     * @brief Unique ID of the medium.
     */
    unsigned int ID;

    /**
     * @brief Title of the medium.
     */
    std::string titel;

    /**
     * @brief Status of the medium (true: borrowed, false: not borrowed).
     */
    bool status;

    /**
     * @brief Date since the medium was borrowed.
     */
    Datum datumAusgeliehen;

    /**
     * @brief Person who borrowed the medium.
     */
    Person personAusgeliehen;

    /**
     * @brief Function to retrieve the title of the medium.
     *
     * @return The title of the medium.
     */
    std::string getTitel() const { return titel; }
};

#endif /* MEDIUM_H_ */
