#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;


// $$$$$$$$$$$$$$$$$$$ FUNKCJE Z KONSOL¥ $$$$$$$$$$$$$$$$$$$


/** Funkcja usuwa wybrany przez u¿ytkownika wyraz w wybranym miejscu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
*/
void usun_wiersz_konsola(list<list<char>>& wiersze);

/** Funkcja dodaje pusty wiersz po okreœlonym przez uzytkownika
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
*/
void dodaj_wiersz_konsola(list<list<char>>& wiersze);

/** Funkcja usuwa okreœlony przez uzytkownika wyraz
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
*/
void usun_wyraz_konsola(list<list<char>>& wiersze);

/** Funkcja zamienia wybrany przez u¿ytkownika wyraz w wybranym miejscu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
*/
void zamien_wyraz_konsola(list<list<char>>& wiersze,const int max_znakow);

/** Funkcja dodaje wybrany przez u¿ytkownika wyraz w wybranym miejscu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param max_w_W limit znaków w wierszu
*/
void dodaj_wyraz_konsola(list<list<char>>& wiersze, int max_w_W);

/** Funkcja wczytuje plik o podanej œcie¿ce do edytora
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param sciezkain scie¿ka do pliku
*/
void wczytaj_plik_konsola(list<list<char>>& wiersze, string& sciezkain);

/** Funkcja wczytuje plik o podanej przez u¿ytkownika œcie¿ce do edytora
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param sciezkain scie¿ka do pliku
*/
void wczytaj_nowy_plik_konsola(list<list<char>>& wiersze, string& sciezkain);

/** Funkcja dodaje pusty wiersz po okreœlonym numerem wierszu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param czy_nr_w zmienna okreœlaj¹ca, czy tekst ma byæ wyœwietlany z numerami wierszy czy bez, wartoœæ domyœlna 0 oznacza brak wyœwietlania numerów wierszy
*/
void wyswietl_tekst(list<list<char>>& wiersze, const bool czy_nr_w = 0);

/** Funkcja wyœwietla statyki tekstu
* @param wiersze tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
*/
void statystyki_konsola(list<list<char>>& wiersze);

/** Funkcja zmienia limit znakow w wierszu na nowy, okreslony przez uzytkownika
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param max_znakow maksymalna iloœæ znaków w wierszu
*/
void zmiana_limitu_znakow(list<list<char>>& wiersze, int& max_znakow);

/** Funkcja zapisuje tekst do okreœlonego pliku
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param sciezkaout sciezka do pliku wyjœciowego
*/
void zapisz_plik_konsola(list<list<char>>& wiersze, const string& sciezkaout);


// $$$$$$$$$$$$$$$$$$$ OBS£UGA PLIKÓW $$$$$$$$$$$$$$$$$$$


/** Funkcja zapisuje tekst do pliku
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param sicezkaout sciezka do pliku wyjœciowego
* @param nr_wierszy zmienna okreœlaj¹ca, czy tekst ma byæ zapisany z numerami wierszy czy bez, wartoœæ domyœlna 0 oznacza brak wyœwietlania numerów wierszy
*/
void zapisz_plik(list<list<char>>& wiersze, const string& sciezkaout, const bool nr_wierszy = 0);

/** Funkcja sprawdza czy istnieje plik o podanej nazwie
* @param sciezkain sciezka do wczytanego pliku lub jego nazwa
* @return true, jeœli plik istnieje, false, gdy nie istnieje
*/
bool czy_istnieje_plik(const string& sciezkain);

/** Funkcja wczytuje tekst z okreœlonego pliku
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param sciezkain œcie¿ka do pliku wejœciowego
*/
void wczytaj_plik(list<list<char>>& wiersze, string& sciezkain);


// $$$$$$$$$$$$$$$$$$$ FUNKCJE PROGRAMU I POMOCNICZE $$$$$$$$$$$$$$$$$$$


/** Funkcja dodaje pusty wiersz po okreœlonym numerem wierszu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param nr numer wiersza, po którym ma byæ dodany nowy
*/
void dodaj_wiersz(list<list<char>>& wiersze, const int nr);

/** Funkcja dodaje wyraz w okreœlonym przez miejscu
* @param znaki edytowany wiersz w formacie list<char>
* @param max_w_W maksymalna iloœæ znaków w linii, gdy nowy wyraz jest d³u¿szy, jest zwiêkszana
* @param nr nr wiersza, w którym ma byc dodany wyraz
* @param wyraz wyraz do dodania
* @param wybor wybor czy wyraz ma byc dodany na pocz¹tku (1), na koñcu wiersza (2), czy po innym wyrazie (3)
* @param wystapienie po którym wyst¹pieniu danego wyrazu w wierszu (na liœcie znaków) ma byæ dodany nowy
* @param wyraz_po wyraz, po którym ma byæ dodany nowy
*/
void dodaj_wyraz(list<char>& znaki, int max_w_W, const int nr, string& wyraz, const int wybor, const int wystapienie = 1, const string& wyraz_po = "");

/** Funkcja wyœwietla statyki tekstu
* @param wiersze tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param w zmienna, której wartoœæ zostanie zmieniona na liczbê wyrazów w tekœcie
* @param zs zmienna, której wartoœæ zostanie zmieniona na liczbê znaków (ze spacjami) w tekœcie
* @param z zmienna, której wartoœæ zostanie zmieniona na liczbê znaków (bez spacji) w tekœcie
*/
void statystyki(list<list<char>>& wiersze, int& w, int& zs, int& z);

/** Funkcja sprawdza, czy wiersze spe³niaj¹ limit znaków i przenosi nadmiarowe znaki do kolejnych
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param max_znakow maksymalna iloœæ znaków w wierszu
*/
void sprawdz_limit_znakow(list<list<char>>& wiersze, const int max_znakow);

