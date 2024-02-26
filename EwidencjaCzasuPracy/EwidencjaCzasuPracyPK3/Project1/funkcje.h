#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>

using namespace std;

/** Funkcja sprawdza czy istnieje plik o podanej nazwie
* @param sciezkain sciezka do wczytanego pliku lub jego nazwa
* @return true, jeœli plik istnieje, false, gdy nie istnieje
*/
bool czy_istnieje_plik(const string& sciezkain);

/** Funkcja pobiera od u¿ytkownika liczbe double
* @return podana liczba
*/
double wczytaj_liczbe_double_dodatnia();

/** Funkcja pobiera od u¿ytkownika liczbe int
* @return podana liczba
*/
int wczytaj_liczbe_int_dodatnia();

/** Funkcja pobiera od u¿ytkownika liczbe int z zakresu parametrów przes³anych do niej
* @param min minimalna liczba
* @param max maksymalna liczba
* @return podana liczba
*/
int wczytaj_liczbe_int_z_zakresu(int min, int max);

/** Funkcja usuwa znaki z ca³ej linii wpisanej przez u¿ytkownika, jest u¿ywana do zapobiegniêcia wczytaniu dodatkowych znaków przez cin.
*/
void czysc_wczytywanie();

/** Funkcja wypisuje komunikat o nieprawid³owych danych oraz czyœci cin, jest wykorzystywana w cia³ach pêtli funkcji wczytuj¹cych liczby.
*/
void wczytywanie_srodek_petli();

/** Funkcja sprawdza, czy liczba znajduje siê w zakresie miêdzy minimum, a maksimum
* @param min minimum zakresu
* @param max maksimum zakresu
* @param liczba liczba do sprawdzenia
* @return (1), jeœli liczba jest w zakresie, (0), jeœli jest poza zakresem
*/
bool czy_lezy_w_zakrese(int min, int max, int liczba);

/**
* Klasa, której obiekty s¹ wykorzystywane jako obiekty funkcyjne do zamienianie liter na wielki.
*/
class wielkia_litera {
public:
	/** Operator (), zwraca du¿¹ literê, odpowiadaj¹c¹ argumentowi
	* @param c ma³a litera do zamiany
	* @return du¿a litera
	*/
	char operator()(const char& c) {
		return toupper(c);
	}
};

/** Funkcja pomocnicza, wykorzystywana w algorytmie accumulate
* @param sum obecna suma
* @param t para double i int, w której int jest iloœci¹ wartoœci double
* @return suma (t.first * t.second + sum)
*/
double doAcc_pair_double(double sum, const pair<double, int>& t);

