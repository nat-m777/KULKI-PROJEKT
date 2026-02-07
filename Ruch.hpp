#ifndef RUCH_HPP
#define RUCH_HPP

#include <string>


using namespace std;

class Plansza;
class ObslugaGry;

/**
 * @class Ruch
 * @brief Abstrakcyjna klasa bazowa dla wszystkich typów ruchów
 *
 * Definiuje interfejs wspólny dla wszystkich rodzajów ruchów w grze.
 * Wymaga implementacji metody WykonajRuch() w klasach pochodnych.
 * Wykorzystuje polimorfizm do ujednolicenia obs³ugi ró¿nych typów ruchów.
 */

class Ruch {

public:

    virtual void WykonajRuch(Plansza& tab, ObslugaGry* gra) = 0;
    virtual ~Ruch() = default;

};

#endif
