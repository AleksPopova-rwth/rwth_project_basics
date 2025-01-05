/*
 * Magazin.cpp
 *
 *  Created on: 25 июн. 2024 г.
 *      Author: alexp
 */

#include "Magazin.h"
#include <iostream>
//Magazin::Magazin() {
//	// TODO Auto-generated constructor stub
//
//}
/**
 * @file Magazin.cpp
 *
 * @brief Implementation of methods..
 */

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
: Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte) {}

void Magazin::ausgabe() const
{
    Medium::ausgabe(); // Aufruf der ausgabe() Funktion der Basisklasse
    std::cout << "Erscheinungsdatum: " << datumAusgabe << std::endl;
    std::cout << "Sparte: " << sparte << std::endl;
}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub


}
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    // Berechnung der Anzahl der Monate zwischen dem Ausleihdatum und dem Erscheinungsdatum
    int monateDifferenz = ausleihdatum - datumAusgabe;

    // Wenn es sich um die neueste Ausgabe handelt
    if (monateDifferenz < 1) {
        std::cout << "Das Magazin \"" << getTitel() << "\" ist die neueste Ausgabe und kann nicht ausgeliehen werden!" << std::endl;
        return false;
    }

    // Wenn es nicht die neueste Ausgabe ist, rufen wir die Basisklassenfunktion auf
    return Medium::ausleihen(person, ausleihdatum);
}
