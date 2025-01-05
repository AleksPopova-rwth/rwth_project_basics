/*
 * Buch.h
 *
 *  Created on: 24 июн. 2024 г.
 *      Author: alexp
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"
/**
 * @file Buch.h
 *
 * @brief Declaration of the Buch class, which represents a book.
 */

/**
 * @class Buch
 *
 * @brief Represents a book, inheriting from the Medium class.
 */
class Buch: public Medium
{
public:
    /**
     * @brief Constructor for the Buch class.
     *
     * @param initTitel The title of the book.
     * @param initAuthor The author of the book.
     */
	Buch(std::string initTitel, std::string initAuthor);
    /**
     * @brief Destructor for the Buch class.
     */
	virtual ~Buch();

    /**
     * @brief Outputs information about the book.
     *
     * Overrides the ausgabe method from the Medium class to output
     * specific information about the book, including its title and author.
     */
	void ausgabe() const override;
private:
	std::string author;
};

#endif /* BUCH_H_ */
