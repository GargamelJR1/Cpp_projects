#pragma once
#include "wydajnosc_pracy.h"
#include "funkcje.h"
#include <tuple>
#include <array>

/**
* Klasa zawiera dane dotycz�ce wydajno�ci pracy pracownika z podzia�em na okresy czasu i metody do ich obs�ugi.
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
	* Funkcja zwraca warto�ci zwi�zane z obiektem klasy wydajno�� w obecnym okresie czasu jako postaci tuple.
	* @param dzien_tydzien_miesiac_rok dzien / tydzie� / miesi�c / rok
	* @return ilo�� wykonanej czynno�ci, wyliczona wydajno��, wymagana ilo�� czynno�ci
	*/
	tuple<int, double, int> get_wydajnosc(int dzien_tydzien_miesiac_rok);

	/**
	* Funkcja zwraca warto�ci zwi�zane z obiektem klasy wydajno�� w wybranym okresie czasu jako postaci tuple.
	* @param dzien_tydzien_miesiac_rok dzien / tydzie� / miesi�c / rok
	* @param wybor numer wybranego dnia / tygodnia / miesi�ca
	* @return ilo�� wykonanej czynno�ci, wyliczona wydajno��, wymagana ilo�� czynno�ci
	*/
	tuple<int, double, int> get_wydajnosc_wybrana(int dzien_tydzien_miesiac_rok, int wybor = 1);

	/**
	* Funkcja ustawia warto�ci zwi�zane z wydajno�ci� pracy.
	* @param ilosc_czynnosci ilosc wykonanych czynno�ci
	* @param wymagana_ilosc_czynnosci ilo�� wymaganych czynno�ci
	*/
	void set_wydajnosc_pracy(int ilosc_czynnosci, int wymagana_ilosc_czynnosci);

	/**
	* Funkcja ustawia tygodniow� wymagan� ilo�� czynno�ci.
	* @param wymagana_ilosc_czynnosci ilo�� wymaganych czynno�ci
	* @param _tydzien numer tygodnia
	*/
	void set_ilosc_wymagana_tygodniowa(int wymagana_ilosc_czynnosci, int _tydzien);

	/**
	* Funkcja ustawia miesi�czn� wymagan� ilo�� czynno�ci.
	* @param _tydzien numer miesi�ca
	* @param wymagana_ilosc_czynnosci ilo�� wymaganych czynno�ci
	*/
	void set_ilosc_wymagana_miesieczna(int _miesiac, int wymagana_ilosc_czynnosci);

	/**
	* Funkcja ustawia roczn� wymagan� ilo�� czynno�ci.
	* @param wymagana_ilosc_czynnosci ilo�� wymaganych czynno�ci
	*/
	void set_ilosc_wymagana_roczna(int wymagana_ilosc_czynnosci) {
		wydajnosc_roczna.set_wymagana_ilosc_czynnosci(wymagana_ilosc_czynnosci);
	}

	/**
	* Funkcja zwi�ksza ilo�� wykonanej czynno�ci.
	* @param minusilosc liczba o jak� powi�kszana jest ilo�� wykonanej czynno�ci
	*/
	void zwieksz_ilosc_czynnosci(int plusilosc);

	/**
	* Funkcja zmniejsza ilo�� wykonanej czynno�ci.
	* @param minusilosc liczba o jak� pomniejszana jest ilo�� wykonanej czynno�ci
	*/
	void zmniejsz_ilosc_czynnosci(int minusilosc);

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

	/**
	* Funkcja ustawia dzienna wymagan� ilo�� czynno�ci.
	* @param ilosc_wym ilo�� wymaganych czynno�ci
	* @param xdzien wybrany dzie�
	*/
	void set_ilosc_wymagana_dzienna(int ilosc_wym, int xdzien) {
		xdzien--;
		wydajnosc_dzienna[xdzien].set_wymagana_ilosc_czynnosci(ilosc_wym);
	}

	/**
	* Funkcja ustawia dzienna wykonan� ilo�� czynno�ci.
	* @param temp_wydajnosc ilo�� wykonanych czynno�ci
	* @param xdzien wybrany dzie�
	*/
	void set_ilosc_wykonana_dzienna(int temp_wydajnosc, int xdzien) {
		xdzien--;
		wydajnosc_dzienna[xdzien].set_ilosc_wykonanej_czynnosci(temp_wydajnosc);
	}

	/**
	* Funkcja ustawia tygodniow� wykonan� ilo�� czynno�ci.
	* @param temp_wydajnosc ilo�� wykonanych czynno�ci
	* @param xtydzien wybrany tydzie�
	*/
	void set_ilosc_wykonana_tygodniowa(int temp_wydajnosc, int xtydzien) {
		xtydzien--;
		wydajnosc_tygodniowa[xtydzien].set_ilosc_wykonanej_czynnosci(temp_wydajnosc);
	}

	/**
	* Funkcja ustawia miesi�czn� wykonan� ilo�� czynno�ci.
	* @param temp_wydajnosc ilo�� wykonanych czynno�ci
	* @param xmiesiac wybrany miesi�c
	*/
	void set_ilosc_wykonana_miesieczna(int temp_wydajnosc, int xmiesiac) {
		xmiesiac--;
		wydajnosc_miesieczna[xmiesiac].set_ilosc_wykonanej_czynnosci(temp_wydajnosc);
	}

	/**
	* Funkcja ustawia roczn� wykonan� ilo�� czynno�ci.
	* @param temp_wydajnosc ilo�� wykonanych czynno�ci
	*/
	void set_ilosc_wykonana_roczna(int temp_wydajnosc) {
		wydajnosc_roczna.set_ilosc_wykonanej_czynnosci(temp_wydajnosc);
	}
};

