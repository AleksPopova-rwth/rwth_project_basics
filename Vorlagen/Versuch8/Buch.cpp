/*
 * Buch.cpp
 *
 *  Created on: 24 июн. 2024 г.
 *      Author: alexp
 */

#include "Buch.h"
/**
 * @file Buch.cpp
 *
 * @brief Implementation of methods.
 */
Buch::Buch(std::string initTitel, std::string initAuthor) : Medium(initTitel), author(initAuthor)
{
	// TODO Auto-generated constructor stub

}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe() const
{
    Medium::ausgabe(); // Aufruf der ausgabe() Funktion der Basisklasse
    std::cout << "Autor: " << author << std::endl;
}
