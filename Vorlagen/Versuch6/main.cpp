/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 6: STL, vector
 *
 *
 */

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <algorithm>// für std::find_if
#include <fstream>

#include <iterator>// für std::reverse_iterator

/**
 * @brief Schreibt die Daten aus studentenListe in die angegebene Datei.
 * @file main.cpp
 */

/**
 * @brief Schreibt die Daten aus studentenListe in die angegebene Datei.
 *
 * @param studentenListe Die Liste der Studenten.
 * @param dateiname Der Name der Datei, in die geschrieben werden soll.
 */
void rewriteTextFile(const std::vector<Student>& studentenListe,  std::string& dateiname)
{
	std::ofstream ausgabe(dateiname, std::ios::trunc); // Open file in truncation mode (clear contents)

	if (ausgabe.is_open())
	{
		for (const auto& student : studentenListe)
		{
			ausgabe << student.getMatNr() << '\n';
			ausgabe << student.getName() << '\n';
			ausgabe << student.getGeburtstag() << '\n';
			ausgabe << student.getAdresse() << '\n';
		}
		std::cout << "Datei erfolgreich neu geschrieben." << std::endl;
		ausgabe.close(); // Close the file after writing
	}
	else
	{
		std::cerr << "Fehler beim Oeffnen der Datei " << dateiname << std::endl;
	}
}

/**
 * @brief Fügt ein Datenelement am Ende der studentenListe hinzu.
 *
 * Benutzer wird zur Eingabe von Name, Geburtsdatum, Adresse und Matrikelnummer aufgefordert.
 * Das neue Datenelement wird auch in die Datei geschrieben.
 *
 * @param studentenListe Die Liste der Studenten.
 */
void datenelementHintenHinzufuegen(std::vector<Student>& studentenListe)
{
	unsigned int matNr = 0;
	std::string name = "";
	std::string geburtstag = "";
	std::string adresse = "";

	std::cout << "Bitte geben Sie die Daten fuer den Studenten ein." << std::endl;
	std::cout << "Name: ";
	getline(std::cin, name);
	std::cout  << std::endl;
	std::cout << "Geburtsdatum: ";
	getline(std::cin, geburtstag);
	std::cout <<std::endl;
	std::cout << "Adresse: ";
	getline(std::cin, adresse);
	std::cout <<std::endl;
	std::cout << "Matrikelnummer: ";
	std::cin >> matNr;
	std::cin.ignore(10, '\n'); // Puffer leeren
	// Erstellen des Studenten-Objekts
	Student student;
	studentenListe.push_back(student);

}
/**
 * @brief Löscht das letzte Datenelement aus der studentenListe.
 *
 * @param studentenListe Die Liste der Studenten.
 */
void datenelementHintenLoeschen(std::vector<Student>& studentenListe)
{
	// Check if studentenListe is not empty before attempting to delete the last student
	if (!studentenListe.empty())
	{
		// Get a reference to the last student in studentenListe
		Student& lastStudent = studentenListe.back();
		// Print message indicating the last student is being deleted
		std::cout << "Student mit Matrikelnummer " << lastStudent.getMatNr() << " wird gelöscht." << std::endl;
		// Remove the last student from the list
		studentenListe.pop_back();
		// Return true to indicate successful deletion
	}
	else
	{
		// Print error message if studentenListe is empty
		std::cerr << "Liste ist leer. Keine Studenten vorhanden." << std::endl;

		// Return false to indicate no students were found (because list is empty)
		exit(1);
	}

}

/**
 * @brief Löscht das erste Datenelement aus der Datei und gibt es aus.
 *
 * @param dateiname Der Name der Datei, aus der gelesen und gelöscht wird.
 */
