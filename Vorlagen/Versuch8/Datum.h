/*!
 * @file Datum.h
 *
 * @brief Declaration of the Datum class and its related functionality.
 */

#ifndef DATUM_H_
#define DATUM_H_

#include <string>
#include <iostream>

/*!
 * @brief Class representing a date.
 *
 * This class stores a date consisting of day, month, and year.
 * The Datum class provides various functionalities/operators for outputting, editing, and comparing different dates.
 */
class Datum {
public:
    /*!
     * @brief Default constructor.
     *
     * Initializes the Datum class with today's date.
     */
    Datum();

    /*!
     * @brief Constructor for a specific date.
     *
     * @param initTag The given day.
     * @param initMonat The given month.
     * @param initJahr The given year.
     */
    Datum(int initTag, int initMonat, int initJahr);

    /*!
     * @brief Destructor for the Datum class.
     */
    ~Datum();

    /*!
     * @brief Input function for a date using an input stream.
     *
     * @param in The input stream for reading input.
     */
    void eingabe(std::istream& in);

    /*!
     * @brief Output function for a date using an output stream.
     *
     * @param out The output stream for writing output.
     */
    void ausgabe(std::ostream& out) const;

    /*!
     * @brief Assignment operator for Datum objects.
     *
     * @param d The Datum object on the right-hand side of the assignment.
     * @return Datum& Reference to the assigned Datum object.
     */
    Datum& operator=(Datum& d);

    /*!
     * @brief Subtraction operator for Datum objects.
     *
     * @param d The Datum object on the right-hand side.
     * @return int The difference between the two dates in months.
     */
    int operator-(const Datum d) const;

    /*!
     * @brief Addition operator for Datum objects.
     *
     * @param anzahlTage Number of days to add to the current date.
     * @return Datum The modified date after adding the specified number of days.
     */
    Datum operator+(const int anzahlTage) const;

private:
    int tag;        /*!< Day of the date. */
    int monat;      /*!< Month of the date. */
    int jahr;       /*!< Year of the date. */

    /*!
     * @brief Array containing the number of days in each month.
     */
    static const int tageMonat[12];
};

/*!
 * @brief Overload of the output stream operator for the Datum class.
 *
 * @param out The left-hand side output stream.
 * @param d The right-hand side Datum object to output.
 * @return std::ostream& Reference to the output stream where the date was written.
 */
std::ostream& operator<<(std::ostream& out, const Datum& d);

/*!
 * @brief Overload of the input stream operator for the Datum class.
 *
 * @param in The left-hand side input stream.
 * @param d The right-hand side Datum object to read into.
 * @return std::istream& Reference to the input stream where the date was read.
 */
std::istream& operator>>(std::istream& in, Datum& d);

#endif /* DATUM_H_ */
