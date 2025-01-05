//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

/**
 * @file Student.h
 * @brief Deklaration der Klasse Student, die einen Studenten repräsentiert.
 */

/**
 * @class Student
 * @brief Repräsentiert einen Studenten mit Matrikelnummer, Name, Geburtstag und Adresse.
 */
class Student
{
public:
    /// @brief Standardkonstruktor.
    Student();

    /**
     * @brief Konstruktor mit Parametern.
     * @param matNr Matrikelnummer des Studenten.
     * @param name Name des Studenten.
     * @param geburtstag Geburtstag des Studenten.
     * @param address Adresse des Studenten.
     */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);

    /**
     * @brief Gibt die Matrikelnummer zurück.
     * @return Matrikelnummer des Studenten.
     */
    unsigned int getMatNr() const;

    /**
     * @brief Gibt den Namen zurück.
     * @return Name des Studenten.
     */
    std::string getName() const;

    /**
     * @brief Gibt den Geburtstag zurück.
     * @return Geburtstag des Studenten.
     */
    std::string getGeburtstag() const;

    /**
     * @brief Gibt die Adresse zurück.
     * @return Adresse des Studenten.
     */
    std::string getAdresse() const;

    /// @brief Gibt die Informationen des Studenten auf der Konsole aus.
    void ausgabe() const;

    /**
     * @brief Setzt die Matrikelnummer.
     * @param matNr Neue Matrikelnummer.
     */
    void setMatNr(unsigned int matNr);

    /**
     * @brief Setzt den Namen.
     * @param name Neuer Name.
     */
    void setName(const std::string& name);

    /**
     * @brief Setzt den Geburtstag.
     * @param geburtstag Neuer Geburtstag.
     */
    void setGeburtstag(const std::string& geburtstag);

    /**
     * @brief Setzt die Adresse.
     * @param adresse Neue Adresse.
     */
    void setAdresse(const std::string& adresse);

    /**
     * @brief Vergleichsoperator '<'.
     * @param other Ein anderer Student.
     * @return true, wenn die Matrikelnummer des aktuellen Studenten kleiner ist als die des anderen.
     */
    bool operator<(const Student& other) const;

    /**
     * @brief Vergleichsoperator '>'.
     * @param other Ein anderer Student.
     * @return true, wenn die Matrikelnummer des aktuellen Studenten größer ist als die des anderen.
     */
    bool operator>(const Student& other) const;

    /**
     * @brief Vergleichsoperator '=='.
     * @param other Ein anderer Student.
     * @return true, wenn die Matrikelnummer des aktuellen Studenten gleich der des anderen ist.
     */
    bool operator==(const Student& other) const;

    /**
     * @brief Ausgabeoperator.
     * @param out Ausgabestream.
     * @return Referenz auf den Ausgabestream.
     */
    std::ostream& ausgabe(std::ostream& out) const;

    /**
     * @brief Freundfunktion zur Überladung des Ausgabeoperators.
     * @param ausgabe Ausgabestream.
     * @param student Der auszugebende Student.
     * @return Referenz auf den Ausgabestream.
     */
    friend std::ostream& operator<<(std::ostream& ausgabe, const Student& student);

private:
    unsigned int matNr; ///< Matrikelnummer des Studenten.
    std::string name; ///< Name des Studenten.
    std::string geburtstag; ///< Geburtstag des Studenten.
    std::string adresse; ///< Adresse des Studenten.
};

inline std::ostream& operator<<(std::ostream &ausgabe, const Student &student) {
    return student.ausgabe(ausgabe);
}

#endif // STUDENT_H_
