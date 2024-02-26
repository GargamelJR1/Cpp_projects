#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;


// $$$$$$$$$$$$$$$$$$$ FUNKCJE Z KONSOL� $$$$$$$$$$$$$$$$$$$


/** Funkcja usuwa wybrany przez u�ytkownika wyraz w wybranym miejscu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
*/
void usun_wiersz_konsola(list<list<char>>& wiersze);

/** Funkcja dodaje pusty wiersz po okre�lonym przez uzytkownika
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
*/
void dodaj_wiersz_konsola(list<list<char>>& wiersze);

/** Funkcja usuwa okre�lony przez uzytkownika wyraz
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
*/
void usun_wyraz_konsola(list<list<char>>& wiersze);

/** Funkcja zamienia wybrany przez u�ytkownika wyraz w wybranym miejscu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
*/
void zamien_wyraz_konsola(list<list<char>>& wiersze,const int max_znakow);

/** Funkcja dodaje wybrany przez u�ytkownika wyraz w wybranym miejscu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param max_w_W limit znak�w w wierszu
*/
void dodaj_wyraz_konsola(list<list<char>>& wiersze, int max_w_W);

/** Funkcja wczytuje plik o podanej �cie�ce do edytora
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param sciezkain scie�ka do pliku
*/
void wczytaj_plik_konsola(list<list<char>>& wiersze, string& sciezkain);

/** Funkcja wczytuje plik o podanej przez u�ytkownika �cie�ce do edytora
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param sciezkain scie�ka do pliku
*/
void wczytaj_nowy_plik_konsola(list<list<char>>& wiersze, string& sciezkain);

/** Funkcja dodaje pusty wiersz po okre�lonym numerem wierszu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param czy_nr_w zmienna okre�laj�ca, czy tekst ma by� wy�wietlany z numerami wierszy czy bez, warto�� domy�lna 0 oznacza brak wy�wietlania numer�w wierszy
*/
void wyswietl_tekst(list<list<char>>& wiersze, const bool czy_nr_w = 0);

/** Funkcja wy�wietla statyki tekstu
* @param wiersze tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
*/
void statystyki_konsola(list<list<char>>& wiersze);

/** Funkcja zmienia limit znakow w wierszu na nowy, okreslony przez uzytkownika
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param max_znakow maksymalna ilo�� znak�w w wierszu
*/
void zmiana_limitu_znakow(list<list<char>>& wiersze, int& max_znakow);

/** Funkcja zapisuje tekst do okre�lonego pliku
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param sciezkaout sciezka do pliku wyj�ciowego
*/
void zapisz_plik_konsola(list<list<char>>& wiersze, const string& sciezkaout);


// $$$$$$$$$$$$$$$$$$$ OBS�UGA PLIK�W $$$$$$$$$$$$$$$$$$$


/** Funkcja zapisuje tekst do pliku
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param sicezkaout sciezka do pliku wyj�ciowego
* @param nr_wierszy zmienna okre�laj�ca, czy tekst ma by� zapisany z numerami wierszy czy bez, warto�� domy�lna 0 oznacza brak wy�wietlania numer�w wierszy
*/
void zapisz_plik(list<list<char>>& wiersze, const string& sciezkaout, const bool nr_wierszy = 0);

/** Funkcja sprawdza czy istnieje plik o podanej nazwie
* @param sciezkain sciezka do wczytanego pliku lub jego nazwa
* @return true, je�li plik istnieje, false, gdy nie istnieje
*/
bool czy_istnieje_plik(const string& sciezkain);

/** Funkcja wczytuje tekst z okre�lonego pliku
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param sciezkain �cie�ka do pliku wej�ciowego
*/
void wczytaj_plik(list<list<char>>& wiersze, string& sciezkain);


// $$$$$$$$$$$$$$$$$$$ FUNKCJE PROGRAMU I POMOCNICZE $$$$$$$$$$$$$$$$$$$


/** Funkcja dodaje pusty wiersz po okre�lonym numerem wierszu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param nr numer wiersza, po kt�rym ma by� dodany nowy
*/
void dodaj_wiersz(list<list<char>>& wiersze, const int nr);

/** Funkcja dodaje wyraz w okre�lonym przez miejscu
* @param znaki edytowany wiersz w formacie list<char>
* @param max_w_W maksymalna ilo�� znak�w w linii, gdy nowy wyraz jest d�u�szy, jest zwi�kszana
* @param nr nr wiersza, w kt�rym ma byc dodany wyraz
* @param wyraz wyraz do dodania
* @param wybor wybor czy wyraz ma byc dodany na pocz�tku (1), na ko�cu wiersza (2), czy po innym wyrazie (3)
* @param wystapienie po kt�rym wyst�pieniu danego wyrazu w wierszu (na li�cie znak�w) ma by� dodany nowy
* @param wyraz_po wyraz, po kt�rym ma by� dodany nowy
*/
void dodaj_wyraz(list<char>& znaki, int max_w_W, const int nr, string& wyraz, const int wybor, const int wystapienie = 1, const string& wyraz_po = "");

/** Funkcja wy�wietla statyki tekstu
* @param wiersze tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param w zmienna, kt�rej warto�� zostanie zmieniona na liczb� wyraz�w w tek�cie
* @param zs zmienna, kt�rej warto�� zostanie zmieniona na liczb� znak�w (ze spacjami) w tek�cie
* @param z zmienna, kt�rej warto�� zostanie zmieniona na liczb� znak�w (bez spacji) w tek�cie
*/
void statystyki(list<list<char>>& wiersze, int& w, int& zs, int& z);

