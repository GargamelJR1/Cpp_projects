#pragma once
#include "czas_pracy_pracownika.h"
#include "wydajnosc_pracy_pracownika.h"

/**
* Klasa zawiera dane dotycz�ce pracy pracownika i metody do ich obs�ugi.
*/
class praca : public czas_pracy_pracownika, public wydajnosc_pracy_pracownika
{
	double stawka_std;
	double stawka_dod;
	czas_pracy* cpptr = nullptr;

public:

	/**
	* Konstruktor domy�lny, inicjalizuje pola obiektu warto�ci� 0.
	*/
	praca() : stawka_std(0), stawka_dod(0) {};

	/*praca& operator=(const praca& p) {
		stawka_std = p.stawka_std;
		stawka_dod = p.stawka_dod;
		cpptr = p.cpptr;

	}*/


	/** Funkcja wy�wietla czas pracy, w okre�lonym okresie
	* @param nr_id numer identyfikatora pracownika
	* @param dzien_tyg_mies_rocz czas dzienny, tygodniowy, miesi�czny lub roczny
	* @param _miesiac numer miesi�ca
	* @param _tydzien numer tygodnia
	* @param _dzien numer dnia
	*/
	void wyswietl_czas(int nr_id, int dzien_tyg_mies_rocz, int _miesiac = 0, int _tydzien = 0, int _dzien = 0);

	/**
	* Funkcja oblicza i zwraca warto�� wynagrodzenia.
	* @return wynagrodzenie miesi�czne
	*/
	double oblicz_wynagrodzenie(int tydzien_miesiac_rok);

	/**
	* Funkcja ustawia p�ace za godziny standardowe i dodatkowe.
	* @param plnperhstd p�aca za godziny standardowe
	* @param plnperhdod p�aca za godziny dodatkowe
	*/
	void set_stawka_za_prace(double plnperhstd, double plnperhdod) {
		stawka_std = plnperhstd;
		stawka_dod = plnperhdod;
	}

	/**
	* Funkcja zwraca p�ace godzinowe standardow� i dodatkow� w postaci tuple.
	* @return p�aca godzinowa standardowa, dodatkowa
	*/
	tuple<double, double> get_stawki_godzinowe() const {
		return make_tuple(stawka_std, stawka_dod);
	}
};

