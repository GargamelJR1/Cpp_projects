#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>

using namespace std;

/** Funkcja sprawdza czy istnieje plik o podanej nazwie
* @param sciezkain sciezka do wczytanego pliku lub jego nazwa
* @return true, je�li plik istnieje, false, gdy nie istnieje
*/
bool czy_istnieje_plik(const string& sciezkain);

/** Funkcja pobiera od u�ytkownika liczbe double
* @return podana liczba
*/
double wczytaj_liczbe_double_dodatnia();

/** Funkcja pobiera od u�ytkownika liczbe int
* @return podana liczba
*/
int wczytaj_liczbe_int_dodatnia();

/** Funkcja pobiera od u�ytkownika liczbe int z zakresu parametr�w przes�anych do niej
* @param min minimalna liczba
* @param max maksymalna liczba
* @return podana liczba
*/
int wczytaj_liczbe_int_z_zakresu(int min, int max);

/** Funkcja usuwa znaki z ca�ej linii wpisanej przez u�ytkownika, jest u�ywana do zapobiegni�cia wczytaniu dodatkowych znak�w przez cin.
*/
void czysc_wczytywanie();

/** Funkcja wypisuje komunikat o nieprawid�owych danych oraz czy�ci cin, jest wykorzystywana w cia�ach p�tli funkcji wczytuj�cych liczby.
*/
void wczytywanie_srodek_petli();

/** Funkcja sprawdza, czy liczba znajduje si� w zakresie mi�dzy minimum, a maksimum
* @param min minimum zakresu
* @param max maksimum zakresu
* @param liczba liczba do sprawdzenia
* @return (1), je�li liczba jest w zakresie, (0), je�li jest poza zakresem
*/
bool czy_lezy_w_zakrese(int min, int max, int liczba);

/**
* Klasa, kt�rej obiekty s� wykorzystywane jako obiekty funkcyjne do zamienianie liter na wielki.
*/
class wielkia_litera {
public:
	/** Operator (), zwraca du�� liter�, odpowiadaj�c� argumentowi
	* @param c ma�a litera do zamiany
	* @return du�a litera
	*/
	char operator()(const char& c) {
		return toupper(c);
	}
};

/** Funkcja pomocnicza, wykorzystywana w algorytmie accumulate
* @param sum obecna suma
* @param t para double i int, w kt�rej int jest ilo�ci� warto�ci double
* @return suma (t.first * t.second + sum)
*/
double doAcc_pair_double(double sum, const pair<double, int>& t);

