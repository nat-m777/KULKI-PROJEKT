#ifndef RUCHGRACZA_HPP
#define RUCHGRACZA_HPP

#include "Ruch.hpp"
using namespace std;

class Plansza;
class ObslugaGry;


/**
 * @class RuchGracza
 * @brief Implementuje ruch wykonywany przez gracza
 *
 * Dziedziczy po klasie Ruch, obs³uguje interakcjê z u¿ytkownikiem
 * w celu okreœlenia parametrów ruchu i wykonuje go na planszy.
 */
class RuchGracza : public Ruch {
private:
    int x1, y1, x2, y2;
    void odczytPolaStartowegoIKoncowego();

public:
    void WykonajRuch(Plansza& tab, ObslugaGry* gra) override;
};

#endif