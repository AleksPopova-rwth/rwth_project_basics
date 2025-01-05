//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @file Student.h
 *
 * @brief Declaration of the Student class, representing a student.
 */

class Student
{
public:
    /**
     * @brief Default constructor for Student class.
     */
    Student();

    /**
     * @brief Constructor for Student class.
     *
     * @param matNr The matriculation number of the student.
     * @param name The name of the student.
     * @param geburtstag The birthdate of the student.
     * @param adresse The address of the student.
     */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse);

    /**
     * @brief Getter method for retrieving the matriculation number.
     *
     * @return The matriculation number of the student.
     */
    unsigned int getMatNr() const;

    /**
     * @brief Getter method for retrieving the name.
     *
     * @return The name of the student.
     */
    std::string getName() const;

    /**
     * @brief Getter method for retrieving the birthdate.
     *
     * @return The birthdate of the student.
     */
    std::string getGeburtstag() const;

    /**
     * @brief Getter method for retrieving the address.
     *
     * @return The address of the student.
     */
    std::string getAdresse() const;

    /**
     * @brief Prints the details of the student.
     *
     * This method prints out the details of the student,
     * including matriculation number, name, birthdate, and address.
     */
    void ausgabe() const;

    /**
     * @brief Setter method for setting the matriculation number.
     *
     * @param matNr The new matriculation number to set.
     */
    void setMatNr(unsigned int matNr);

    /**
     * @brief Setter method for setting the name.
     *
     * @param name The new name to set.
     */
    void setName(const std::string& name);

    /**
     * @brief Setter method for setting the birthdate.
     *
     * @param geburtstag The new birthdate to set.
     */
    void setGeburtstag(const std::string& geburtstag);

    /**
     * @brief Setter method for setting the address.
     *
     * @param adresse The new address to set.
     */
    void setAdresse(const std::string& adresse);

private:
    unsigned int matNr; ///< The matriculation number of the student.
    std::string name;   ///< The name of the student.
    std::string geburtstag; ///< The birthdate of the student.
    std::string adresse;    ///< The address of the student.
};

#endif /* STUDENT_H_ */