/** Funkcja sprawdza, czy wiersze spe�niaj� limit znak�w i przenosi nadmiarowe znaki do kolejnych
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param max_znakow maksymalna ilo�� znak�w w wierszu
*/
void sprawdz_limit_znakow(list<list<char>>& wiersze, const int max_znakow);

/** Funkcja wyr�wnuje tekst do obu margines�w poprzez dodanie spacji
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param max_znakow maksymalna ilo�� znak�w w wierszu
*/
void justowanie(list<list<char>>& wiersze, const int max_znakow);

/** Funkcja usuwa przez u�ytkownika wiersz
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param nr numer wiersza do usuni�cia
*/
void usun_wiersz(list<list<char>>& wiersze, int nr);

/** Funkcja usuwa lub zamienia podany wyraz
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param wyraz wyraz do zamienienia lub usuni�cia
* @param a zmienna okre�laj�ca, gdzie ma by� zamieniony lub usuni�ty wyraz (1 - w ca�ym okre�lonym wierszu, 2 - n-te wyst�pienie w wierszu, 3 -  w ca�ym tek�cie)
* @param wystapienie n-te wyst�pienie wyrazu w wierszu (na li�cie znak�w)
* @param nr_wiersza nr wiersza z wyrazem
* @param zamien je�li warto�� true, wyraz jest zamieniany, a false usuwany
* @param n_wyraz nowy wyraz, je�li stary jest zamieniany
*/
void usun_lub_zamien_wyraz(list<list<char>>& wiersze, const string& wyraz, const int a, const int wystapienie = 1, const int nr_wiersza = 0, const bool zamien = 0, const string& n_wyraz = "");

/** Funkcja ustawia poczatkowy limit znakow w wierszu zgodnie z najdluzszym wierszem
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param max_znakow maksymalna ilo�� znak�w w wierszu
*/
void ustaw_limit(list<list<char>>& wiersze, int& max_znakow);

/** Funkcja zwraca d�ugo�� najd�u�szego wyrazu w tek�cie
* @param wiersze przeszukiwany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
*/
int dlugosc_najdluzszego_wyrazu(list<list<char>>& wiersze);

/** Funkcja ustawia sci�k� do zapisywanego pliku dla funkcji zapisuj�cej
* @param sciezkaout sciezka do wczytanego pliku lub jego nazwa, kt�ra jest zamieniona na inn� lub pozostaje niezmieniona
*/
void ustaw_sciezke_zapisu(string& sciezkaout);

/** Funkcja pobiera od u�ytkownika cyfr� z zakresu od 1 do argumentu ile, pozwala na wyb�r r�nych opcji w programie
* @param ile maksymalna cyfra do kt�rej ma by� mo�liwy wyb�r przez u�ytkownika
* @return wybrana cyfra
*/
int wybor1zN(const int ile);

/** Funkcja wyszukuje wyraz i przemieszcza iterator na jego koniec
* @param Z iteraor na element przeszukiwanej listy znak�w
* @param wyraz wyraz do znalezienia
* @param znaki lista znak�w z wyrazem do znalezienia
* @return true, je�li wyraz wyst�puje w danej li�cie, false je�li nie ma go w danej li�cie
*/
bool znajdz_wyraz(list<char>::iterator& Z, const string& wyraz, const list<char>& znaki);

/** Funcja zlicza ilo�� wyst�pie� danego wyrazu w wierszu
* @param znaki jeden wiersz tekstu w formacie listy znak�w
* @param wyraz wyraz, kt�rego wyst�pienia s� zliczane
* @return ilo�� wyst�pie� wyrazu w wierszu
*/
int ilosc_wystapien_w_wierszu(list<char>& znaki, const string& wyraz);

/** Funkcja zwraca wybrany przez u�ytkownika numer wiersza 
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @return wybrany numer wiersza
*/
int ustaw_nr_wiersza(list<list<char>>& wiersze);

/** Funkcja przesuwa iterator na wiersz o podanym numerze
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param W iterator na wiersz (element listy wiersz�w)
* @param nr_wiersza numer wiersza 
*/
void przewin_do_wiersza(list<list<char>>& wiersze, std::list<list<char>>::iterator& W, const int nr_wiersza);

/** Funkcja wysy�a ca�y tekst do ostream
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param s strumie� wyj�ciowy
* @param nr_wiersz numer wiersza
*/
void przewin_tekst(list<list<char>>& wiersze, ostream& s, const bool nr_wiersz = 0);

/** Funkcja obs�uguje dzia�anie funkcji usun_lub_zamien_wyraz
* @param n_wyraz nowy wyraz 
* @param znaki wiersz tekstu
* @param wyraz wyraz do usuni�cia/zast�pienia 
* @param dlg_wyrazu d�ugo�� wyrazu do usuniecia/zast�pienia
* @param zamien je�li warto�� true, wyraz jest zamieniany, a false usuwany
* @param Z iterator do znaku w wierszu
*/
void zamien_usun_wnetrze(const string& n_wyraz, list<char>& znaki, const string& wyraz, const int dlg_wyrazu, const bool zamien, list<char>::iterator& Z);


// $$$$$$$$$$$$$$$$$$$ MENU $$$$$$$$$$$$$$$$$$$


/** Funkcja wy�wietla menu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wiersz�w, zawieraj�ca listy znak�w
* @param sciezkain scie�ka do pliku wej�ciowego
* @param max_znakow maksymalna ilo�� znak�w w wierszu
* @param czy_nr_w warto�� bool, potrzebna do wy�wietlania tekstu z numerem wiersza lub bez
* @return true, gdy u�ytkownik chce zamkn�� program, w innych przypadkach zwraca 1
*/
bool menu(list<list<char>>& wiersze, string& sciezkain, int& max_znakow, bool& czy_nr_w);