#pragma once
#include "czas_pracy_dzienny.h"
#include "czas_pracy_tygodniowy.h"
#include "czas_pracy_miesieczny.h"
#include "czas_pracy_roczny.h"
#include "funkcje.h"
#include <array>

/**
* Klasa zawiera dane dotycz¹ce czasu pracy pracownika z podzia³em na okresy czasu i metody do ich obs³ugi.
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
	* @return (1) jeœli uda siê ustawiæ czas pracy lub (0), jeœli siê nie uda
	*/
	bool set_czas_pracy(int czas_std, int czas_dod);

	/**
	* Funkcja ustawia czas pracy w wybranym okresie czasu.
	* @param czas_std przepracowany czas pracy standardowy
	* @param czas_dod przepracowany czas pracy dodatkowy
	* @param dzien_tydzien_miesiac_rok dzien / tydzieñ / miesi¹c / rok
	* @param wybor numer wybranego dnia / tygodnia / miesi¹ca
	*/
	void set_czas_pracy_wybrany(int czas_std, int czas_dod, int dzien_tydzien_miesiac_rok, int wybor = 1);

	/**
	* Funkcja zwraca wartoœci zwi¹zane z obiektem klasy czas_pracy w wybranym okresie czasu jako postaci tuple.
	* @param dzien_tydzien_miesiac_rok dzien / tydzieñ / miesi¹c / rok
	* @param wybor numer wybranego dnia / tygodnia / miesi¹ca
	* @return czas pracy standardowy, dodatkowy, dni, œredni czas pracy
	*/
	tuple<int, int, double> get_czas_pracy_wybrany(int dzien_tydzien_miesiac_rok, int wybor = 1);

	/**
	* Funkcja zwiêksza iloœæ standardowych przepracowanych godzin.
	* @param zm_czas liczba o jak¹ powiêkszana jest iloœæ przepracowanych godzin standardowych
	* @return (1) jeœli uda siê zwiêkszyæ czas pracy standardowy lub (0), jeœli siê nie uda
	*/
	bool zwieksz_czas_pracy_std(int zw_czas);

	/**
	* Funkcja zmniejsza iloœæ standardowych przepracowanych godzin.
	* @param zm_czas liczba o jak¹ pomniejszana jest iloœæ przepracowanych godzin standardowych
	* @return (1) jeœli uda siê zmniejszyæ czas pracy standardowy lub (0), jeœli siê nie uda
	*/
	bool zmniejsz_czas_pracy_std(int zm_czas);

	/**
	* Funkcja zwiêksza dodatkowy czas pracy o podan¹ iloœæ godzin.
	* @param zw_czas_d iloœæ godzin dodatkowych do dodania
	* @return (1) jeœli uda siê zwiêkszyæ czas pracy dodatkowy lub (0), jeœli siê nie uda
	*/
	bool zwieksz_czas_pracy_dod(int zw_czas_d);

	/**
	* Funkcja zwraca wartoœci zwi¹zane z obiektem klasy czas_pracy w obecnym okresie czasu jako postaci tuple.
	* @param dzien_tydzien_miesiac_rok dzien / tydzieñ / miesi¹c / rok
	* @return czas pracy standardowy, dodatkowy, œredni czas pracy
	*/
	tuple<int, int, double> get_czas_pracy(int dzien_tydzien_miesiac_rok);

	/**
	* Funkcja ustawia obecny dzieñ.
	* @param _dzien dzieñ do ustawienia
	*/
	void set_dzien(int _dzien) {
		dzien = _dzien;
	}

	/**
	* Funkcja ustawia obecny tydzieñ.
	* @param _tydzien tydzieñ do ustawienia
	*/
	void set_tydzien(int _tydzien) {
		tydzien = _tydzien;
	}

	/**
	* Funkcja ustawia obecny miesi¹c.
	* @param _miesiac miesi¹c do ustawienia
	*/
	void set_miesiac(int _miesiac) {
		miesiac = _miesiac;
	}
};

