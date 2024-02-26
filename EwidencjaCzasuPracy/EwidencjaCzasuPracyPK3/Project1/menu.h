#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "pracownik.h"
#include "funkcje.h"
#include <map>
#include <numeric>
#include <algorithm>
#include "logi.h"
#include "lista.h"
#include <execution>
#include <queue>
#include <chrono>

using namespace std;

/**
* Klasa s³u¿¹ca do obs³ugi menu i programu. Menu obs³ugiwane jest poprzez wpisywanie znaków z klawiatury. Klasa jest oparta o wzorzec singleton.
*/
class menu
{
	double pln_per_godzina_std;
	double pln_per_godzina_dod;
	int pierwszy_dzien_roku = 0;
	int wymagana_ilosc_wykonanej_czynnosci;
	int wymagany_czas_pracy;
	double prog_wydajnosci;
	lista pracownicy;
	int wysw_wydajnosc;
	int wysw_czas;
	int sort_wybor = 0;
	bool kolejnosc = 0;
	const bool LOG = 0; // sta³a decyduj¹ca, czy bêd¹ tworzone logi
	int obecny_dzien = 1;
	int obecny_tydzien = 1;
	int obecny_miesiac = 1;
	int dzien_miesiaca = 1;
	int dzien_tydzien_miesiac_rok = 1;

	/**
	* Konstruktor menu, prywatny, inicjalizuje pola obiektu wartoœci¹ 0. Konstruktor jest wywo³ywany przez publiczn¹ metodê klasy
	*/
	menu(const bool LOGI) : wysw_wydajnosc(0), wysw_czas(0), pln_per_godzina_std(0), pln_per_godzina_dod(0), wymagana_ilosc_wykonanej_czynnosci(0), wymagany_czas_pracy(0), prog_wydajnosci(0), LOG(LOGI)
	{
		if (!LOG)
			logi::utworz_log().wylacz_logowanie();
		cout << "Witaj w Systemie Ewidencji Czasu Pracy" << endl
			<< "Program dziala z zalozeniem ze wszystkie podane dane, jesli nie zaznaczono inaczej, sa danymi dziennymi." << endl
			<< "1 - Wczytaj plik zapisu" << endl << "2 - Otworz program bez danych poczatkowych" << endl << "Prosze wybrac odpowiednia opcje:   ";
		int wybor = wczytaj_liczbe_int_z_zakresu(1, 2);
		if (wybor == 1) {
			wczytaj_plik_konsola();
		}
		else if (wybor == 2) {
			ustaw_nowe_parametry_programu(6);
		}
	};

public:

	/**
	* Funkcja statyczna, tworz¹c¹ obiekt typu menu
	* @param LOG parametr okreœlaj¹cy, czy maj¹ byæ zapisywane logi do pliku, wartoœæ domyœlna 0 oznacza brak logów
	*/
	static menu& utworz_menu(const bool LOG = 0) {
		static menu Menu(LOG);
		return Menu;
	}

	/**
	* Funkcja ustawia wartoœci pól obiektu menu.
	* @param plnperhstd p³aca godzinowa za godziny standardowe
	* @param plnperhdod p³aca godzinowa za godziny dodatkowe
	* @param wiwc wymagana iloœæ wykonanej czynnoœci
	* @param wcp wymagany czas pracy
	* @param pw wymagana wydajnoœæ pracownika
	*/
	void set_wartosci_menu(double plnperhstd, double plnperhdod, int wiwc, int wcp, double pw, int pdr) {
		pln_per_godzina_std = plnperhstd;
		pln_per_godzina_dod = plnperhdod;
		wymagana_ilosc_wykonanej_czynnosci = wiwc;
		wymagany_czas_pracy = wcp;
		prog_wydajnosci = pw;
		pierwszy_dzien_roku = pdr;
	}

	/**
	* Funkcja zwraca wartoœci pól obiektu menu w formie tuple.
	* @return wartoœci menu
	*/
	auto get_wartosci_menu() const {
		return make_tuple(pln_per_godzina_std, pln_per_godzina_dod, wymagana_ilosc_wykonanej_czynnosci, wymagany_czas_pracy, prog_wydajnosci, pierwszy_dzien_roku);
	}

	/**
	* Funkcja wyœwietla i obs³uguje menu programu.
	* @return (1) jeœli program ma byæ kontynuowany, (0) jeœli u¿ytkownik chce wyjœæ z programu
	*/
	bool wyswietl_menu();

	/**
	* Funkcja pobiera od u¿ytkownika i ustawia parametry programu.
	* @param ktory_parametr cyfra 1-7, wyznacza, które parametry proramu edytowaæ
	*/
	void ustaw_nowe_parametry_programu(int ktory_parametr);

	/**
	* Funkcja tworzy nowego pracownika i dodaje go do listy pracownicy.
	* @param p_imie imie pracownika
	* @param p_nazwisko nazwisko pracownika
	* @param p_wiek wiek pracownika
	*/
	void dodaj_pracownika(string p_imie, string p_nazwisko, int p_wiek);

