#pragma once
#include "praca.h"

/**
* Klasa s�u�y do obs�ugi pojedynczego pracownika. Zawiera dane zwi�zane z nim i metody dost�pu do tych danych.
*/
class pracownik
{
	int identyfikator;
	static int numer;
	std::string imie, nazwisko;
	int wiek;
	praca praca_pracownika;

	/**
	* Funkcja zwraca czas pracy z wybranego dnia.
	* @param dzien numer dnia
	*/
	auto getCzasPracy_wybrany_dzien(int dzien) {
		return praca_pracownika.get_czas_pracy_wybrany(1, dzien);
	}

	/**
	* Funkcja zwraca czas pracy z wybranego tygodnia.
	* @param tydzien numer tygodnia
	*/
	auto getCzasPracy_wybrany_tydzien(int tydzien) {
		return praca_pracownika.get_czas_pracy_wybrany(2, tydzien);
	}

	/**
	* Funkcja zwraca czas pracy z wybranego miesi�ca.
	* @param miesiac numer miesi�ca
	*/
	auto getCzasPracy_wybrany_miesiac(int miesiac) {
		return praca_pracownika.get_czas_pracy_wybrany(3, miesiac);
	}

	/**
	* Funkcja zwraca czas pracy roczny.
	* @return roczny czas pracy
	*/
	auto getCzasPracy_rok() {
		return praca_pracownika.get_czas_pracy_wybrany(4);
	}

	/**
	* Funkcja zwraca wydajno�� pracy z wybranego dnia.
	* @param dzien numer dnia
	* @return wydajno�� wybranego dnia
	*/
	auto getWydajnosc_wybrany_dzien(int dzien) {
		return praca_pracownika.get_wydajnosc_wybrana(1, dzien);
	}

	/**
	* Funkcja zwraca wydajno�� pracy z wybranego tygodnia.
	* @param tydzien numer tygodnia
	* @return wydajno�� wybranego tygodnia
	*/
	auto getWydajnosc_wybrany_tydzien(int tydzien) {
		return praca_pracownika.get_wydajnosc_wybrana(2, tydzien);
	}

	/**
	* Funkcja zwraca wydajno�� pracy z wybranego miesi�ca.
	* @param miesiac numer miesi�ca
	* @return wydajno�� wybranego miesi�ca
	*/
	auto getWydajnosc_wybrany_miesiac(int miesiac) {
		return praca_pracownika.get_wydajnosc_wybrana(3, miesiac);
	}

	/**
	* Funkcja zwraca wydajno�� pracy roczn�.
	* @return wydajno�� roczna
	*/
	auto getWydajnosc_rok() {
		return praca_pracownika.get_wydajnosc_wybrana(4);
	}

	/**
	* Funkcja ustawia wydajno�� pracy wybranego dnia.
	* @param iloscwk ilo�� wykonana czynno�ci
	* @param iloscwm ilo�� wymagana czynno�ci
	* @param dzien numer dnia
	*/
	void setWydajnoscdzien(int iloscwk, int iloscwm, int dzien) {
		praca_pracownika.set_ilosc_wykonana_dzienna(iloscwk, dzien);
		praca_pracownika.set_ilosc_wymagana_dzienna(iloscwm, dzien);
	}

	/**
	* Funkcja ustawia wydajno�� pracy wybranego tygodnia.
	* @param iloscwk ilo�� wykonana czynno�ci
	* @param iloscwm ilo�� wymagana czynno�ci
	* @param tydzien numer tygodnia
	*/
	void setWydajnosctydzien(int iloscwk, int iloscwm, int tydzien) {
		praca_pracownika.set_ilosc_wykonana_tygodniowa(iloscwk, tydzien);
		praca_pracownika.set_ilosc_wymagana_tygodniowa(iloscwm, tydzien);
	}