void datenelementVorneLoeschen(std::vector<Student>& studentenListe)
{
	// Überprüfen, ob die studentenListe nicht leer ist, bevor versucht wird, den ersten Studenten zu löschen
	if (!studentenListe.empty())
	{
		// Eine Referenz auf den ersten Studenten in der studentenListe erhalten
		Student& firstStudent = studentenListe.front();
		// Nachricht ausgeben, dass der erste Student gelöscht wird
		std::cout << "Student mit Matrikelnummer " << firstStudent.getMatNr() << " wird gelöscht." << std::endl;
		// Den ersten Studenten aus der Liste entfernen
		studentenListe.erase(studentenListe.begin());
	} else
	{
		// Fehlermeldung ausgeben, wenn die studentenListe leer ist
		std::cerr << "Liste ist leer. Keine Studenten vorhanden." << std::endl;
		// Programm mit Fehlercode beenden
		exit(1);
	}

}

/**
 * @brief Liest Daten aus der angegebenen Datei in die studentenListe ein.
 *
 * @param studentenListe Die Liste der Studenten, in die die Daten eingelesen werden.
 * @param dateiname Der Name der Datei, aus der gelesen wird.
 */
void datenEinlesen(std::vector<Student>& studentenListe,  std::string& dateiname)
{
	studentenListe.clear(); // Clear the vector before populating it
	std::ifstream eingabe(dateiname, std::ios::in);

	unsigned int matNr = 0;
	std::string name = "";
	std::string geburtsdatum = "";
	std::string adresse = "";
	if (!eingabe) {
		std::cerr << "Fehler beim Oeffnen der Datei " << dateiname << "!" << std::endl;
		throw std::runtime_error("Datei konnte nicht geöffnet werden.");
	}

	while (!eingabe.eof()) {
		eingabe >> matNr;
		eingabe.ignore(10, '\n'); // Ignore the newline character after matNr
		if (!std::getline(eingabe, name))
		{

			std::cerr << "Fehler beim Lesen des Namens für Matrikelnummer " << matNr << std::endl;
			break; // Exit loop if unable to read name
		}
		if (!std::getline(eingabe, geburtsdatum))
		{
			std::cerr << "Fehler beim Lesen des Geburtsdatums für Matrikelnummer " << matNr << std::endl;
			break; // Exit loop if unable to read birthdate
		}
		if (!std::getline(eingabe, adresse))
		{
			std::cerr << "Fehler beim Lesen der Adresse für Matrikelnummer " << matNr << std::endl;
			break; // Exit loop if unable to read address
		}

		studentenListe.push_back(Student(matNr, name, geburtsdatum, adresse));
	}


	if (eingabe.eof())
	{
		std::cout << "Daten erfolgreich eingelesen." << std::endl;
	} else if (eingabe.fail())
	{
		std::cerr << "Fehler beim Lesen der Datei " << dateiname << "." << std::endl;
	}

	eingabe.close();
}
/**
 * @brief Fügt ein Datenelement am Anfang der studentenListe hinzu.
 *
 * @param newStudent Das neue Studentenobjekt, das hinzugefügt werden soll.
 * @param studentenListe Die Liste der Studenten.
 */
void datenVorneHinzufuegen(const Student& newStudent, std::vector<Student>& studentenListe)
{

	// Insert new data at the beginning of the vector
	studentenListe.insert(studentenListe.begin(), newStudent);

}
/**
 * @brief Gibt die gesamte studentenListe aus.
 *
 * @param studentenListe Die Liste der Studenten, die ausgegeben werden soll.
 */
void datenbankAusgeben(std::vector<Student>& studentenListe)
{
	std::cout << "Datenausgabe:" << std::endl;

	for ( auto& student : studentenListe)
	{
		student.ausgabe();
		std::cout<< '\n';// Utilize the ausgabe method of the Student class to print student details
	}
	std::cout << "Ende der Datenbank." << std::endl;
}
/**
 * @brief Speichert die Daten aus studenten in die angegebene Datei.
 *
 * @param studenten Die Liste der Studenten, deren Daten gespeichert werden sollen.
 * @param dateiname Der Name der Datei, in die gespeichert werden soll.
 */
