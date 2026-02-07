#ifndef RUCHLOSOWY_HPP
#define RUCHLOSOWY_HPP

#include "Ruch.hpp"

using namespace std;

class Plansza;
class ObslugaGry;

/**
 * @class RuchLosowy
 * @brief Implementuje automatyczny ruch losowy
 *
 * Dziedziczy po klasie Ruch, generuje losowe parametry ruchu
 * i wykonuje go na planszy. U¿ywany gdy gracz wybiera opcjê
 * losowego ruchu.
 */
class RuchLosowy : public Ruch {
private:
    int x1, y1, x2, y2;
    void losowePoleStartoweIKoncowe(Plansza& tab);

public:
    void WykonajRuch(Plansza& tab, ObslugaGry* gra) override;
};

#endif