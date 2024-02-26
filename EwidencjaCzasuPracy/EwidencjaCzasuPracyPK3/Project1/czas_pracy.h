#pragma once
#include "funkcje.h"

/**
* Klasa zawiera dane dotycz�ce czasu pracy pracownika i metody do ich obs�ugi.
*/
class czas_pracy
{
	int standardowe_godziny;
	int dodatkowe_godziny;

protected:
	double sredni_czas_pracy;

public:

	/**
	* Konstruktor domy�lny, inicjalizuje pola obiektu warto�ci� 0.
	*/
	czas_pracy() :standardowe_godziny(0), dodatkowe_godziny(0), sredni_czas_pracy(0) { };

	/**
	* Konstruktor tworz�cy nowy obiekt klasy z warto�ciami pocz�tkowymi.
	* @param st przepracowany standardowy czas pracy
	* @param dod przepracowany dodatkowy czas pracy
	* @param dn przepracowane dni
	*/
	czas_pracy(int st, int dod, int dn) :standardowe_godziny(st), dodatkowe_godziny(dod), sredni_czas_pracy(0) { };

	/**
	* Operator dodawania, zwi�ksza ilo�� standardowych przepracowanych godzin.
	* @param nowe_godziny liczba o jak� powi�kszana jest ilo�� przepracowanych godzin standardowych
	*/
	czas_pracy& operator+=(int nowe_godziny) {
		standardowe_godziny += nowe_godziny;
		return *this;
	}

	/**
	* Operator odejmowania, zmniejsza ilo�� standardowych przepracowanych godzin.
	* @param nowe_godziny liczba o jak� pomniejszana jest ilo�� przepracowanych godzin standardowych
	*/
	czas_pracy& operator-=(int nowe_godziny) {
		standardowe_godziny -= nowe_godziny;
		return *this;
	}

	/**
	* Funkcja zwraca ilo�� przepracowanych godzin standardowych.
	* @return standardowy czas pracy
	*/
	int get_czas_std() const {
		return standardowe_godziny;
	}

	/**
	* Funkcja zwraca ilo�� przepracowanych godzin dodatkowych.
	* @return dodatkowy czas pracy
	*/
	int get_czas_dod() const {
		return dodatkowe_godziny;
	}

	/**
	* Funkcja zwraca �redni� ilo�� przepracowanych godzin w jednym dniu.
	* @return �redni dzienny czas pracy
	*/
	double get_sredni_czas_pracy() {
		oblicz_sredni_czas_pracy();
		return sredni_czas_pracy;
	}

	/**
	* Funkcja ustawia warto�� pola standardowe_godziny.
	* @param czas_std ilo�� przepracowanych godzin standardowych
	*/
	void set_czas_std(int czas_std) {
		standardowe_godziny = czas_std;
	}

	/**
	* Funkcja ustawia warto�� pola dodatkowe_godziny.
	* @param czas_dod ilo�� przepracowanych godzin doodatkowych
	*/
	void set_czas_dod(int czas_dod) {
		dodatkowe_godziny = czas_dod;
	}

	/**
	* Funkcja zwi�ksza dodatkowy czas pracy o podan� ilo�� godzin.
	* @param czas_do_dodania ilo�� godzin dodatkowych do dodania
	*/
	void zwieksz_dod_czas_pracy(int czas_do_dodania);

	/**
	* Funkcja zmniejsza dodatkowy czas pracy o podan� ilo�� godzin.
	* @param czas_do_odjecia ilo�� godzin dodatkowych do odj�cia
	*/
	void zmniejsz_dod_czas_pracy(int czas_do_odjecia);

	/**
	* Funkcja zwraca ca�kowity czas pracy.
	* @return ca�kowity czas pracy
	*/
	int get_calkowity_czas_pracy() {
		return (standardowe_godziny + dodatkowe_godziny);
	}

	/**
	* Funkcja wirtualna, oblicza �redni� ilo�� przepracowanych godzin w danym okresie czasu.
	*/
	void virtual oblicz_sredni_czas_pracy() {};

	/** Funkcja wirtualna, wy�wietlaj�ca czas pracy, w okre�lonym okresie
	* @param nrp numer identyfikatora pracownika
	*/
	void virtual wypisz_czas_pracy(int nrp) {};
};

