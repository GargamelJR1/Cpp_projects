#pragma once
#include "czas_pracy_dzienny.h"
#include "czas_pracy_tygodniowy.h"
#include "czas_pracy_miesieczny.h"
#include "czas_pracy_roczny.h"
#include "funkcje.h"
#include <array>

/**
* Klasa zawiera dane dotycz�ce czasu pracy pracownika z podzia�em na okresy czasu i metody do ich obs�ugi.
*/
class czas_pracy_pracownika
{
protected:
	std::array<czas_pracy_dzienny, 365> czas_dzienny;
	std::array<czas_pracy_tygodniowy, 53> czas_tygodniowy;
	std::array<czas_pracy_miesieczny, 12> czas_miesieczny;
	czas_pracy_roczny czas_roczny;
	int miesiac = 1;
	int tydzien = 1;
	int dzien = 1;

public:
	/**
	* Funkcja ustawia czas pracy.
	* @param czas_std przepracowany czas pracy standardowy
	* @param czas_dod przepracowany czas pracy dodatkowy
	* @return (1) je�li uda si� ustawi� czas pracy lub (0), je�li si� nie uda
	*/
	bool set_czas_pracy(int czas_std, int czas_dod);

	/**
	* Funkcja ustawia czas pracy w wybranym okresie czasu.
	* @param czas_std przepracowany czas pracy standardowy
	* @param czas_dod przepracowany czas pracy dodatkowy
	* @param dzien_tydzien_miesiac_rok dzien / tydzie� / miesi�c / rok
	* @param wybor numer wybranego dnia / tygodnia / miesi�ca
	*/
	void set_czas_pracy_wybrany(int czas_std, int czas_dod, int dzien_tydzien_miesiac_rok, int wybor = 1);

	/**
	* Funkcja zwraca warto�ci zwi�zane z obiektem klasy czas_pracy w wybranym okresie czasu jako postaci tuple.
	* @param dzien_tydzien_miesiac_rok dzien / tydzie� / miesi�c / rok
	* @param wybor numer wybranego dnia / tygodnia / miesi�ca
	* @return czas pracy standardowy, dodatkowy, dni, �redni czas pracy
	*/
	tuple<int, int, double> get_czas_pracy_wybrany(int dzien_tydzien_miesiac_rok, int wybor = 1);

	/**
	* Funkcja zwi�ksza ilo�� standardowych przepracowanych godzin.
	* @param zm_czas liczba o jak� powi�kszana jest ilo�� przepracowanych godzin standardowych
	* @return (1) je�li uda si� zwi�kszy� czas pracy standardowy lub (0), je�li si� nie uda
	*/
	bool zwieksz_czas_pracy_std(int zw_czas);

	/**
	* Funkcja zmniejsza ilo�� standardowych przepracowanych godzin.
	* @param zm_czas liczba o jak� pomniejszana jest ilo�� przepracowanych godzin standardowych
	* @return (1) je�li uda si� zmniejszy� czas pracy standardowy lub (0), je�li si� nie uda
	*/
	bool zmniejsz_czas_pracy_std(int zm_czas);

	/**
	* Funkcja zwi�ksza dodatkowy czas pracy o podan� ilo�� godzin.
	* @param zw_czas_d ilo�� godzin dodatkowych do dodania
	* @return (1) je�li uda si� zwi�kszy� czas pracy dodatkowy lub (0), je�li si� nie uda
	*/
	bool zwieksz_czas_pracy_dod(int zw_czas_d);

	/**
	* Funkcja zwraca warto�ci zwi�zane z obiektem klasy czas_pracy w obecnym okresie czasu jako postaci tuple.
	* @param dzien_tydzien_miesiac_rok dzien / tydzie� / miesi�c / rok
	* @return czas pracy standardowy, dodatkowy, �redni czas pracy
	*/
	tuple<int, int, double> get_czas_pracy(int dzien_tydzien_miesiac_rok);

	/**
	* Funkcja ustawia obecny dzie�.
	* @param _dzien dzie� do ustawienia
	*/
	void set_dzien(int _dzien) {
		dzien = _dzien;
	}

	/**
	* Funkcja ustawia obecny tydzie�.
	* @param _tydzien tydzie� do ustawienia
	*/
	void set_tydzien(int _tydzien) {
		tydzien = _tydzien;
	}

	/**
	* Funkcja ustawia obecny miesi�c.
	* @param _miesiac miesi�c do ustawienia
	*/
	void set_miesiac(int _miesiac) {
		miesiac = _miesiac;
	}
};

