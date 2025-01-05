/*
 * Magazin.h
 *
 *  Created on: 25 июн. 2024 г.
 *      Author: alexp
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

/**
 * @file Magazin.h
 *
 * @brief Declaration of the Magazin class, which represents a magazine.
 */

/**
 * @class Magazin
 *
 * @brief Represents a magazine, inheriting from the Medium class.
 */
class Magazin: public Medium
{
private:
    Datum datumAusgabe; ///< The publication date of the magazine.
    std::string sparte; ///< The category or genre of the magazine.
public:
    /**
     * @brief Constructor for the Magazin class.
     *
     * @param initTitel The title of the magazine.
     * @param initDatumAusgabe The publication date of the magazine.
     * @param initSparte The category or genre of the magazine.
     */
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

    /**
     * @brief Outputs information about the magazine.
     *
     * Overrides the ausgabe method from the Medium class to output
     * specific information about the magazine, including its title,
     * publication date, and category.
     */
    void ausgabe() const override;

    /**
     * @brief Overrides the ausleihen method to support magazine-specific borrowing logic.
     *
     * @param person The person who is borrowing the magazine.
     * @param ausleihdatum The date when the magazine is borrowed.
     * @return True if the magazine can be borrowed, false otherwise.
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

    /**
     * @brief Destructor for the Magazin class.
     */
    virtual ~Magazin();
};

#endif /* MAGAZIN_H_ */
