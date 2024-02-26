#pragma once
#include "czas_pracy.h"

/**
* Klasa zawiera dane dotycz�ce dziennego czasu pracy pracownika i metody do ich obs�ugi.
*/
class czas_pracy_dzienny :
	public virtual czas_pracy
{
public:
		
	/**
	* Funkcja oblicza �redni� ilo�� przepracowanych godzin w jednym dniu.
	*/
	void oblicz_sredni_czas_pracy() override {
		sredni_czas_pracy = ((double)get_czas_std() + get_czas_dod());
	}

	/** Funkcja  wy�wietlaj�ca czas pracy, w jednym dniu
	* @param nrp numer identyfikatora pracownika
	*/
	void wypisz_czas_pracy(int nrp) override;
};