/** Funkcja wyrównuje tekst do obu marginesów poprzez dodanie spacji
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param max_znakow maksymalna iloœæ znaków w wierszu
*/
void justowanie(list<list<char>>& wiersze, const int max_znakow);

/** Funkcja usuwa przez u¿ytkownika wiersz
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param nr numer wiersza do usuniêcia
*/
void usun_wiersz(list<list<char>>& wiersze, int nr);

/** Funkcja usuwa lub zamienia podany wyraz
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param wyraz wyraz do zamienienia lub usuniêcia
* @param a zmienna okreœlaj¹ca, gdzie ma byæ zamieniony lub usuniêty wyraz (1 - w ca³ym okreœlonym wierszu, 2 - n-te wyst¹pienie w wierszu, 3 -  w ca³ym tekœcie)
* @param wystapienie n-te wyst¹pienie wyrazu w wierszu (na liœcie znaków)
* @param nr_wiersza nr wiersza z wyrazem
* @param zamien jeœli wartoœæ true, wyraz jest zamieniany, a false usuwany
* @param n_wyraz nowy wyraz, jeœli stary jest zamieniany
*/
void usun_lub_zamien_wyraz(list<list<char>>& wiersze, const string& wyraz, const int a, const int wystapienie = 1, const int nr_wiersza = 0, const bool zamien = 0, const string& n_wyraz = "");

/** Funkcja ustawia poczatkowy limit znakow w wierszu zgodnie z najdluzszym wierszem
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param max_znakow maksymalna iloœæ znaków w wierszu
*/
void ustaw_limit(list<list<char>>& wiersze, int& max_znakow);

/** Funkcja zwraca d³ugoœæ najd³u¿szego wyrazu w tekœcie
* @param wiersze przeszukiwany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
*/
int dlugosc_najdluzszego_wyrazu(list<list<char>>& wiersze);

/** Funkcja ustawia sciê¿kê do zapisywanego pliku dla funkcji zapisuj¹cej
* @param sciezkaout sciezka do wczytanego pliku lub jego nazwa, która jest zamieniona na inn¹ lub pozostaje niezmieniona
*/
void ustaw_sciezke_zapisu(string& sciezkaout);

/** Funkcja pobiera od u¿ytkownika cyfrê z zakresu od 1 do argumentu ile, pozwala na wybór ró¿nych opcji w programie
* @param ile maksymalna cyfra do której ma byæ mo¿liwy wybór przez u¿ytkownika
* @return wybrana cyfra
*/
int wybor1zN(const int ile);

/** Funkcja wyszukuje wyraz i przemieszcza iterator na jego koniec
* @param Z iteraor na element przeszukiwanej listy znaków
* @param wyraz wyraz do znalezienia
* @param znaki lista znaków z wyrazem do znalezienia
* @return true, jeœli wyraz wystêpuje w danej liœcie, false jeœli nie ma go w danej liœcie
*/
bool znajdz_wyraz(list<char>::iterator& Z, const string& wyraz, const list<char>& znaki);

/** Funcja zlicza iloœæ wyst¹pieñ danego wyrazu w wierszu
* @param znaki jeden wiersz tekstu w formacie listy znaków
* @param wyraz wyraz, którego wyst¹pienia s¹ zliczane
* @return iloœæ wyst¹pieñ wyrazu w wierszu
*/
int ilosc_wystapien_w_wierszu(list<char>& znaki, const string& wyraz);

/** Funkcja zwraca wybrany przez u¿ytkownika numer wiersza 
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @return wybrany numer wiersza
*/
int ustaw_nr_wiersza(list<list<char>>& wiersze);

/** Funkcja przesuwa iterator na wiersz o podanym numerze
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param W iterator na wiersz (element listy wierszów)
* @param nr_wiersza numer wiersza 
*/
void przewin_do_wiersza(list<list<char>>& wiersze, std::list<list<char>>::iterator& W, const int nr_wiersza);

/** Funkcja wysy³a ca³y tekst do ostream
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param s strumieñ wyjœciowy
* @param nr_wiersz numer wiersza
*/
void przewin_tekst(list<list<char>>& wiersze, ostream& s, const bool nr_wiersz = 0);

/** Funkcja obs³uguje dzia³anie funkcji usun_lub_zamien_wyraz
* @param n_wyraz nowy wyraz 
* @param znaki wiersz tekstu
* @param wyraz wyraz do usuniêcia/zast¹pienia 
* @param dlg_wyrazu d³ugoœæ wyrazu do usuniecia/zast¹pienia
* @param zamien jeœli wartoœæ true, wyraz jest zamieniany, a false usuwany
* @param Z iterator do znaku w wierszu
*/
void zamien_usun_wnetrze(const string& n_wyraz, list<char>& znaki, const string& wyraz, const int dlg_wyrazu, const bool zamien, list<char>::iterator& Z);


// $$$$$$$$$$$$$$$$$$$ MENU $$$$$$$$$$$$$$$$$$$


/** Funkcja wyœwietla menu
* @param wiersze edytowany tekst w formacie list<list<char>>, lista wierszów, zawieraj¹ca listy znaków
* @param sciezkain scie¿ka do pliku wejœciowego
* @param max_znakow maksymalna iloœæ znaków w wierszu
* @param czy_nr_w wartoœæ bool, potrzebna do wyœwietlania tekstu z numerem wiersza lub bez
* @return true, gdy u¿ytkownik chce zamkn¹æ program, w innych przypadkach zwraca 1
*/
bool menu(list<list<char>>& wiersze, string& sciezkain, int& max_znakow, bool& czy_nr_w);