/** @mainpage
 *
 * Praktikum Informatik 1 MMXXVI <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include<fstream>
#include <string>
#include <vector>

#include "Student.h"

int main()
{
    std::vector<Student> studentenListe;
    std::vector<Student>::iterator studentenListeIterator;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl //--
				  << "(5): Datenelement loeschen" << std::endl
				  << "(6): Datenelement vorne hinzufuegen" << std::endl
				  << "(7): Datenelement vorne loeschen" << std::endl
				  << "(8): Daten aus einer Datei einlesen" << std::endl
				  << "(9): Daten in eine Datei sichern" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                    	studentenListeIterator = studentenListe.begin();
                        student = *studentenListeIterator;
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for(std::vector<Student>::iterator it = studentenListe.begin(); it != studentenListe.end(); it++)
                    {
                    	it->ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            case '4': //--
            	if(!studentenListe.empty())
                {
            		std::cout << "Inhalt der Liste in umgekehrter Reihenfolge Reihenfolge:" << std::endl;
            		for(std::vector<Student>::reverse_iterator it = studentenListe.rbegin(); it != studentenListe.rend(); it++)
            		{
            			it->ausgabe();
            		}
                }
                else
                {
                	std::cout << "Die Liste ist leer!\n\n";
                }
            	break;
            case '5':
            	{
            		unsigned int matNr;
            		std::cout << "Geben Sie die Matrikelnummer, die dem Student gehoert." << std::endl;
            		std::cin >> matNr;

            		if(studentenListe.empty())
            		{
            			std::cout << "Die Liste ist leer!\n\n";
            		}
            		else
            		{
            			for(std::vector<Student>::iterator it = studentenListe.begin(); it != studentenListe.end();)
            			{
            				if(it->getMatNr() == matNr)
            				{
            					studentenListe.erase(it);
            				}
            				else
            				{
            					it++;
            				}
            			}
            		}
        		}
            	break;

            case '6':
            	{
            		unsigned int matNr = 0;
            		std::string name = "";
            		std::string geburtstag = "";
            		std::string adresse = "";

            		std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
            		getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

            		std::cout << "Geburtsdatum: ";
            		getline(std::cin, geburtstag);

            		std::cout << "Adresse: ";
            		getline(std::cin, adresse);

            		std::cout << "Matrikelnummer: ";
            		std::cin >> matNr;
            		std::cin.ignore(10, '\n');

            		student = Student(matNr, name, geburtstag, adresse);

            		studentenListeIterator = studentenListe.begin();
            		studentenListe.insert(studentenListeIterator, student);
            	}
            	break;
            case '7':
                {
                    if(!studentenListe.empty())
                    {
                    	studentenListeIterator = studentenListe.begin();
                        student = *studentenListeIterator;
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;
            case '8':
            	{
            		std::string dateiName = "";

            		std::cout << "Aus welcher Datei sollte die Daten eingelesen werden?\n";
            		getline(std::cin ,dateiName);

            		std::cout << "Einlesen beginnt.\n";

            		std::ifstream datei(dateiName);
            		std::string matNrStr = "";
            		std::string name = "";
            		std::string geburtstag = "";
            		std::string adresse = "";

            		studentenListe.clear();

            		while(getline(datei, matNrStr, ','))
            		{
            			getline(datei, name, ',');
            			getline(datei, geburtstag, ',');
            			getline(datei, adresse);

            			unsigned int matNr = std::stoi(matNrStr);
            			student = Student(matNr, name, geburtstag, adresse);

            			studentenListe.push_back(student);
            		}

            		std::cout << "Einlesen war erfolgreich.\n";
            	}
            	break;
            case '9':
            	{
            		std::string dateiName = "";

            		std::cout << "In welche Datei sollten di Daten gesichert werden?\n";
            		getline(std::cin, dateiName);

            		std::cout << "Datei wird gesichert.";

            		unsigned int matNr = 0;
            		std::string name = "";
            		std::string geburtstag = "";
            		std::string adresse = "";

            		std::ofstream ausgabe(dateiName);

            		for(std::vector<Student>::iterator it = studentenListe.begin(); it != studentenListe.end(); it++)
            		{
            			matNr = it->getMatNr();
            			name = it->getName();
            			geburtstag = it->getGeburtstag();
            			adresse = it->getAdresse();

            			ausgabe << matNr << "," << name << "," << geburtstag << "," << adresse << std::endl;
            		}

            		ausgabe.close();
            	}
            	break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}