	/**
	* Funkcja tworzy nowego pracownika o podanych przez u¿ytkownika parametrach i dodaje go do listy pracownicy.
	*/
	void dodaj_pracownika_konsola();

	/**
	* Funkcja pobiera od u¿ytkownika nazwe pliku do wczytania i wczytuje go.
	*/
	void wczytaj_plik_konsola(bool norm = 1);

	/**
	* Funkcja wysy³a sformatowan¹ listê pracowników do strumienia wyjœciowego.
	* @param ofs wyjœciowy strumieñ
	* @note funkcja wyœwietla pracowników zgodnych z aktualnymi parametrami wyœwietlania, wysw_czas: (2) - czas pracy poni¿ej wymaganego,
	(1) - czas pracy spe³nia normê, (0) - brak sprawdzania czasu pracy, wysw_wyd: (2) - wydajnoœæ pracy poni¿ej wymaganej,
	(1) - wydajnoœæ pracy spe³nia normê, (0) - brak sprawdzania wydajnoœci pracy.
	*/
	void wyswietl_liste_pracownikow(ostream& ofs);

	/**
	* Funkcja zmienia wybrane parametry pracownika.
	* @param wybor wybór parametru, który ma byæ zmieniony 1-10 (1 - imiê, 2 - nazwisko, 3 - wiek, 4 - dni, 5 - czas std, 6 - czas dod, 7 - wymagana
	  ilosc czynnosci, 8 - wykonana iloœæ czynnoœci, 9 - stawka godzinowa std, 10 - stawka godzinowa dod)
	* @param PR wskaŸnik na edytowanego pracownika
	* @param ed_string nowa wartoœæ, nadpisuj¹ca parametr w formacie string
	* @param ed_int nowa wartoœæ, nadpisuj¹ca parametr w formacie int
	* @param ed_double nowa wartoœæ, nadpisuj¹ca parametr w formacie double
	* @return (1) jeœli uda siê edytowaæ pracownika lub (0), jeœli siê nie uda
	*/
	bool edytuj_pracownika(int wybor, pracownik* PR, const string& ed_string = " ", int ed_int = 0, double ed_double = 0);

	/**
	* Funkcja szuka w wektorze pracownicy pracownika o podanym numerze id.
	* @param numer_id numer identyfikacyjny pracownika do znalezienia
	* @return (1) jeœli pracownika istnieje lub (0) jeœli nie ma pracownika o podanym numerze id
	* @note funkcja zapisuje logi do pliku
	*/
	bool czy_istnieje_pracownik(int numer_id);

	/**
	* Funkcja edytuje okreœlone przez u¿ytkownika parametry pracownika o numerze identyfikacyjnym podanym przez u¿ytkownika.
	*/
	void edytuj_pracownika_konsola();

	/**
	* Funkcja zapisuje dane programu do pliku o œcie¿ce podanej w parametrze.
	* @param sciezkaout œcie¿ka do zapisywanego pliku
	*/
	void zapisz_do_pliku(const string& sciezkaout);

	/**
	* Funkcja pobiera od u¿ytkownika œcie¿kê do pliku i zwraca j¹ w formacie string.
	* @param zapis (1) œcie¿ka do pliku wyjœciowego lub (0) wejœciowego
	* @return sciezka do pliku w formacie string
	*/
	string ustaw_sciezke_zapisu_odczytu(bool zapis);

	/**
	* Funkcja ustawia wybrane przez u¿ytkownika parametry wyœwietlania.
	*/
	void parametry_wyswietlania();

	/**
	* Funkcja ostrzega u¿ytkownika o mo¿liwej utracie danych i wczytuje nowy plik zapisu lub powraca do menu.
	*/
	void wczytaj_nowy_plik_konsola();

	/**
	* Funkcja ustawia wartoœæ pocz¹tkowego numeru identyfikatora dla kolejnych pracowników na najwy¿szy obecnie u¿ywany numer identyfikatora.
	*/
	void ustaw_id();

	/**
	* Funkcja wczytuje plik o œcie¿ce podanej w parametrze.
	* @param sciezkain œcie¿ka do pliku, który ma byæ wczytany
	* return (1) jeœli uda siê wczytaæ plik, (0) gdy nie mo¿na wczytaæ pliku
	*/
	bool wczytaj_plik(const string& sciezkain);

	/**
	* Funkcja zwiêksza parametry czasu pracy i iloœci wykonanych czynnoœci wybranego przez u¿ytkownika pracownika.
	*/
	void dodaj_nowa_prace_pracownika();

	/**
	* Funkcja usuwa z listy pracownicy pracownika o podanym przez u¿ytkownika numerze identyfikatora.
	*/
	void usun_pracownika_konsola();

	/**
	* Funkcja usuwa z listy pracownicy pracownika o podanym numerze identyfikatora.
	* @param numer_id numer identyfikatora pracownika do usuniêcia
	* @return (1) jeœli uda siê usun¹æ pracownika o podanym numerze id, (0) gdy nie mo¿na usun¹æ danego pracownika (pracownik nie istnieje)
	*/
	void usun_pracownika(int numer_id);

