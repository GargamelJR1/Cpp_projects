#pragma once
#include "wydajnosc_pracy.h"
#include "funkcje.h"
#include <tuple>
#include <array>

/**
* Klasa zawiera dane dotycz¹ce wydajnoœci pracy pracownika z podzia³em na okresy czasu i metody do ich obs³ugi.
*/
class wydajnosc_pracy_pracownika
{
protected:
	std::array<wydajnosc_pracy, 365> wydajnosc_dzienna;
	std::array<wydajnosc_pracy, 53> wydajnosc_tygodniowa;
	std::array<wydajnosc_pracy, 12> wydajnosc_miesieczna;

	wydajnosc_pracy wydajnosc_roczna;
	int miesiac = 1;
	int tydzien = 1;
	int dzien = 1;

public:

	/**
	* Funkcja zwraca wartoœci zwi¹zane z obiektem klasy wydajnoœæ w obecnym okresie czasu jako postaci tuple.
	* @param dzien_tydzien_miesiac_rok dzien / tydzieñ / miesi¹c / rok
	* @return iloœæ wykonanej czynnoœci, wyliczona wydajnoœæ, wymagana iloœæ czynnoœci
	*/
	tuple<int, double, int> get_wydajnosc(int dzien_tydzien_miesiac_rok);

	/**
	* Funkcja zwraca wartoœci zwi¹zane z obiektem klasy wydajnoœæ w wybranym okresie czasu jako postaci tuple.
	* @param dzien_tydzien_miesiac_rok dzien / tydzieñ / miesi¹c / rok
	* @param wybor numer wybranego dnia / tygodnia / miesi¹ca
	* @return iloœæ wykonanej czynnoœci, wyliczona wydajnoœæ, wymagana iloœæ czynnoœci
	*/
	tuple<int, double, int> get_wydajnosc_wybrana(int dzien_tydzien_miesiac_rok, int wybor = 1);

	/**
	* Funkcja ustawia wartoœci zwi¹zane z wydajnoœci¹ pracy.
	* @param ilosc_czynnosci ilosc wykonanych czynnoœci
	* @param wymagana_ilosc_czynnosci iloœæ wymaganych czynnoœci
	*/
	void set_wydajnosc_pracy(int ilosc_czynnosci, int wymagana_ilosc_czynnosci);

	/**
	* Funkcja ustawia tygodniow¹ wymagan¹ iloœæ czynnoœci.
	* @param wymagana_ilosc_czynnosci iloœæ wymaganych czynnoœci
	* @param _tydzien numer tygodnia
	*/
	void set_ilosc_wymagana_tygodniowa(int wymagana_ilosc_czynnosci, int _tydzien);

	/**
	* Funkcja ustawia miesiêczn¹ wymagan¹ iloœæ czynnoœci.
	* @param _tydzien numer miesi¹ca
	* @param wymagana_ilosc_czynnosci iloœæ wymaganych czynnoœci
	*/
	void set_ilosc_wymagana_miesieczna(int _miesiac, int wymagana_ilosc_czynnosci);

	/**
	* Funkcja ustawia roczn¹ wymagan¹ iloœæ czynnoœci.
	* @param wymagana_ilosc_czynnosci iloœæ wymaganych czynnoœci
	*/
	void set_ilosc_wymagana_roczna(int wymagana_ilosc_czynnosci) {
		wydajnosc_roczna.set_wymagana_ilosc_czynnosci(wymagana_ilosc_czynnosci);
	}

	/**
	* Funkcja zwiêksza iloœæ wykonanej czynnoœci.
	* @param minusilosc liczba o jak¹ powiêkszana jest iloœæ wykonanej czynnoœci
	*/
	void zwieksz_ilosc_czynnosci(int plusilosc);

	/**
	* Funkcja zmniejsza iloœæ wykonanej czynnoœci.
	* @param minusilosc liczba o jak¹ pomniejszana jest iloœæ wykonanej czynnoœci
	*/
	void zmniejsz_ilosc_czynnosci(int minusilosc);

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

	/**
	* Funkcja ustawia dzienna wymagan¹ iloœæ czynnoœci.
	* @param ilosc_wym iloœæ wymaganych czynnoœci
	* @param xdzien wybrany dzieñ
	*/
	void set_ilosc_wymagana_dzienna(int ilosc_wym, int xdzien) {
		xdzien--;
		wydajnosc_dzienna[xdzien].set_wymagana_ilosc_czynnosci(ilosc_wym);
	}

	/**
	* Funkcja ustawia dzienna wykonan¹ iloœæ czynnoœci.
	* @param temp_wydajnosc iloœæ wykonanych czynnoœci
	* @param xdzien wybrany dzieñ
	*/
	void set_ilosc_wykonana_dzienna(int temp_wydajnosc, int xdzien) {
		xdzien--;
		wydajnosc_dzienna[xdzien].set_ilosc_wykonanej_czynnosci(temp_wydajnosc);
	}

	/**
	* Funkcja ustawia tygodniow¹ wykonan¹ iloœæ czynnoœci.
	* @param temp_wydajnosc iloœæ wykonanych czynnoœci
	* @param xtydzien wybrany tydzieñ
	*/
	void set_ilosc_wykonana_tygodniowa(int temp_wydajnosc, int xtydzien) {
		xtydzien--;
		wydajnosc_tygodniowa[xtydzien].set_ilosc_wykonanej_czynnosci(temp_wydajnosc);
	}

	/**
	* Funkcja ustawia miesiêczn¹ wykonan¹ iloœæ czynnoœci.
	* @param temp_wydajnosc iloœæ wykonanych czynnoœci
	* @param xmiesiac wybrany miesi¹c
	*/
	void set_ilosc_wykonana_miesieczna(int temp_wydajnosc, int xmiesiac) {
		xmiesiac--;
		wydajnosc_miesieczna[xmiesiac].set_ilosc_wykonanej_czynnosci(temp_wydajnosc);
	}

	/**
	* Funkcja ustawia roczn¹ wykonan¹ iloœæ czynnoœci.
	* @param temp_wydajnosc iloœæ wykonanych czynnoœci
	*/
	void set_ilosc_wykonana_roczna(int temp_wydajnosc) {
		wydajnosc_roczna.set_ilosc_wykonanej_czynnosci(temp_wydajnosc);
	}
};