	/**
	* Funkcja ustawia wydajno�� pracy wybranego miesi�ca.
	* @param iloscwk ilo�� wykonana czynno�ci
	* @param iloscwm ilo�� wymagana czynno�ci
	* @param miesiac numer miesi�ca
	*/
	void setWydajnoscmiesiac(int iloscwk, int iloscwm, int miesiac) {
		praca_pracownika.set_ilosc_wykonana_miesieczna(iloscwk, miesiac);
		praca_pracownika.set_ilosc_wymagana_miesieczna(iloscwm, miesiac);
	}

	/**
	* Funkcja ustawia wydajno�� pracy roczn�.
	* @param iloscwk ilo�� wykonana czynno�ci
	* @param iloscwm ilo�� wymagana czynno�ci
	*/
	void setWydajnoscrok(int iloscwk, int iloscwm) {
		praca_pracownika.set_ilosc_wykonana_roczna(iloscwk);
		praca_pracownika.set_ilosc_wymagana_roczna(iloscwm);
	}

	/**
	* Funkcja ustawia czas pracy wybranego okresu czasu.
	* @param std godziny standardowe
	* @param dod godziny dodatkowe
	* @param dtmr dzien / tydzie� / miesi�c / rok
	* @param nr numer wybranego dnia / tygodnia / miesi�ca
	*/
	void set_czas_wybrany(int std, int dod, int dtmr, int nr = 1) {
		praca_pracownika.set_czas_pracy_wybrany(std, dod, dtmr, nr);
	}

public:

	/**
	* Konstruktor domy�lny,kt�ry tworzy nowych pracownik�w, bez danych.
	*/
	pracownik() : imie(" "), nazwisko(" "), wiek(0), identyfikator(0), praca_pracownika() {};

	/**
	* Konstruktor,kt�ry tworzy nowych pracownik�w, bez danych pracy.
	* @param p_imie imie pracownika
	* @param p_nazwisko nazwisko pracownika
	* @param p_wiek wiek pracownika
	* @param numer numer identyfikatora pracownika
	*/
	pracownik(string p_imie, string p_nazwisko, int p_wiek) :imie(p_imie), nazwisko(p_nazwisko), wiek(p_wiek), identyfikator(numer), praca_pracownika() {
		numer++;
	};

	/**
	* Konstruktor kopiuj�cy.
	* @param p sta�a referencja na pracownika
	*/
	pracownik(const pracownik& p) : imie(p.imie), nazwisko(p.nazwisko), wiek(p.wiek), identyfikator(p.identyfikator), praca_pracownika(p.praca_pracownika) {}

	/**
	* Konstruktor przenosz�cy.
	* @param p referencja na r-warto�� pracownika
	*/
	pracownik(pracownik&& p)noexcept{
		imie = move(p.imie);
		nazwisko = move(p.nazwisko);
		identyfikator = p.identyfikator;
		praca_pracownika = p.praca_pracownika;
	}

	/**
	* Operator przeniesienia.
	* @param p referencja na r-warto�� pracownika
	*/
	pracownik& operator=(pracownik&& p) noexcept;

	/**
	* Operator przypisania.
	* @param p referencja na pracownika
	*/
	pracownik& operator=(const pracownik& p);

	/**
	* Funkcja zwraca warto�� pola imie.
	* @return imi� pracownika
	*/
	string getImie() const {
		return imie;
	}

	/**
	* Funkcja zwraca warto�� pola nazwisko.
	* @return nazwisko pracownika
	*/
	string getNazwisko() const {
		return nazwisko;
	}

	/**
	* Funkcja zwraca warto�� pola wiek.
	* @return wiek pracownika
	*/
	int getWiek() const {
		return wiek;
	}

	/**
	* Funkcja ustawia warto�� pola imie.
	* @param n_imie imie pracownika
	*/
	void setImie(string n_imie) {
		imie = n_imie;
	}

	/**
	* Funkcja ustawia warto�� pola nazwisko.
	* @param n_nazwisko nazwisko pracownika
	*/
	void setNazwisko(string n_nazwisko) {
		nazwisko = n_nazwisko;
	}

