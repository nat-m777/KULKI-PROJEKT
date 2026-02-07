#ifndef BAZADANYCH_HPP
#define BAZADANYCH_HPP

#include <fstream>
#include <sstream>
#include <string>

class ObslugaGry;

using namespace std;

/**
 * @class BazaDanych
 * @brief Zarz¹dza trwa³ym przechowywaniem stanu gry
 *
 * Odpowiada za zapis i odczyt stanu gry do/z plików tekstowych.
 * Wspó³pracuje z klas¹ ObslugaGry poprzez wzorzec strategii.
 */

class BazaDanych {
private:
    string plikZDanymi;
    ObslugaGry* daneZGry;

public:
    //konstruktor
    BazaDanych();

    // Settery
    void setDaneZGry(ObslugaGry* gra);
    void setPlikZDanymi(const string& nazwa);

    // Gettery
    ObslugaGry* getDaneZGry();
    string getPlikZDanymi() const;

    // Operacje na danych
    void zapiszStanGry(ObslugaGry* przekazanaGra);
    void odczytaj(string nickOdUzytkownika);
};

#endif