//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"
/**
 * @file Student.cpp
 * @brief Implementierung der Klasse Student, die einen Studenten repräsentiert.
 */


Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }


Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }


unsigned int Student::getMatNr() const
{
    return matNr;
}


std::string Student::getName() const
{
    return name;
}


std::string Student::getGeburtstag() const
{
    return geburtstag;
}


std::string Student::getAdresse() const
{
    return adresse;
}


bool Student::operator<(const Student& other) const
{
    return matNr < other.matNr;
}

bool Student::operator>(const Student& other) const
{
    return matNr > other.matNr;
}

bool Student::operator==(const Student& other) const
		{
    return matNr == other.matNr;
}
std::ostream& Student::ausgabe(std::ostream& out) const
{
    out << name << '\n'
        << "MatNr. " << matNr << '\n'
        << "geb. am " << geburtstag << '\n'
        << "wohnhaft in " << adresse << '\n';
    return out;
}

//std::ostream& operator<<(std::ostream& out, const Student& student) {
//    student.ausgabe(out);
//    return out;
//}
// Setter methods implementation
void Student::setMatNr(unsigned int matNr)
{
    this->matNr = matNr;
}

void Student::setName(const std::string& name)
{
    this->name = name;
}

void Student::setGeburtstag(const std::string& geburtstag)
{
    this->geburtstag = geburtstag;
}

void Student::setAdresse(const std::string& adresse)
{
    this->adresse = adresse;
}
