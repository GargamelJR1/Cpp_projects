#pragma once
#include "praca.h"

/**
* Klasa s³u¿y do obs³ugi pojedynczego pracownika. Zawiera dane zwi¹zane z nim i metody dostêpu do tych danych.
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
	* Funkcja zwraca czas pracy z wybranego miesi¹ca.
	* @param miesiac numer miesi¹ca
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
	* Funkcja zwraca wydajnoœæ pracy z wybranego dnia.
	* @param dzien numer dnia
	* @return wydajnoœæ wybranego dnia
	*/
	auto getWydajnosc_wybrany_dzien(int dzien) {
		return praca_pracownika.get_wydajnosc_wybrana(1, dzien);
	}

	/**
	* Funkcja zwraca wydajnoœæ pracy z wybranego tygodnia.
	* @param tydzien numer tygodnia
	* @return wydajnoœæ wybranego tygodnia
	*/
	auto getWydajnosc_wybrany_tydzien(int tydzien) {
		return praca_pracownika.get_wydajnosc_wybrana(2, tydzien);
	}

	/**
	* Funkcja zwraca wydajnoœæ pracy z wybranego miesi¹ca.
	* @param miesiac numer miesi¹ca
	* @return wydajnoœæ wybranego miesi¹ca
	*/
	auto getWydajnosc_wybrany_miesiac(int miesiac) {
		return praca_pracownika.get_wydajnosc_wybrana(3, miesiac);
	}

	/**
	* Funkcja zwraca wydajnoœæ pracy roczn¹.
	* @return wydajnoœæ roczna
	*/
	auto getWydajnosc_rok() {
		return praca_pracownika.get_wydajnosc_wybrana(4);
	}

	/**
	* Funkcja ustawia wydajnoœæ pracy wybranego dnia.
	* @param iloscwk iloœæ wykonana czynnoœci
	* @param iloscwm iloœæ wymagana czynnoœci
	* @param dzien numer dnia
	*/
	void setWydajnoscdzien(int iloscwk, int iloscwm, int dzien) {
		praca_pracownika.set_ilosc_wykonana_dzienna(iloscwk, dzien);
		praca_pracownika.set_ilosc_wymagana_dzienna(iloscwm, dzien);
	}

	/**
	* Funkcja ustawia wydajnoœæ pracy wybranego tygodnia.
	* @param iloscwk iloœæ wykonana czynnoœci
	* @param iloscwm iloœæ wymagana czynnoœci
	* @param tydzien numer tygodnia
	*/
	void setWydajnosctydzien(int iloscwk, int iloscwm, int tydzien) {
		praca_pracownika.set_ilosc_wykonana_tygodniowa(iloscwk, tydzien);
		praca_pracownika.set_ilosc_wymagana_tygodniowa(iloscwm, tydzien);
	}

	/**
	* Funkcja ustawia wydajnoœæ pracy wybranego miesi¹ca.
	* @param iloscwk iloœæ wykonana czynnoœci
	* @param iloscwm iloœæ wymagana czynnoœci
	* @param miesiac numer miesi¹ca
	*/
	void setWydajnoscmiesiac(int iloscwk, int iloscwm, int miesiac) {
		praca_pracownika.set_ilosc_wykonana_miesieczna(iloscwk, miesiac);
		praca_pracownika.set_ilosc_wymagana_miesieczna(iloscwm, miesiac);
	}

	/**
	* Funkcja ustawia wydajnoœæ pracy roczn¹.
	* @param iloscwk iloœæ wykonana czynnoœci
	* @param iloscwm iloœæ wymagana czynnoœci
	*/
	void setWydajnoscrok(int iloscwk, int iloscwm) {
		praca_pracownika.set_ilosc_wykonana_roczna(iloscwk);
		praca_pracownika.set_ilosc_wymagana_roczna(iloscwm);
	}

	/**
	* Funkcja ustawia czas pracy wybranego okresu czasu.
	* @param std godziny standardowe
	* @param dod godziny dodatkowe
	* @param dtmr dzien / tydzieñ / miesi¹c / rok
	* @param nr numer wybranego dnia / tygodnia / miesi¹ca
	*/
	void set_czas_wybrany(int std, int dod, int dtmr, int nr = 1) {
		praca_pracownika.set_czas_pracy_wybrany(std, dod, dtmr, nr);
	}

