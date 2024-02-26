#pragma once
#include "funkcje.h"

/**
* Klasa zawiera dane dotycz¹ce czasu pracy pracownika i metody do ich obs³ugi.
*/
class czas_pracy
{
	int standardowe_godziny;
	int dodatkowe_godziny;

protected:
	double sredni_czas_pracy;

public:

	/**
	* Konstruktor domyœlny, inicjalizuje pola obiektu wartoœci¹ 0.
	*/
	czas_pracy() :standardowe_godziny(0), dodatkowe_godziny(0), sredni_czas_pracy(0) { };

	/**
	* Konstruktor tworz¹cy nowy obiekt klasy z wartoœciami pocz¹tkowymi.
	* @param st przepracowany standardowy czas pracy
	* @param dod przepracowany dodatkowy czas pracy
	* @param dn przepracowane dni
	*/
	czas_pracy(int st, int dod, int dn) :standardowe_godziny(st), dodatkowe_godziny(dod), sredni_czas_pracy(0) { };

	/**
	* Operator dodawania, zwiêksza iloœæ standardowych przepracowanych godzin.
	* @param nowe_godziny liczba o jak¹ powiêkszana jest iloœæ przepracowanych godzin standardowych
	*/
	czas_pracy& operator+=(int nowe_godziny) {
		standardowe_godziny += nowe_godziny;
		return *this;
	}

	/**
	* Operator odejmowania, zmniejsza iloœæ standardowych przepracowanych godzin.
	* @param nowe_godziny liczba o jak¹ pomniejszana jest iloœæ przepracowanych godzin standardowych
	*/
	czas_pracy& operator-=(int nowe_godziny) {
		standardowe_godziny -= nowe_godziny;
		return *this;
	}

	/**
	* Funkcja zwraca iloœæ przepracowanych godzin standardowych.
	* @return standardowy czas pracy
	*/
	int get_czas_std() const {
		return standardowe_godziny;
	}

	/**
	* Funkcja zwraca iloœæ przepracowanych godzin dodatkowych.
	* @return dodatkowy czas pracy
	*/
	int get_czas_dod() const {
		return dodatkowe_godziny;
	}

	/**
	* Funkcja zwraca œredni¹ iloœæ przepracowanych godzin w jednym dniu.
	* @return œredni dzienny czas pracy
	*/
	double get_sredni_czas_pracy() {
		oblicz_sredni_czas_pracy();
		return sredni_czas_pracy;
	}

	/**
	* Funkcja ustawia wartoœæ pola standardowe_godziny.
	* @param czas_std iloœæ przepracowanych godzin standardowych
	*/
	void set_czas_std(int czas_std) {
		standardowe_godziny = czas_std;
	}

	/**
	* Funkcja ustawia wartoœæ pola dodatkowe_godziny.
	* @param czas_dod iloœæ przepracowanych godzin doodatkowych
	*/
	void set_czas_dod(int czas_dod) {
		dodatkowe_godziny = czas_dod;
	}

	/**
	* Funkcja zwiêksza dodatkowy czas pracy o podan¹ iloœæ godzin.
	* @param czas_do_dodania iloœæ godzin dodatkowych do dodania
	*/
	void zwieksz_dod_czas_pracy(int czas_do_dodania);

	/**
	* Funkcja zmniejsza dodatkowy czas pracy o podan¹ iloœæ godzin.
	* @param czas_do_odjecia iloœæ godzin dodatkowych do odjêcia
	*/
	void zmniejsz_dod_czas_pracy(int czas_do_odjecia);

	/**
	* Funkcja zwraca ca³kowity czas pracy.
	* @return ca³kowity czas pracy
	*/
	int get_calkowity_czas_pracy() {
		return (standardowe_godziny + dodatkowe_godziny);
	}

	/**
	* Funkcja wirtualna, oblicza œredni¹ iloœæ przepracowanych godzin w danym okresie czasu.
	*/
	void virtual oblicz_sredni_czas_pracy() {};

	/** Funkcja wirtualna, wyœwietlaj¹ca czas pracy, w okreœlonym okresie
	* @param nrp numer identyfikatora pracownika
	*/
	void virtual wypisz_czas_pracy(int nrp) {};
};