	/**
	* Funkcja ustawia warto�� pola wiek.
	* @param n_wiek wiek pracownika
	*/
	void setWiek(int n_wiek) {
		wiek = n_wiek;
	}

	/**
	* Funkcja zwraca warto�� pola identyfikator.
	* @return numer identyfikatora
	*/
	int getID() const {
		return identyfikator;
	}

	/**
	* Funkcja zwraca warto�� wydajno�ci pracy.
	* @return warto�ci zwi�zane z wydajno�ci� pracy
	* @note zwracany warto�ci s� w tuple
	*/
	auto getWydajnosc(int tydzien_miesiac_rok) {
		return praca_pracownika.get_wydajnosc(tydzien_miesiac_rok);
	}

	/**
	* Funkcja zwraca warto�� czasu pracy.
	* @return czas pracy
	* @note zwracany warto�ci s� w tuple
	*/
	auto getCzasPracy(int dzien_tydzien_miesiac_rok) {
		return praca_pracownika.get_czas_pracy(dzien_tydzien_miesiac_rok);
	}

	/**
	* Funkcja zwraca warto�� wynagrodzenia.
	* @return wynagrodzenie za okre�lony okres czasu
	*/
	double getWynagrodzenie(int tydzien_miesiac_rok) {
		return praca_pracownika.oblicz_wynagrodzenie(tydzien_miesiac_rok);
	}

	/**
	* Funkcja zwraca warto�� p�acy godzinowej.
	* @return p�aca godzinowa
	* @note zwracany warto�ci s� w tuple
	*/
	auto getStawkagodzinowa() {
		return praca_pracownika.get_stawki_godzinowe();
	}

	/**
	* Funkcja ustawia warto�ci p�acy godzinowej.
	* @param plnstd p�aca godzinowa za godziny standardowe
	* @param plndod p�aca godzinowa za godziny nadliczbowe
	*/
	void setStawkagodzinowa(double plnstd, double plndod) {
		praca_pracownika.set_stawka_za_prace(plnstd, plndod);
	}

	/**
	* Funkcja ustawia warto�ci potrzebne do obliczania wydajno�ci.
	* @param ilosc_wykonana wykonana ilo�� czynno�ci
	* @param ilosc_wymagana wymagana ilo�� czynno�ci
	*/
	void setWydajnoscpracy(int ilosc_wykonana, int ilosc_wymagana) {
		praca_pracownika.set_wydajnosc_pracy(ilosc_wykonana, ilosc_wymagana);
	}

	/**
	* Funkcja zwraca ca�kowity czas pracy pracownika.
	* @return ca�kowity czas pracy pracownika
	*/
	int getSumaCzasuPracy(int dzien_tydzien_miesiac_rok) {
		return get<0>(getCzasPracy(dzien_tydzien_miesiac_rok)) + get<1>(getCzasPracy(dzien_tydzien_miesiac_rok));
	}

	/**
	* Funkcja ustawia obecny dzien, tydzie� i miesi�c.
	* @param dzien obecny dzie�
	* @param tydzien obecny tydzie�
	* @param miesiac obecny miesi�c
	*/
	void setDzien_tydzien_i_miesiac(int dzien, int tydzien, int miesiac);

	/**
	* Funkcja wyswietla czas pracy pracownika za wybrany okres czasu.
	* @param dzien obecny dzie�
	* @param tydzien obecny tydzie�
	* @param miesiac obecny miesi�c
	* @param
	*/
	void wyswietl_czas_pracownika(int dzien_tyg_mies_rocz, int miesiac = 0, int tydzien = 0, int dzien = 0) {
		praca_pracownika.wyswietl_czas(identyfikator, dzien_tyg_mies_rocz, miesiac, tydzien, dzien);
	}

	/**
	* Funkcja zmniejsza ilo�� wykonanej czynno�ci pracownika.
	* @param dzien obecny dzie�
	*/
	void zmniejszIlosc_czynnosci(int ilosc) {
		praca_pracownika.zmniejsz_ilosc_czynnosci(ilosc);
	}

