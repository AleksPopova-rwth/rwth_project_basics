/*
 * DVD.cpp
 *
 *  Created on: 25 июн. 2024 г.
 *      Author: alexp
 */

#include "DVD.h"
#include <iostream>

//DVD::DVD() {
//	// TODO Auto-generated constructor stub
//
//}

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
: Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre) {}

void DVD::ausgabe() const
{
    Medium::ausgabe(); // Aufruf der ausgabe() Funktion der Basisklasse
    std::cout << "Altersfreigabe: " << altersfreigabe << std::endl;
    std::cout << "Genre: " << genre << std::endl;
}
DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	Datum neueZeit;
    // Überprüfung der Altersfreigabe
    if (neueZeit - person.getGeburtsdatum() < altersfreigabe)
    {
        std::cout << "Die DVD \"" << getTitel() << "\" kann nicht ausgeliehen werden, da die Altersfreigabe nicht erfüllt ist!" << std::endl;
        return false;
    }

    // Wenn die Altersfreigabe erfüllt ist, rufen wir die Basisklassenfunktion auf
    return Medium::ausleihen(person, ausleihdatum);
}