void datenSpeichern(const std::vector<Student>& studenten, const std::string& dateiname)
{
	std::ofstream ausgabe(dateiname); // Open file for writing
	if (!ausgabe)
	{
		std::cerr << "Fehler beim Oeffnen der Datei " << dateiname << " zum Schreiben." << std::endl;
		return;
	}

	for (const auto& student : studenten)
	{
		ausgabe << student.getMatNr() << std::endl;
		ausgabe << student.getName() << std::endl;
		ausgabe << student.getGeburtstag() << std::endl;
		ausgabe << student.getAdresse() << std::endl;
	}

	ausgabe.close(); // Close the file
	std::cout << "Daten erfolgreich in " << dateiname << " gespeichert." << std::endl;
}
/**
 * @brief Fügt ein Datenelement an der angegebenen Position in studenten ein.
 *
 * @param studenten Die Liste der Studenten.
 * @param student Das neue Studentenobjekt, das eingefügt werden soll.
 * @param position Die Position, an der das Datenelement eingefügt werden soll.
 */
void datenEinfuegen(std::vector<Student>& studenten, const Student& student, size_t position)
{
	if (position <= studenten.size()) {
		studenten.insert(studenten.begin() + position, student);
	}
	else
	{
		std::cerr << "Ungültige Position!" << std::endl;
	}
}
/**
 * @brief Löscht das Datenelement mit der angegebenen Matrikelnummer aus studenten.
 *
 * @param studenten Die Liste der Studenten.
 * @param matNr Die Matrikelnummer des zu löschenden Studenten.
 */
void datenLoeschen(std::vector<Student>& studenten, int matNr )
{
	auto it = std::find_if(studenten.begin(), studenten.end(), [matNr](const Student& student) { return student.getMatNr() == matNr; });

	if (it != studenten.end())
	{
		studenten.erase(it);
		std::cout << "Student mit Matrikelnummer " << matNr << " wurde gelöscht." << std::endl;

	}
	else
	{
		std::cerr << "Student mit Matrikelnummer " << matNr << " nicht gefunden." << std::endl;
		exit(1);
	}
}
/**
 * @brief Gibt die Datenbank in umgekehrter Reihenfolge aus.
 *
 * @param studentenListe Die Liste der Studenten, die in umgekehrter Reihenfolge ausgegeben werden soll.
 */
void datenbankInUmgekehrterReihenfolgeAusgeben(std::vector<Student>& studenten)
{
	std::cout << "Datenbankausgabe in umgekehrter Reihenfolge:" << std::endl;
	for (auto it = studenten.rbegin(); it != studenten.rend(); ++it) {
		it->ausgabe(); // Utilize the ausgabe method of the Student class to print student details
	}
	std::cout << "Ende der umgekehrten Datenbank." << std::endl;
}

