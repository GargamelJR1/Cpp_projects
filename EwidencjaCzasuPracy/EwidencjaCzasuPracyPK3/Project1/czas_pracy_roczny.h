#pragma once
#include "czas_pracy.h"

/**
* Klasa zawiera dane dotycz¹ce rocznego czasu pracy pracownika i metody do ich obs³ugi.
*/
class czas_pracy_roczny :
    public virtual czas_pracy
{
public:

	/**
	* Funkcja oblicza œredni¹ iloœæ przepracowanych godzin w roku.
	*/
	void oblicz_sredni_czas_pracy() override {
		sredni_czas_pracy = ((double)get_czas_std() + get_czas_dod()) / 365;
	}

	/** Funkcja  wyœwietlaj¹ca czas pracy, w roku
	* @param nrp numer identyfikatora pracownika
	*/
	void wypisz_czas_pracy(int nrp) override;
};

