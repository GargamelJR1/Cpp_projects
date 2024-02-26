#pragma once

/**
* Klasa zawiera dane dotycz¹ce wydajnoœci pracy pracownika i metody do ich obs³ugi.
*/
class wydajnosc_pracy
{
	double wydajnosc_wyliczona;
	int ilosc_wykonanej_czynnosci;
	int wymagana_ilosc_czynnosci;

public:

	/**
	* Konstruktor domyœlny, inicjalizuje pola obiektu wartoœci¹ 0.
	*/
	wydajnosc_pracy() :wydajnosc_wyliczona(0), ilosc_wykonanej_czynnosci(0), wymagana_ilosc_czynnosci(0) {};

	/**
	* Operator dodawania, zwiêksza iloœæ wykonanej czynnoœci.
	* @param _ilosc liczba o jak¹ powiêkszana jest iloœæ wykonanej czynnoœci
	*/
	wydajnosc_pracy& operator+=(int dodatkowa_ilosc) {
		ilosc_wykonanej_czynnosci += dodatkowa_ilosc;
		return *this;
	}

	/**
	* Operator odejmowania, zmniejsza iloœæ wykonanej czynnoœci.
	* @param _ilosc liczba o jak¹ pomniejszana jest iloœæ wykonanej czynnoœci
	*/
	wydajnosc_pracy& operator-=(int _ilosc) {
		ilosc_wykonanej_czynnosci -= _ilosc;
		return *this;
	}

	/**
	* Funkcja ustawia wartoœæ pola ilosc_wykonanej_czynnosci.
	* @param iwc wykonana iloœæ czynnoœci
	*/
	void set_ilosc_wykonanej_czynnosci(int iwc) {
		ilosc_wykonanej_czynnosci = iwc;
	}

	/**
	* Funkcja ustawia wartoœæ pola wymagana_ilosc_czynnosci.
	* @param wic wymagana iloœæ czynnoœci
	*/
	void set_wymagana_ilosc_czynnosci(int wic) {
		wymagana_ilosc_czynnosci = wic;
	}

	/**
	* Funkcja zwraca wartoœæ wydajnoœæ wyliczona.
	* @note Funkcja przed zwróceniem wartoœci wywo³uje funkcjê oblicz_wydajnosc().
	* @return obliczona wydajnoœæ
	*/
	double get_wydajnosc_wyliczona() {
		oblicz_wydajnosc();
		return wydajnosc_wyliczona;
	}

	/**
	* Funkcja zwraca iloœæ wymaganej czynnoœci.
	* @return iloœæ wymaganej czynnoœci
	*/
	int get_wymagana_ilosc_czynnosci() const {
		return wymagana_ilosc_czynnosci;
	}

	/**
	* Funkcja zwraca iloœæ wykonanej czynnoœci.
	* @return iloœæ wykonanej czynnoœci
	*/
	int get_ilosc_wykonanej_czynnosci() const {
		return ilosc_wykonanej_czynnosci;
	}

	/**
	* Funkcja oblicza wydajnoœæ.
	* @note gdy pole wymagana_ilosc_czynnosci jest równe 0, wydajnoœæ jest równa 0, a gdy pole wymagana_ilosc_czynnosci jest ró¿ne od 0,
		wydajnoœæ jest równa iloczynowi ilosc_wykonanej_czynnosci/wymagana_ilosc_czynnosci.
	*/
	void oblicz_wydajnosc();
};

