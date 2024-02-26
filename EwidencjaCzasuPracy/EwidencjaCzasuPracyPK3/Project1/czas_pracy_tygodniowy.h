#pragma once
#include "czas_pracy.h"

/**
* Klasa zawiera dane dotycz¹ce tygodniowego czasu pracy pracownika i metody do ich obs³ugi.
*/
class czas_pracy_tygodniowy :
	public virtual czas_pracy
{
public:
	
	/**
	* Funkcja oblicza œredni¹ iloœæ przepracowanych godzin w jednym tygodniu.
	*/
	void oblicz_sredni_czas_pracy() override {
		sredni_czas_pracy = ((double)get_czas_std() + get_czas_dod()) / 7;
	}

	/** Funkcja  wyœwietlaj¹ca czas pracy, w jednym tygodniu
	* @param nrp numer identyfikatora pracownika
	*/
	void wypisz_czas_pracy(int nrp) override;
};