public:

	/**
	* Konstruktor domyœlny,który tworzy nowych pracowników, bez danych.
	*/
	pracownik() : imie(" "), nazwisko(" "), wiek(0), identyfikator(0), praca_pracownika() {};

	/**
	* Konstruktor,który tworzy nowych pracowników, bez danych pracy.
	* @param p_imie imie pracownika
	* @param p_nazwisko nazwisko pracownika
	* @param p_wiek wiek pracownika
	* @param numer numer identyfikatora pracownika
	*/
	pracownik(string p_imie, string p_nazwisko, int p_wiek) :imie(p_imie), nazwisko(p_nazwisko), wiek(p_wiek), identyfikator(numer), praca_pracownika() {
		numer++;
	};

	/**
	* Konstruktor kopiuj¹cy.
	* @param p sta³a referencja na pracownika
	*/
	pracownik(const pracownik& p) : imie(p.imie), nazwisko(p.nazwisko), wiek(p.wiek), identyfikator(p.identyfikator), praca_pracownika(p.praca_pracownika) {}

	/**
	* Konstruktor przenosz¹cy.
	* @param p referencja na r-wartoœæ pracownika
	*/
	pracownik(pracownik&& p)noexcept{
		imie = move(p.imie);
		nazwisko = move(p.nazwisko);
		identyfikator = p.identyfikator;
		praca_pracownika = p.praca_pracownika;
	}

	/**
	* Operator przeniesienia.
	* @param p referencja na r-wartoœæ pracownika
	*/
	pracownik& operator=(pracownik&& p) noexcept;

	/**
	* Operator przypisania.
	* @param p referencja na pracownika
	*/
	pracownik& operator=(const pracownik& p);

	/**
	* Funkcja zwraca wartoœæ pola imie.
	* @return imiê pracownika
	*/
	string getImie() const {
		return imie;
	}

	/**
	* Funkcja zwraca wartoœæ pola nazwisko.
	* @return nazwisko pracownika
	*/
	string getNazwisko() const {
		return nazwisko;
	}

	/**
	* Funkcja zwraca wartoœæ pola wiek.
	* @return wiek pracownika
	*/
	int getWiek() const {
		return wiek;
	}

	/**
	* Funkcja ustawia wartoœæ pola imie.
	* @param n_imie imie pracownika
	*/
	void setImie(string n_imie) {
		imie = n_imie;
	}

	/**
	* Funkcja ustawia wartoœæ pola nazwisko.
	* @param n_nazwisko nazwisko pracownika
	*/
	void setNazwisko(string n_nazwisko) {
		nazwisko = n_nazwisko;
	}

	/**
	* Funkcja ustawia wartoœæ pola wiek.
	* @param n_wiek wiek pracownika
	*/
	void setWiek(int n_wiek) {
		wiek = n_wiek;
	}

	/**
	* Funkcja zwraca wartoœæ pola identyfikator.
	* @return numer identyfikatora
	*/
	int getID() const {
		return identyfikator;
	}

	/**
	* Funkcja zwraca wartoœæ wydajnoœci pracy.
	* @return wartoœci zwi¹zane z wydajnoœci¹ pracy
	* @note zwracany wartoœci s¹ w tuple
	*/
	auto getWydajnosc(int tydzien_miesiac_rok) {
		return praca_pracownika.get_wydajnosc(tydzien_miesiac_rok);
	}

	/**
	* Funkcja zwraca wartoœæ czasu pracy.
	* @return czas pracy
	* @note zwracany wartoœci s¹ w tuple
	*/
	auto getCzasPracy(int dzien_tydzien_miesiac_rok) {
		return praca_pracownika.get_czas_pracy(dzien_tydzien_miesiac_rok);
	}

	/**
	* Funkcja zwraca wartoœæ wynagrodzenia.
	* @return wynagrodzenie za okreœlony okres czasu
	*/
	double getWynagrodzenie(int tydzien_miesiac_rok) {
		return praca_pracownika.oblicz_wynagrodzenie(tydzien_miesiac_rok);
	}

	/**
	* Funkcja zwraca wartoœæ p³acy godzinowej.
	* @return p³aca godzinowa
	* @note zwracany wartoœci s¹ w tuple
	*/
	auto getStawkagodzinowa() {
		return praca_pracownika.get_stawki_godzinowe();
	}

	/**
	* Funkcja ustawia wartoœci p³acy godzinowej.
	* @param plnstd p³aca godzinowa za godziny standardowe
	* @param plndod p³aca godzinowa za godziny nadliczbowe
	*/
	void setStawkagodzinowa(double plnstd, double plndod) {
		praca_pracownika.set_stawka_za_prace(plnstd, plndod);
	}

	/**
	* Funkcja ustawia wartoœci potrzebne do obliczania wydajnoœci.
	* @param ilosc_wykonana wykonana iloœæ czynnoœci
	* @param ilosc_wymagana wymagana iloœæ czynnoœci
	*/
	void setWydajnoscpracy(int ilosc_wykonana, int ilosc_wymagana) {
		praca_pracownika.set_wydajnosc_pracy(ilosc_wykonana, ilosc_wymagana);
	}

	/**
	* Funkcja zwraca ca³kowity czas pracy pracownika.
	* @return ca³kowity czas pracy pracownika
	*/
	int getSumaCzasuPracy(int dzien_tydzien_miesiac_rok) {
		return get<0>(getCzasPracy(dzien_tydzien_miesiac_rok)) + get<1>(getCzasPracy(dzien_tydzien_miesiac_rok));
	}

	/**
	* Funkcja ustawia obecny dzien, tydzieñ i miesi¹c.
	* @param dzien obecny dzieñ
	* @param tydzien obecny tydzieñ
	* @param miesiac obecny miesi¹c
	*/
	void setDzien_tydzien_i_miesiac(int dzien, int tydzien, int miesiac);

	/**
	* Funkcja wyswietla czas pracy pracownika za wybrany okres czasu.
	* @param dzien obecny dzieñ
	* @param tydzien obecny tydzieñ
	* @param miesiac obecny miesi¹c
	* @param
	*/
	void wyswietl_czas_pracownika(int dzien_tyg_mies_rocz, int miesiac = 0, int tydzien = 0, int dzien = 0) {
		praca_pracownika.wyswietl_czas(identyfikator, dzien_tyg_mies_rocz, miesiac, tydzien, dzien);
	}

	/**
	* Funkcja zmniejsza iloœæ wykonanej czynnoœci pracownika.
	* @param dzien obecny dzieñ
	*/
	void zmniejszIlosc_czynnosci(int ilosc) {
		praca_pracownika.zmniejsz_ilosc_czynnosci(ilosc);
	}

	/**
	* Funkcja ustawia wartoœæ pocz¹tkowego numeru identyfikatora.
	* @param nowy_min_ID nowy pocz¹tkowy (najmniejszy) numer identyfikatora
	*/
	void setMinID(int nowy_min_ID) {
		numer = ++nowy_min_ID;
	}

	/**
	* Funkcja ustawia wartoœci p³acy godzinowej.
	* @param stdgodz iloœæ przepracowanych godzin standardowych
	* @param dodgodz iloœæ przepracowanych godzin dodatkowych
	* @param dni iloœæ przepracowanych dni
	* @return (1) jeœli uda siê ustawiæ czas pracy lub (0), jeœli siê nie uda
	*/
	bool setCzaspracy(int stdgodz, int dodgodz);

	/**
	* Funkcja zwiêksza przepracowan¹ iloœæ godzin standardowych.
	* @param std iloœæ godzin, o jak¹ zmieni siê czas pracy standardowy
	* @return (1) jeœli uda siê zwiêkszyæ czas pracy standardowy lub (0), jeœli siê nie uda
	*/
	bool zwiekszCzasPracyStd(int std);

	/**
	* Funkcja zmniejsza przepracowan¹ iloœæ godzin standardowych.
	* @param std iloœæ godzin, o jak¹ zmieni siê czas pracy standardowy
	* @return (1) jeœli uda siê zmniejszyæ czas pracy standardowy lub (0), jeœli siê nie uda
	*/
	bool zmniejszCzasPracyStd(int std);

	/**
	* Funkcja zwiêksza przepracowan¹ iloœæ godzin dodatkowych.
	* @param dod iloœæ godzin, o jak¹ zmieni siê czas pracy dodatkowy
	* @return (1) jeœli uda siê zwiêkszyæ czas pracy dodatkowy lub (0), jeœli siê nie uda
	*/
	bool zwiekszCzasPracyDod(int dod);

	/**
	* Funkcja zwiêksza wykonan¹ iloœæ czynnoœci.
	* @param dod_ilosc iloœæ czynnoœci, o jak¹ zmieni siê wykonana iloœæ czynnoœci
	* @return (1) jeœli uda siê zwiêkszyæ iloœæ wykonanych czynnoœci lub (0), jeœli siê nie uda
	*/
	void zwiekszIloscCzynnosci(int dod_ilosc);

	/**
	* Funkcja wypisuje wartoœci pracownika.
	*/
	void Wypisz();

	/**
	* Funkcja ustawia wymagan¹ iloœæ czynnoœci w danym czasie.
	* @param dzien_tyg_mies_rocz dzien / tydzieñ / miesi¹c / rok
	* @param ilosc iloœæ wymaganej czynnoœci
	* @param nr numer wybranego dnia / tygodnia / miesi¹ca
	*/
	void setIlosc_wymagana(int dzien_tyg_mies_rocz, int ilosc, int nr = 0);

	/**
	* Operator zwraca dane pracownika.
	* @param index ustala która dana ma byæ zwrócona \n
		(0) - numer identyfikatora \n
		(1) - imie \n
		(2) - nazwisko \n
		(3) - wiek \n
	@return wybrana wartoœæ
	*/
	string operator[](int index) const;


	friend istream& operator>>(istream& is, pracownik& p1);
	friend ostream& operator<<(ostream& os, pracownik& p1);
};

/**
* Operator strumieniowy wyjœcia klasy pracownik, zwraca parametry pracownika do strumienia wyjœciowego.
* @param os referencja na strumieñ wyjœciowy
* @param p1 referencja sta³y obiekt klasy pracownik
* @note operator wykorzystywany przy zapisie pracowników do pliku
*/
ostream& operator<<(ostream& os, pracownik& p1);

/**
* Operator strumieniowy wejœcia klasy pracownik, pobiera parametry pracownika ze strumienia wyjœciowego.
* @param os referencja na strumieñ wyjœciowy
* @param p1 referencja obiekt klasy pracownik
* @note operator wykorzystywany przy odczycie pracowników z pliku
*/
istream& operator>>(istream& is, pracownik& p1);
