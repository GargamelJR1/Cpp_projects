#pragma once
#include "czas_pracy.h"

/**
* Klasa zawiera dane dotycz�ce miesi�cznego czasu pracy pracownika i metody do ich obs�ugi.
*/
class czas_pracy_miesieczny :
	public virtual czas_pracy
{
public:

	/**
	* Funkcja oblicza �redni� ilo�� przepracowanych godzin w jednym miesi�cu.
	*/
	void oblicz_sredni_czas_pracy() override {
		sredni_czas_pracy = ((double)get_czas_std() + get_czas_dod()) / 30;
	}

	/** Funkcja  wy�wietlaj�ca czas pracy, w jednym miesi�cu
	* @param nrp numer identyfikatora pracownika
	*/
	void wypisz_czas_pracy(int nrp) override;
};

