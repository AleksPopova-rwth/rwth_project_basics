/*
 * DVD.h
 *
 *  Created on: 25 июн. 2024 г.
 *      Author: alexp
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"
#include <string>

/**
 * @file DVD.h
 *
 * @brief Declaration of the DVD class, which represents a DVD.
 */

/**
 * @class DVD
 *
 * @brief Represents a DVD, inheriting from the Medium class.
 */
class DVD: public Medium
{
private:
    int altersfreigabe; ///< The age rating for the DVD.
    std::string genre; ///< The genre of the DVD.
public:
    /**
     * @brief Constructor for the DVD class.
     *
     * @param initTitel The title of the DVD.
     * @param initAltersfreigabe The age rating of the DVD.
     * @param initGenre The genre of the DVD.
     */
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

    /**
     * @brief Outputs information about the DVD.
     *
     * Overrides the ausgabe method from the Medium class to output
     * specific information about the DVD, including its title, age rating, and genre.
     */
    void ausgabe() const override;

    /**
     * @brief Overrides the ausleihen method to support DVD-specific borrowing logic.
     *
     * @param person The person who is borrowing the DVD.
     * @param ausleihdatum The date when the DVD is borrowed.
     * @return True if the DVD can be borrowed, false otherwise.
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

    /**
     * @brief Destructor for the DVD class.
     */
    virtual ~DVD();
};

#endif /* DVD_H_ */
