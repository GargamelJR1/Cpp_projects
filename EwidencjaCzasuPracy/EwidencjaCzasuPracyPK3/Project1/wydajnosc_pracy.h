#pragma once

/**
* Klasa zawiera dane dotycz�ce wydajno�ci pracy pracownika i metody do ich obs�ugi.
*/
class wydajnosc_pracy
{
	double wydajnosc_wyliczona;
	int ilosc_wykonanej_czynnosci;
	int wymagana_ilosc_czynnosci;

public:

	/**
	* Konstruktor domy�lny, inicjalizuje pola obiektu warto�ci� 0.
	*/
	wydajnosc_pracy() :wydajnosc_wyliczona(0), ilosc_wykonanej_czynnosci(0), wymagana_ilosc_czynnosci(0) {};

	/**
	* Operator dodawania, zwi�ksza ilo�� wykonanej czynno�ci.
	* @param _ilosc liczba o jak� powi�kszana jest ilo�� wykonanej czynno�ci
	*/
	wydajnosc_pracy& operator+=(int dodatkowa_ilosc) {
		ilosc_wykonanej_czynnosci += dodatkowa_ilosc;
		return *this;
	}

	/**
	* Operator odejmowania, zmniejsza ilo�� wykonanej czynno�ci.
	* @param _ilosc liczba o jak� pomniejszana jest ilo�� wykonanej czynno�ci
	*/
	wydajnosc_pracy& operator-=(int _ilosc) {
		ilosc_wykonanej_czynnosci -= _ilosc;
		return *this;
	}

	/**
	* Funkcja ustawia warto�� pola ilosc_wykonanej_czynnosci.
	* @param iwc wykonana ilo�� czynno�ci
	*/
	void set_ilosc_wykonanej_czynnosci(int iwc) {
		ilosc_wykonanej_czynnosci = iwc;
	}

	/**
	* Funkcja ustawia warto�� pola wymagana_ilosc_czynnosci.
	* @param wic wymagana ilo�� czynno�ci
	*/
	void set_wymagana_ilosc_czynnosci(int wic) {
		wymagana_ilosc_czynnosci = wic;
	}

	/**
	* Funkcja zwraca warto�� wydajno�� wyliczona.
	* @note Funkcja przed zwr�ceniem warto�ci wywo�uje funkcj� oblicz_wydajnosc().
	* @return obliczona wydajno��
	*/
	double get_wydajnosc_wyliczona() {
		oblicz_wydajnosc();
		return wydajnosc_wyliczona;
	}

	/**
	* Funkcja zwraca ilo�� wymaganej czynno�ci.
	* @return ilo�� wymaganej czynno�ci
	*/
	int get_wymagana_ilosc_czynnosci() const {
		return wymagana_ilosc_czynnosci;
	}

	/**
	* Funkcja zwraca ilo�� wykonanej czynno�ci.
	* @return ilo�� wykonanej czynno�ci
	*/
	int get_ilosc_wykonanej_czynnosci() const {
		return ilosc_wykonanej_czynnosci;
	}

	/**
	* Funkcja oblicza wydajno��.
	* @note gdy pole wymagana_ilosc_czynnosci jest r�wne 0, wydajno�� jest r�wna 0, a gdy pole wymagana_ilosc_czynnosci jest r�ne od 0,
		wydajno�� jest r�wna iloczynowi ilosc_wykonanej_czynnosci/wymagana_ilosc_czynnosci.
	*/
	void oblicz_wydajnosc();
};