	/**
	* Funkcja zmienia wybrane przez u¿ytkownika parametry programu na nowe podane przez niego.
	*/
	void nowe_parametry_programu_konsola();

	/**
	* Funkcja wyœwietla w konsoli parametry programu.
	*/
	void wyswietl_parametry_programu();

	/**
	* Funkcja pobiera od u¿ytkownika nazwe pliku, do jakiego ma zapisaæ listê pracowników i zapisuje j¹.
	*/
	void zapisz_liste_konsola();

	/**
	* Funkcja pobiera od u¿ytkownika nazwe pliku, do jakiego ma zapisaæ stan programu.
	*/
	void zapisz_plik_konsola(bool norm = 1);

	/**
	* Operator strumieniowy wyjœcia klasy menu, zwraca parametry menu do strumienia wyjœciowego.
	* @param os referencja na strumieñ wyjœciowy
	* @note operator wykorzystywany przy zapisie do pliku
	*/
	ostream& operator<<(ostream& os);

	/**
	* Operator strumieniowy wejœcia klasy menu, ustawia parametry menu z danych pochodz¹cych ze strumienia wejœciowego.
	* @param os referencja na strumieñ wejœciowy
	* @note operator wykorzystywany przy zapisie do pliku
	*/
	istream& operator>>(istream& is);

	/**
	* Funkcja ustawia wartoœæ pola obecny_miesiac na obliczony wed³ug obecnego dnia miesi¹c.
	*/
	void ustaw_miesiac();

	/**
	* Funkcja ustawia wartoœæ pola obecny_tydzien na obliczony wed³ug obecnego dnia tydzieñ.
	*/
	void ustaw_tydzien();

	/**
	* Funkcja zmienia obecny_dzieñ na wybrany (nastêpny, poprzedni, lub downolny dzieñ roku).
	*/
	void zmien_dzien();

	/**
	* Funkcja ustawia dni, tygodnie i miesi¹ce pracowników.
	*/
	void ustaw_dzien_tydzien_miesiac_rok_pracownikow();

	/**
	* Funkcja wyœwietla czas pracy wybranego pracownika z wybranego okresu.
	*/
	void pokaz_wybrany_czas_konsola();

	/**
	* Funkcja oblicza obecny dzieñ tygodnia i zwraca jego numer.
	* @return numer obecnego dnia tygodnia
	*/
	int oblicz_dzien_tygodnia();

	/**
	* Funkcja oblicza dzieñ tygodnia i zwraca jego nazwe.
	* @paranm nr_dnia numer dnia
	* @return nazwa dnia tygodnia
	*/
	string dzien_tygodnia_nazwa(int nr_dnia);

	/**
	* Funkcja zwraca nazwê okresu czasu, który jest obecnie wyœwietlany na liœcie pracowników.
	* @return nazwa okresu czas, za jaki jest wyœwietlana lista pracowników
	*/
	string wyswietlanie_nazwa();

	/**
	* Funkcja oblicza statystyki i wywo³uje funkcjê wyswietl_statystyki_konsola, która je wyœwietla.
	*/
	void wyswietl_statystyki();

	/**
	* Funkcja wyœwietla statystyki, podane jako jej parametry.
	* @param nazwa nazwa czego dotyczc¹ parametry statystyczne
	* @param srednia wartoœæ œrednia
	* @param var wariancja
	* @param ods odchylenie standardowe
	* @param max maksymalna wartoœæ
	* @param min minimalna wartoœc
	* @param medb okreœla, czy podana jest mediana
	* @param med mediana
	*/
	void wyswietl_statystyki_konsola(const string& nazwa, double srednia, double var, double ods, double max, double min, bool medb = 0, double med = 0.0);

	/**
	* Funkcja usuwa wszystkich pracowników z listy.
	*/
	void wyczysc_liste();

	/**
	* Funkcja wyœwietla wszystkie pliki zapisu, znalezione w katalogu z programem.
	*/
	void wyswietl_pliki_zapisu();

	/**
	* Funkcja szuka w katalogu z programem plików zapisu i dodaje ich nazwy do wektora.
	* @param vs wektor stringów, do którego dodawane s¹ nazwy znalezionych plików
	*/
	void znajdz_pliki_zapisu(vector<std::string> &vs);

	/**
	* Funkcja inkrementuje lub dekrementuje iterator listy.
	* @param i iterator
	* @param plus_minus gdy 1 ++, 0 --
	*/
	void kolejny(lista::IteratorTS& i, bool plus_minus);

	/**
	* Funkcja zapisuje parametry programu do pliku o podanej przez u¿ytkownika nazwie.
	*/
	void zapisz_parametry_plik();

	/**
	* Funkcja wczytuje parametry programu z pliku o podanej przez u¿ytkownika nazwie.
	*/
	void wczytaj_parametry_plik();
};