int main()
{
	std::vector<Student> studentenListe;
	Student student;

	std::string dateiname;
	std::cout << "Bitte geben Sie den Namen der Datei ein: ";
	std::cin >> dateiname;
	std::cin.ignore(1, '\n');
	//datenEinlesen(studentenListe, dateiname);

	// Ausgabe der eingelesenen Daten
	char abfrage;

	do
	{
		std::cout << "\nMenue:" << std::endl
				<< "-----------------------------" << std::endl
				<< "(1): Datenelement im Zwischenspeicher hinten hinzufuegen\n"
				<< "(2): Datenelement im Zwischenspeicher hinten loeschen\n"
				<< "(3): Datenelement im Zwischenspeicher vorne loeschen\n"
				<< "(4): Datenelement im Zwischenspeicher vorne hinzufuegen\n"
				<< "(5): Daten aus einer Datei einlesen\n"
				<< "(6): Datenbank im Zwischenspeicher  ausgeben\n"
				<< "(7): Daten in umgekehrter Reihenfolge aus dem Zwischenspeicher ausgeben\n"
				<< "(8): Datenelement im Zwischenspeicher  loeschen\n"
				<< "(9): Datenelement im Zwischenspeicher  hinzufuegen\n"
				<< "(A): Daten in Datei sichern\n"
				<< "(0): Beenden\n";
		std::cin >> abfrage;
		std::cin.ignore(10, '\n');

		switch (abfrage)
		{
		// Datenelement hinten hinzufuegen
		case '1':
		{

			datenelementHintenHinzufuegen(studentenListe);
			datenbankAusgeben(studentenListe);
			break;
		}


		// Datenelement hinten entfernen
		case '2':
		{
			datenelementHintenLoeschen(studentenListe);
			datenbankAusgeben(studentenListe);
			break;
		}

		// Datenbank vorwaerts ausgeben
		case '3':
		{
			datenelementVorneLoeschen(studentenListe);
			datenbankAusgeben(studentenListe);
			break;

		}

		case '4':
		{
			int matNr = 0;
			std::string name = "";
			std::string geburtsdatum = "";
			std::string adresse = "";

			std::cout << "Geben Sie den Matrikelnummer von neuer Person: ";
			std::cin >> matNr;
			std::cout<<std::endl;
			std::cout << "Geben Sie den Namen von neuer Person: ";
			std::cin >> name;
			std::cout<<std::endl;
			std::cout << "Geben Sie den Geburtsdatum von neuer Person: ";
			std::cin >> geburtsdatum;
			std::cout<<std::endl;
			std::cout << "Geben Sie die Adresse von neuer Person: ";
			std::cin >> adresse;
			std::cout<<std::endl;

			Student student(matNr, name, geburtsdatum, adresse);

			datenVorneHinzufuegen(student, studentenListe);
			datenbankAusgeben(studentenListe);
			break;

		}

		case '5':
		{
			datenEinlesen(studentenListe, dateiname);
			break;
		}



		case '6':
		{
			datenbankAusgeben(studentenListe);
			break;
		}

		case '7':
		{
			datenbankInUmgekehrterReihenfolgeAusgeben(studentenListe);
			//datenbankAusgeben(studentenListe);

			break;
		}

		case '8':
		{

			int matNr=0;
			std::cout << "Geben Sie den Matrikelnummer von der Person: ";
			std::cin >> matNr;
			std::cout<<std::endl;
			datenLoeschen(studentenListe, matNr);
			datenbankAusgeben(studentenListe);
			break;
		}

		case '9':
		{
			int matNr = 0;
			std::string name = "";
			std::string geburtsdatum = "";
			std::string adresse = "";
			size_t position;
			std::cout << "Geben Sie den Matrikelnummer von neuer Person: ";
			std::cin >> matNr;
			std::cout<<std::endl;
			std::cout << "Geben Sie den Namen von neuer Person: ";
			std::cin >> name;
			std::cout<<std::endl;
			std::cout << "Geben Sie den Geburtsdatum von neuer Person: ";
			std::cin >> geburtsdatum;
			std::cout<<std::endl;
			std::cout << "Geben Sie die Adresse von neuer Person: ";
			std::cin >> adresse;
			std::cout<<std::endl;
			std::cout << "Geben Sie die Position in der Liste: ";
			std::cin >> position;
			std::cout<<std::endl;

			Student student(matNr, name, geburtsdatum, adresse);
			datenEinfuegen(studentenListe, student, position);
			datenbankAusgeben(studentenListe);

			break;
		}


		case 'A':
		{
			datenSpeichern(studentenListe, dateiname);
			break;
		}


		case '0':
		{
			std::cout << "Das Programm wird nun beendet";
			studentenListe.clear();
			break;
		}

		default :
		{
			std::cout << "Falsche Eingabe, bitte nochmal";
			break;
		}


		}
	}
	while (abfrage != '0');
	return 0;


}


