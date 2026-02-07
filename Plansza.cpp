#include "Plansza.hpp"
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

// Konstruktor - inicjalizuje plansz�, ustawiaj�c wszystkie pola na nullptr
Plansza::Plansza() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tablica[i][j] = nullptr;
        }
    }
}

// Destruktor - zwalnia pami�� usuwaj�c wszystkie kulki z planszy
Plansza::~Plansza() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            delete tablica[i][j];
        }
    }
}

// Zwraca wska�nik do kulki znajduj�cej si� na podanej pozycji (lub nullptr, je�li nie ma kulki)
Kulka* Plansza::getKulka(int x, int y) const {
    if (x < 0 || x >= N || y < 0 || y >= N) return nullptr;
    return tablica[x][y];
}

// Ustawia kulk� na podanej pozycji
void Plansza::setKulka(int x, int y, Kulka* k) {
    tablica[x][y] = k;
}

// Generuje losowo okre�lon� liczb� nowych kulek na pustych polach planszy
void Plansza::generujKulki(int ilosc) {
    int wolnePola = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablica[i][j] == nullptr) wolnePola++;
        }
    }

    if (wolnePola == 0) return;
    ilosc = min(ilosc, wolnePola);

    for (int k = 0; k < ilosc; k++) {
        int x, y;
        do {
            x = rand() % N;
            y = rand() % N;
        } while (tablica[x][y] != nullptr);

        Kolor kolor = static_cast<Kolor>(rand() % 7);
        tablica[x][y] = new Kulka(kolor);
        cout << "\nNowa kulka na polu: (" << x << ", " << y << ")\n";
    }
}

// Sprawdza czy istnieje �cie�ka pomi�dzy dwoma punktami planszy (algorytm BFS)
bool Plansza::istniejeSciezka(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= N ||
        x2 < 0 || x2 >= N || y2 < 0 || y2 >= N) {
        return false;
    }

    if (tablica[x1][y1] == nullptr || tablica[x2][y2] != nullptr)
        return false;

    bool odwiedzone[N][N] = { false };
    int kolejkaX[N * N], kolejkaY[N * N];
    int pocz = 0, kon = 0;

    kolejkaX[kon] = x1;
    kolejkaY[kon] = y1;
    kon++;
    odwiedzone[x1][y1] = true;

    const int dx[4] = { -1, 1, 0, 0 };
    const int dy[4] = { 0, 0, -1, 1 };

    while (pocz < kon) {
        int x = kolejkaX[pocz];
        int y = kolejkaY[pocz];
        pocz++;

        if (x == x2 && y == y2) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N &&
                !odwiedzone[nx][ny] && tablica[nx][ny] == nullptr) {
                odwiedzone[nx][ny] = true;
                kolejkaX[kon] = nx;
                kolejkaY[kon] = ny;
                kon++;
            }
        }
    }

    return false;
}

// Przesuwa kulk� z jednej pozycji na drug�, je�li istnieje �cie�ka
bool Plansza::przesun(int x1, int y1, int x2, int y2) {
    if (!istniejeSciezka(x1, y1, x2, y2)) return false;

    tablica[x2][y2] = tablica[x1][y1];
    tablica[x1][y1] = nullptr;
    return true;
}

// Usuwa kulki tworz�ce linie co najmniej 5 kulek tego samego koloru
int Plansza::usunKulki() {
    bool doUsuniecia[N][N] = { false };
    int usuniete = 0;

    auto sprawdzKierunek = [&](int x, int y, int dx, int dy) {
        Kolor aktualny = Kolor::Czerwony;
        int dlugosc = 1;
        int startX = x, startY = y;

        while (x >= 0 && y >= 0 && x < N && y < N) {
            if (tablica[x][y] != nullptr) {
                Kolor k = tablica[x][y]->getKolor();
                if (k == aktualny) {
                    dlugosc++;
                }
                else {
                    if (dlugosc >= 5) {
                        for (int i = 0; i < dlugosc; i++) {
                            doUsuniecia[startX + dx * i][startY + dy * i] = true;
                        }
                    }
                    aktualny = k;
                    dlugosc = 1;
                    startX = x;
                    startY = y;
                }
            }
            else {
                if (dlugosc >= 5) {
                    for (int i = 0; i < dlugosc; i++) {
                        doUsuniecia[startX + dx * i][startY + dy * i] = true;
                    }
                }
                dlugosc = 0;
            }
            x += dx;
            y += dy;
        }

        if (dlugosc >= 5) {
            for (int i = 0; i < dlugosc; i++) {
                doUsuniecia[startX + dx * i][startY + dy * i] = true;
            }
        }
        };

    // Sprawdzanie w czterech kierunkach: pionowo, poziomo, uko�nie
    for (int i = 0; i < N; i++) {
        sprawdzKierunek(0, i, 1, 0);   // Pionowo
        sprawdzKierunek(i, 0, 0, 1);   // Poziomo
        sprawdzKierunek(i, 0, 1, 1);   // Ukos  
        sprawdzKierunek(0, i, 1, 1);   // Ukos 
        sprawdzKierunek(i, N - 1, 1, -1); // Ukos /
        sprawdzKierunek(0, i, 1, -1);  // Ukos /
    }

    // Usuwanie zaznaczonych kulek
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (doUsuniecia[i][j]) {
                delete tablica[i][j];
                tablica[i][j] = nullptr;
                usuniete++;
            }
        }
    }

    return usuniete;
}

// Sprawdza, czy plansza jest ca�kowicie zape�niona
bool Plansza::czyPelna() const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablica[i][j] == nullptr) return false;
        }
    }
    return true;
}

// Wy�wietla plansz� w konsoli
void Plansza::wyswietl() {
    cout << "   ";
    for (int i = 0; i < N; i++) cout << i + 1 << " ";
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            if (tablica[j][i] == nullptr) {
                cout << ". ";
            }
            else {
                cout << tablica[j][i]->kolorNaZnak(tablica[j][i]->getKolor()) << " ";
            }
        }
        cout << endl;
    }
}

// Sprawdza, czy dane pole jest puste
bool Plansza::czyPuste(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return tablica[x][y] == nullptr;
}

// Odczytuje stan planszy z tekstu
void Plansza::odczytajZTekstu(const std::string& tekst) {
    if (tekst.size() != N * N) {
        cerr << "Niepoprawna dlugosc tekstu planszy!" << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            delete tablica[i][j];
            char c = tekst[i * N + j];
            if (c != '.') {
                tablica[i][j] = new Kulka(tablica[i][j]->znakNaKolor(c));
            }
            else {
                tablica[i][j] = nullptr;
            }
        }
    }
}

// Zapisuje stan planszy jako tekst
std::string Plansza::zapiszJakoTekst() const {
    string wynik;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablica[i][j] != nullptr) {
                wynik += tablica[i][j]->kolorNaZnak(tablica[i][j]->getKolor());
            }
            else {
                wynik += '.';
            }
        }
    }
    return wynik;
}