	/**
	* Funkcja ustawia warto�� pocz�tkowego numeru identyfikatora.
	* @param nowy_min_ID nowy pocz�tkowy (najmniejszy) numer identyfikatora
	*/
	void setMinID(int nowy_min_ID) {
		numer = ++nowy_min_ID;
	}

	/**
	* Funkcja ustawia warto�ci p�acy godzinowej.
	* @param stdgodz ilo�� przepracowanych godzin standardowych
	* @param dodgodz ilo�� przepracowanych godzin dodatkowych
	* @param dni ilo�� przepracowanych dni
	* @return (1) je�li uda si� ustawi� czas pracy lub (0), je�li si� nie uda
	*/
	bool setCzaspracy(int stdgodz, int dodgodz);

	/**
	* Funkcja zwi�ksza przepracowan� ilo�� godzin standardowych.
	* @param std ilo�� godzin, o jak� zmieni si� czas pracy standardowy
	* @return (1) je�li uda si� zwi�kszy� czas pracy standardowy lub (0), je�li si� nie uda
	*/
	bool zwiekszCzasPracyStd(int std);

	/**
	* Funkcja zmniejsza przepracowan� ilo�� godzin standardowych.
	* @param std ilo�� godzin, o jak� zmieni si� czas pracy standardowy
	* @return (1) je�li uda si� zmniejszy� czas pracy standardowy lub (0), je�li si� nie uda
	*/
	bool zmniejszCzasPracyStd(int std);

	/**
	* Funkcja zwi�ksza przepracowan� ilo�� godzin dodatkowych.
	* @param dod ilo�� godzin, o jak� zmieni si� czas pracy dodatkowy
	* @return (1) je�li uda si� zwi�kszy� czas pracy dodatkowy lub (0), je�li si� nie uda
	*/
	bool zwiekszCzasPracyDod(int dod);

	/**
	* Funkcja zwi�ksza wykonan� ilo�� czynno�ci.
	* @param dod_ilosc ilo�� czynno�ci, o jak� zmieni si� wykonana ilo�� czynno�ci
	* @return (1) je�li uda si� zwi�kszy� ilo�� wykonanych czynno�ci lub (0), je�li si� nie uda
	*/
	void zwiekszIloscCzynnosci(int dod_ilosc);

	/**
	* Funkcja wypisuje warto�ci pracownika.
	*/
	void Wypisz();

	/**
	* Funkcja ustawia wymagan� ilo�� czynno�ci w danym czasie.
	* @param dzien_tyg_mies_rocz dzien / tydzie� / miesi�c / rok
	* @param ilosc ilo�� wymaganej czynno�ci
	* @param nr numer wybranego dnia / tygodnia / miesi�ca
	*/
	void setIlosc_wymagana(int dzien_tyg_mies_rocz, int ilosc, int nr = 0);

	/**
	* Operator zwraca dane pracownika.
	* @param index ustala kt�ra dana ma by� zwr�cona \n
		(0) - numer identyfikatora \n
		(1) - imie \n
		(2) - nazwisko \n
		(3) - wiek \n
	@return wybrana warto��
	*/
	string operator[](int index) const;


	friend istream& operator>>(istream& is, pracownik& p1);
	friend ostream& operator<<(ostream& os, pracownik& p1);
};

/**
* Operator strumieniowy wyj�cia klasy pracownik, zwraca parametry pracownika do strumienia wyj�ciowego.
* @param os referencja na strumie� wyj�ciowy
* @param p1 referencja sta�y obiekt klasy pracownik
* @note operator wykorzystywany przy zapisie pracownik�w do pliku
*/
ostream& operator<<(ostream& os, pracownik& p1);

/**
* Operator strumieniowy wej�cia klasy pracownik, pobiera parametry pracownika ze strumienia wyj�ciowego.
* @param os referencja na strumie� wyj�ciowy
* @param p1 referencja obiekt klasy pracownik
* @note operator wykorzystywany przy odczycie pracownik�w z pliku
*/
istream& operator>>(istream& is, pracownik& p1);
