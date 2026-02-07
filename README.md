# Projekt Semestralny: Gra Kulki

Interaktywna gra logiczna zrealizowana w języku C++ w ramach zaliczenia przedmiotu. Projekt koncentruje się na zastosowaniu zaawansowanych technik programowania obiektowego.

## Realizacja Wymagań Projektowych

Projekt implementuje następujące techniki obiektowe:

1. **Kapsułkowanie**: Pola klas (np. w klasie `Kulka` czy `Plansza`) są prywatne, a dostęp do nich odbywa się przez publiczne metody typu getter/setter.
2. **Dziedziczenie**: Zastosowano hierarchię klas dla logiki ruchów. Klasy `RuchGracza` oraz `RuchLosowy` dziedziczą po klasie bazowej `Ruch`.
3. **Lista inicjalizatorów konstruktora**: Wykorzystana w konstruktorach do efektywnego przypisywania wartości początkowych polom klas.
4. **Polimorfizm**: Realizowany poprzez wirtualne metody w klasie bazowej `Ruch` i wywoływany przez wskaźnik typu bazowego w klasie `ObslugaGry`.
5. **Strumienie (I/O)**: Wykorzystanie biblioteki `<fstream>` do obsługi zapisu i odczytu stanu gry z pliku tekstowego.
6. **Rozdzielenie kodu**: Logika programu jest podzielona na pliki nagłówkowe (`.hpp`) oraz pliki źródłowe (`.cpp`).

## Funkcjonalności
* Gra w trybie tekstowym sterowana z poziomu konsoli.
* Obsługa zapisu i wczytywania stanu gry (`zapis.txt`).
* Automatyczna kontrola poprawności wprowadzanych przez gracza danych.
* System komentarzy w kodzie dokumentujący działanie klas i metod.

## Kompilacja i Uruchomienie

### Wymagania
* Kompilator `clang++` lub `g++` (standard C++14).

### Instrukcja (macOS/Linux)
Aby skompilować wszystkie pliki projektu, użyj komendy:

clang++ -std=c++14 -g Kulka.cpp BazaDanych.cpp ObslugaGry.cpp Plansza.cpp RuchGracza.cpp RuchLosowy.cpp projekt_semestralny_Mucha.cpp -o GraKulki