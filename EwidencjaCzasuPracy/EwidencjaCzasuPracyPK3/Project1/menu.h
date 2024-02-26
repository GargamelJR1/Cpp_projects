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
* Klasa s�u��ca do obs�ugi menu i programu. Menu obs�ugiwane jest poprzez wpisywanie znak�w z klawiatury. Klasa jest oparta o wzorzec singleton.
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
	const bool LOG = 0; // sta�a decyduj�ca, czy b�d� tworzone logi
	int obecny_dzien = 1;
	int obecny_tydzien = 1;
	int obecny_miesiac = 1;
	int dzien_miesiaca = 1;
	int dzien_tydzien_miesiac_rok = 1;

	/**
	* Konstruktor menu, prywatny, inicjalizuje pola obiektu warto�ci� 0. Konstruktor jest wywo�ywany przez publiczn� metod� klasy
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
	* Funkcja statyczna, tworz�c� obiekt typu menu
	* @param LOG parametr okre�laj�cy, czy maj� by� zapisywane logi do pliku, warto�� domy�lna 0 oznacza brak log�w
	*/
	static menu& utworz_menu(const bool LOG = 0) {
		static menu Menu(LOG);
		return Menu;
	}

	/**
	* Funkcja ustawia warto�ci p�l obiektu menu.
	* @param plnperhstd p�aca godzinowa za godziny standardowe
	* @param plnperhdod p�aca godzinowa za godziny dodatkowe
	* @param wiwc wymagana ilo�� wykonanej czynno�ci
	* @param wcp wymagany czas pracy
	* @param pw wymagana wydajno�� pracownika
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
	* Funkcja zwraca warto�ci p�l obiektu menu w formie tuple.
	* @return warto�ci menu
	*/
	auto get_wartosci_menu() const {
		return make_tuple(pln_per_godzina_std, pln_per_godzina_dod, wymagana_ilosc_wykonanej_czynnosci, wymagany_czas_pracy, prog_wydajnosci, pierwszy_dzien_roku);
	}

	/**
	* Funkcja wy�wietla i obs�uguje menu programu.
	* @return (1) je�li program ma by� kontynuowany, (0) je�li u�ytkownik chce wyj�� z programu
	*/
	bool wyswietl_menu();

	/**
	* Funkcja pobiera od u�ytkownika i ustawia parametry programu.
	* @param ktory_parametr cyfra 1-7, wyznacza, kt�re parametry proramu edytowa�
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
	* Funkcja tworzy nowego pracownika o podanych przez u�ytkownika parametrach i dodaje go do listy pracownicy.
	*/
	void dodaj_pracownika_konsola();

	/**
	* Funkcja pobiera od u�ytkownika nazwe pliku do wczytania i wczytuje go.
	*/
	void wczytaj_plik_konsola(bool norm = 1);

	/**
	* Funkcja wysy�a sformatowan� list� pracownik�w do strumienia wyj�ciowego.
	* @param ofs wyj�ciowy strumie�
	* @note funkcja wy�wietla pracownik�w zgodnych z aktualnymi parametrami wy�wietlania, wysw_czas: (2) - czas pracy poni�ej wymaganego,
	(1) - czas pracy spe�nia norm�, (0) - brak sprawdzania czasu pracy, wysw_wyd: (2) - wydajno�� pracy poni�ej wymaganej,
	(1) - wydajno�� pracy spe�nia norm�, (0) - brak sprawdzania wydajno�ci pracy.
	*/
	void wyswietl_liste_pracownikow(ostream& ofs);

	/**
	* Funkcja zmienia wybrane parametry pracownika.
	* @param wybor wyb�r parametru, kt�ry ma by� zmieniony 1-10 (1 - imi�, 2 - nazwisko, 3 - wiek, 4 - dni, 5 - czas std, 6 - czas dod, 7 - wymagana
	  ilosc czynnosci, 8 - wykonana ilo�� czynno�ci, 9 - stawka godzinowa std, 10 - stawka godzinowa dod)
	* @param PR wska�nik na edytowanego pracownika
	* @param ed_string nowa warto��, nadpisuj�ca parametr w formacie string
	* @param ed_int nowa warto��, nadpisuj�ca parametr w formacie int
	* @param ed_double nowa warto��, nadpisuj�ca parametr w formacie double
	* @return (1) je�li uda si� edytowa� pracownika lub (0), je�li si� nie uda
	*/
	bool edytuj_pracownika(int wybor, pracownik* PR, const string& ed_string = " ", int ed_int = 0, double ed_double = 0);

	/**
	* Funkcja szuka w wektorze pracownicy pracownika o podanym numerze id.
	* @param numer_id numer identyfikacyjny pracownika do znalezienia
	* @return (1) je�li pracownika istnieje lub (0) je�li nie ma pracownika o podanym numerze id
	* @note funkcja zapisuje logi do pliku
	*/
	bool czy_istnieje_pracownik(int numer_id);

	/**
	* Funkcja edytuje okre�lone przez u�ytkownika parametry pracownika o numerze identyfikacyjnym podanym przez u�ytkownika.
	*/
	void edytuj_pracownika_konsola();

	/**
	* Funkcja zapisuje dane programu do pliku o �cie�ce podanej w parametrze.
	* @param sciezkaout �cie�ka do zapisywanego pliku
	*/
	void zapisz_do_pliku(const string& sciezkaout);

	/**
	* Funkcja pobiera od u�ytkownika �cie�k� do pliku i zwraca j� w formacie string.
	* @param zapis (1) �cie�ka do pliku wyj�ciowego lub (0) wej�ciowego
	* @return sciezka do pliku w formacie string
	*/
	string ustaw_sciezke_zapisu_odczytu(bool zapis);

	/**
	* Funkcja ustawia wybrane przez u�ytkownika parametry wy�wietlania.
	*/
	void parametry_wyswietlania();

	/**
	* Funkcja ostrzega u�ytkownika o mo�liwej utracie danych i wczytuje nowy plik zapisu lub powraca do menu.
	*/
	void wczytaj_nowy_plik_konsola();

	/**
	* Funkcja ustawia warto�� pocz�tkowego numeru identyfikatora dla kolejnych pracownik�w na najwy�szy obecnie u�ywany numer identyfikatora.
	*/
	void ustaw_id();

	/**
	* Funkcja wczytuje plik o �cie�ce podanej w parametrze.
	* @param sciezkain �cie�ka do pliku, kt�ry ma by� wczytany
	* return (1) je�li uda si� wczyta� plik, (0) gdy nie mo�na wczyta� pliku
	*/
	bool wczytaj_plik(const string& sciezkain);

	/**
	* Funkcja zwi�ksza parametry czasu pracy i ilo�ci wykonanych czynno�ci wybranego przez u�ytkownika pracownika.
	*/
	void dodaj_nowa_prace_pracownika();

	/**
	* Funkcja usuwa z listy pracownicy pracownika o podanym przez u�ytkownika numerze identyfikatora.
	*/
	void usun_pracownika_konsola();

	/**
	* Funkcja usuwa z listy pracownicy pracownika o podanym numerze identyfikatora.
	* @param numer_id numer identyfikatora pracownika do usuni�cia
	* @return (1) je�li uda si� usun�� pracownika o podanym numerze id, (0) gdy nie mo�na usun�� danego pracownika (pracownik nie istnieje)
	*/
	void usun_pracownika(int numer_id);

	/**
	* Funkcja zmienia wybrane przez u�ytkownika parametry programu na nowe podane przez niego.
	*/
	void nowe_parametry_programu_konsola();

	/**
	* Funkcja wy�wietla w konsoli parametry programu.
	*/
	void wyswietl_parametry_programu();

	/**
	* Funkcja pobiera od u�ytkownika nazwe pliku, do jakiego ma zapisa� list� pracownik�w i zapisuje j�.
	*/
	void zapisz_liste_konsola();

	/**
	* Funkcja pobiera od u�ytkownika nazwe pliku, do jakiego ma zapisa� stan programu.
	*/
	void zapisz_plik_konsola(bool norm = 1);

	/**
	* Operator strumieniowy wyj�cia klasy menu, zwraca parametry menu do strumienia wyj�ciowego.
	* @param os referencja na strumie� wyj�ciowy
	* @note operator wykorzystywany przy zapisie do pliku
	*/
	ostream& operator<<(ostream& os);

	/**
	* Operator strumieniowy wej�cia klasy menu, ustawia parametry menu z danych pochodz�cych ze strumienia wej�ciowego.
	* @param os referencja na strumie� wej�ciowy
	* @note operator wykorzystywany przy zapisie do pliku
	*/
	istream& operator>>(istream& is);

	/**
	* Funkcja ustawia warto�� pola obecny_miesiac na obliczony wed�ug obecnego dnia miesi�c.
	*/
	void ustaw_miesiac();

	/**
	* Funkcja ustawia warto�� pola obecny_tydzien na obliczony wed�ug obecnego dnia tydzie�.
	*/
	void ustaw_tydzien();

	/**
	* Funkcja zmienia obecny_dzie� na wybrany (nast�pny, poprzedni, lub downolny dzie� roku).
	*/
	void zmien_dzien();

	/**
	* Funkcja ustawia dni, tygodnie i miesi�ce pracownik�w.
	*/
	void ustaw_dzien_tydzien_miesiac_rok_pracownikow();

	/**
	* Funkcja wy�wietla czas pracy wybranego pracownika z wybranego okresu.
	*/
	void pokaz_wybrany_czas_konsola();

	/**
	* Funkcja oblicza obecny dzie� tygodnia i zwraca jego numer.
	* @return numer obecnego dnia tygodnia
	*/
	int oblicz_dzien_tygodnia();

	/**
	* Funkcja oblicza dzie� tygodnia i zwraca jego nazwe.
	* @paranm nr_dnia numer dnia
	* @return nazwa dnia tygodnia
	*/
	string dzien_tygodnia_nazwa(int nr_dnia);

	/**
	* Funkcja zwraca nazw� okresu czasu, kt�ry jest obecnie wy�wietlany na li�cie pracownik�w.
	* @return nazwa okresu czas, za jaki jest wy�wietlana lista pracownik�w
	*/
	string wyswietlanie_nazwa();

	/**
	* Funkcja oblicza statystyki i wywo�uje funkcj� wyswietl_statystyki_konsola, kt�ra je wy�wietla.
	*/
	void wyswietl_statystyki();

	/**
	* Funkcja wy�wietla statystyki, podane jako jej parametry.
	* @param nazwa nazwa czego dotyczc� parametry statystyczne
	* @param srednia warto�� �rednia
	* @param var wariancja
	* @param ods odchylenie standardowe
	* @param max maksymalna warto��
	* @param min minimalna warto�c
	* @param medb okre�la, czy podana jest mediana
	* @param med mediana
	*/
	void wyswietl_statystyki_konsola(const string& nazwa, double srednia, double var, double ods, double max, double min, bool medb = 0, double med = 0.0);

	/**
	* Funkcja usuwa wszystkich pracownik�w z listy.
	*/
	void wyczysc_liste();

	/**
	* Funkcja wy�wietla wszystkie pliki zapisu, znalezione w katalogu z programem.
	*/
	void wyswietl_pliki_zapisu();

	/**
	* Funkcja szuka w katalogu z programem plik�w zapisu i dodaje ich nazwy do wektora.
	* @param vs wektor string�w, do kt�rego dodawane s� nazwy znalezionych plik�w
	*/
	void znajdz_pliki_zapisu(vector<std::string> &vs);

	/**
	* Funkcja inkrementuje lub dekrementuje iterator listy.
	* @param i iterator
	* @param plus_minus gdy 1 ++, 0 --
	*/
	void kolejny(lista::IteratorTS& i, bool plus_minus);

	/**
	* Funkcja zapisuje parametry programu do pliku o podanej przez u�ytkownika nazwie.
	*/
	void zapisz_parametry_plik();

	/**
	* Funkcja wczytuje parametry programu z pliku o podanej przez u�ytkownika nazwie.
	*/
	void wczytaj_parametry_plik();
};
