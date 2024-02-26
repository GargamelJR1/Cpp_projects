#include "funkcje.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;


// $$$$$$$$$$$$$$$$$$$ FUNKCJE Z KONSOL¥ $$$$$$$$$$$$$$$$$$$


void usun_wiersz_konsola(list<list<char>>& wiersze) {
	cout << "Ktory wiersz chcesz usunac?  ";
	usun_wiersz(wiersze, ustaw_nr_wiersza(wiersze));
}

void dodaj_wiersz_konsola(list<list<char>>& wiersze) {
	cout << "Po, ktorym wierszu chcesz dodac pusty?  ";
	dodaj_wiersz(wiersze, ustaw_nr_wiersza(wiersze));
}

void zapisz_plik_konsola(list<list<char>>& wiersze, const string& sciezkaout) {
	cout << "1 - Zapis pliku z numerami wierszy, 2 - zapis pliku bez numerow wierszy, 3 - anuluj  ";
	bool nr_wierszy = 0;
	switch (wybor1zN(3)) {
	case 1:
		nr_wierszy = 1;
		break;
	case 3:
		return;
		break;
	}
	zapisz_plik(wiersze, sciezkaout, nr_wierszy);
	cout << "Pomyslnie zapisano plik" << endl;
}

void dodaj_wyraz_konsola(list<list<char>>& wiersze, int max_w_W) {
	string wyraz;
	list<char> znaki;

	cout << "Prosze podac wyraz do dodania: ";
	cin >> wyraz;
	cout << "Do ktorego wiersza chesz dodac wyraz? ";
	int nr = ustaw_nr_wiersza(wiersze);
	cout << "Gdzie dodac wyraz?  1 - na poczatku wiersza, 2 - na koncu wiersza, 3 - po innym wyrazie, 4 - anuluj     ";
	int wybor = wybor1zN(4);

	if (wybor == 4) return;
	else {
		auto W = wiersze.begin();
		przewin_do_wiersza(wiersze, W, nr);
		znaki = *W;
		if (wybor == 3) {
			string wyraz_po;
			cout << "Podaj wyraz po ktorym ma byc dodany nowy: ";
			cin >> wyraz_po;
			int ilosc = ilosc_wystapien_w_wierszu(znaki, wyraz_po);
			int wystapienie = 1;
			if (ilosc > 1) {
				cout << "Podany wyraz wystepuje w danym wierszu " << ilosc << " razy. Prosze podac, po ktorym wystapieniu dodac nowy wyraz: ";
				wystapienie = wybor1zN(ilosc);
			}
			else if (ilosc == 0) {
				cout << "Brak podanego wyrazu w wierszu" << endl;
				system("pause");
				return;
			}
			dodaj_wyraz(znaki, max_w_W, nr, wyraz, wybor, wystapienie, wyraz_po);
		}
		else
			dodaj_wyraz(znaki, max_w_W, nr, wyraz, wybor);
		*W = znaki;
	}

}

void wczytaj_nowy_plik_konsola(list<list<char>>& wiersze, string& sciezkain) {
	cout << "Obecnie edytowany tekst zostanie utracony. Czy na pewno chcesz kontynuowac? 1 - kontynuuj, 2 - powrot do menu   ";
	switch (wybor1zN(2)) {
	case 2:
		return;
	case 1:
		wiersze.clear();
		sciezkain.clear();
		wczytaj_plik_konsola(wiersze, sciezkain);
	}

}

void usun_wyraz_konsola(list<list<char>>& wiersze) {
	string wyraz; // zmienna, zawieraj¹ca podany przez u¿ytkownika wyraz do usuniêcia

	cout << "Prosze podac wyraz do usuniecia: ";
	cin >> wyraz; // wczytywanie wyrazu 
	cout << "Gdzie chcesz usunac wyraz?  1 - w calym okreslonym wierszu, 2 - n-te wystapienie w okreslonym wierszu, 3 - w calym tekscie, 4 - ANULUJ      ";
	int a = wybor1zN(4);


	switch (a) {
	case 1:
	{
		int nr = 0; // zmienna przechowuj¹ca numer wiersza
		cout << "Z ktorego wiersza chesz usunac wyraz? ";
		nr = ustaw_nr_wiersza(wiersze);
		usun_lub_zamien_wyraz(wiersze, wyraz, a, 1, nr);
	}
	break;
	case 2:
	{
		int nr = 0; // zmienna przechowuj¹ca numer wiersza
		cout << "Z ktorego wiersza chesz usunac wyraz? ";
		nr = ustaw_nr_wiersza(wiersze);
		auto W = wiersze.begin();
		int ilosc = ilosc_wystapien_w_wierszu(*W, wyraz);
		int wystapienie = 1;
		if (ilosc > 1) {
			cout << "Podany wyraz wystepuje w danym wierszu " << ilosc << " razy. Prosze podac ktore wystapienie wyrazu usunac:  ";
			wystapienie = wybor1zN(ilosc);
		}
		usun_lub_zamien_wyraz(wiersze, wyraz, a, wystapienie, nr);
	}
	break;
	case 3:
	{
		usun_lub_zamien_wyraz(wiersze, wyraz, a);
	}
	break;
	case 4:
	{
		return;
	}
	break;
	}

}

void zamien_wyraz_konsola(list<list<char>>& wiersze, const int max_znakow) {
	string wyraz; // zmienna, zawieraj¹ca podany przez u¿ytkownika wyraz do usuniêcia
	string n_wyraz; // zmienna, zawieraj¹ca nowy wyraz 

	cout << "Prosze podac wyraz do zamienienia: ";
	cin >> wyraz; // wczytywanie wyrazu 
	cout << "Prosze podac nowy wyraz: ";
	cin >> n_wyraz; // wczytanie nowego wyrazu
	if (n_wyraz.size() > max_znakow) {
		cout << "Podany wyraz jest za dlugi, prosze zwiekszyc limit znakow w wierszu i sprobowac ponownie" << endl;
		system("pause");
		return;
	}
	cout << "Gdzie chcesz zamienic wyraz?  1 - w calym okreslonym wierszu, 2 - n-te wystapienie w okreslonym wierszu, 3 - w calym tekscie, 4 - ANULUJ      ";
	int a = wybor1zN(4);

	switch (a) {
	case 1:
	{
		int nr = 0; // zmienna przechowuj¹ca numer wiersza
		cout << "W ktorym wierszu chesz zamienic wyraz? ";
		nr = ustaw_nr_wiersza(wiersze);
		usun_lub_zamien_wyraz(wiersze, wyraz, a, 1, nr, 1, n_wyraz);
	}
	break;
	case 2:
	{
		int nr = 0; // zmienna przechowuj¹ca numer wiersza
		cout << "W ktorym wierszu chesz zamienic wyraz? ";
		nr = ustaw_nr_wiersza(wiersze);
		auto W = wiersze.begin();
		int ilosc = ilosc_wystapien_w_wierszu(*W, wyraz);
		int wystapienie = 1;
		if (ilosc > 1) {
			cout << "Podany wyraz wystepuje w danym wierszu " << ilosc << " razy. Prosze podac ktore wystapienie wyrazu zamienic:  ";
			wystapienie = wybor1zN(ilosc);
		}
		usun_lub_zamien_wyraz(wiersze, wyraz, a, wystapienie, nr, 1, n_wyraz);
	}
	break;
	case 3:
	{
		usun_lub_zamien_wyraz(wiersze, wyraz, a, 1, 1, 1, n_wyraz);
	}
	break;
	case 4:
	{
		return;
	}
	break;
	}
}

void wczytaj_plik_konsola(list<list<char>>& wiersze, string& sciezkain) {
	cout << "Podaj sciezke do pliku wejsciowego   ";
	getline(cin >> ws, sciezkain);
	while (!czy_istnieje_plik(sciezkain)) {
		system("cls");
		cout << "Nie ma takiego pliku" << endl
			<< "Podaj sciezke do pliku wejsciowego   ";
		getline(cin >> ws, sciezkain);
	}
	wczytaj_plik(wiersze, sciezkain); // wczytanie pliku tekstowego
}

void wyswietl_tekst(list<list<char>>& wiersze, const bool czy_nr_w) {
	int nrw = 1; // zmienna pomocnicza, zawieraj¹ca aktualny numer wiersza w ka¿dym obiegu pêtli
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz

	if (!czy_nr_w) {
		przewin_tekst(wiersze, cout);
	}
	// wyœwietlenie tekstu z numerami wierszy
	else {
		przewin_tekst(wiersze, cout, 1);
	}
}

void statystyki_konsola(list<list<char>>& wiersze) {
	int wyrazy = 0, znakis = 0, znaki = 0;
	statystyki(wiersze, wyrazy, znakis, znaki);
	cout << endl << "plik zawiera: " << wyrazy << " wyrazow, " << znakis << " znakow ze spacjami, " << znaki << " znakow bez spacji; najdluzszy wyraz zawiera: " << dlugosc_najdluzszego_wyrazu(wiersze) << " znakow." << endl;
}

void zmiana_limitu_znakow(list<list<char>>& wiersze, int& max_znakow) {
	int temp;

	cout << "UWAGA: Po zmniejszeniu limitu znakow w wierszu, nadmiarowe znaki zostana przeniesione do dalszych wierszy, w przypadku zwiekszenia limitu, tekst pozostanie bez zmian." << endl
		<< "Prosze podac nowy limit znakow, lub 0, aby zachowac obecny limit znakow w wierszu: ";
	cin >> temp;
	if (temp != 0) {
		if (temp >= (dlugosc_najdluzszego_wyrazu(wiersze) + 1))
			max_znakow = temp;
		else {

			cout << "Maksymalna dlugosc wiersza nie moze byc mniejsza niz dlugosc najdluzszego wyrazu w tekscie + jeden znak." << endl;
			system("pause");
		}
	}
}


// $$$$$$$$$$$$$$$$$$$ OBS£UGA PLIKÓW $$$$$$$$$$$$$$$$$$$


bool czy_istnieje_plik(const string& sciezkain) {
	fstream plik;
	plik.open(sciezkain);
	if (plik.good()) return 1;
	else return 0;
}

void zapisz_plik(list<list<char>>& wiersze, const string& sciezkaout, const bool nr_wierszy) {
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz
	ofstream plik;

	plik.open(sciezkaout);
	przewin_tekst(wiersze, plik, nr_wierszy);
	plik.close();
}

void wczytaj_plik(list<list<char>>& wiersze, string& sciezkain) {
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz
	string temp;
	ifstream plik;

	plik.open(sciezkain);
	if (plik) {
		while (!plik.eof()) {
			temp.clear();
			getline(plik, temp);

			for (char x : temp) {
				znaki.push_back(x);
			}

			wiersze.push_back(znaki);
			znaki.clear();
		}
	}
	plik.close();

}


// $$$$$$$$$$$$$$$$$$$ FUNKCJE PROGRAMU I POMOCNICZE $$$$$$$$$$$$$$$$$$$


void usun_wiersz(list<list<char>>& wiersze, int nr) {
	auto W = wiersze.begin();
	przewin_do_wiersza(wiersze, W, nr);
	wiersze.erase(W); // usuniêcie wybranego wiersza	
}

int ilosc_wystapien_w_wierszu(list<char>& znaki, const string& wyraz) {
	int ilosc = 0;
	list<char>::iterator Z = znaki.begin();

	do {
		if (znajdz_wyraz(Z, wyraz, znaki))
			ilosc++;
	} while (Z != znaki.end());
	return ilosc;
}

void dodaj_wiersz(list<list<char>>& wiersze, const int nr) {

	if (nr == wiersze.size()) wiersze.emplace_back(); // dodanie nowego pustego wiersza na koniec
	else {
		auto W = wiersze.begin();
		przewin_do_wiersza(wiersze, W, nr + 1);
		wiersze.emplace(W);
	}
}

void ustaw_sciezke_zapisu(string& sciezkaout) {
	bool jld = 0; // zmienna pomocnicza

	cout << "Czy chcesz zapisac zmiany w aktualnym pliku, czy utworzyc nowy plik txt?" << endl << "Nacisnij 1 jesli chcesz nowy plik, 2 jesli chcesz zapisac zmiany w aktualnym pliku   ";
	switch (wybor1zN(2)) {

	case 1:
		cout << "Podaj nazwe pliku wyjsciowego wraz z rozszerzeniem  ";
		cin >> sciezkaout;

		break;
	}
}

void przewin_tekst(list<list<char>>& wiersze, ostream& s, const bool nr_wiersz) {
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz
	int nrw = 1;

	for (auto W = wiersze.begin(); W != wiersze.end(); W++) {
		znaki = *W;
		if (nr_wiersz) s << nrw++ << "." << "\t";
		for (auto Z = znaki.begin(); Z != znaki.end(); Z++) {
			s << *Z;
		}
		s << endl;
	}
	znaki.clear();
}

void sprawdz_limit_znakow(list<list<char>>& wiersze, const int max_znakow) {
	list<char> znaki; // pomocnicza lista charów
	int roznica; // minimalna iloœæ znaków do przeniesienia
	string buf; // bufor
	int dlg_buf = 0; // iloœæ znaków przeniesionych z poprzedniego wiersza	
	int pom = 1;
	int tmp = 0;


	for (auto W = wiersze.begin(); W != wiersze.end(); W++) {
		int dlg_w = wiersze.size(); // iloœc wierszy / numer ostatniego wiersza
		znaki = *W;
		pom++;

		if (dlg_buf > 0) {
			auto Zk = znaki.begin();
			if (!znaki.empty()) {
				if (*Zk != ' ' && buf[0] != ' ') {
					znaki.push_front(' ');
				}
			}
			for (char x : buf) {
				znaki.push_front(x);
			}
		}

		buf.clear();
		dlg_buf = 0;
		int c = znaki.size(); // iloœæ znaków w wierszu

		if (znaki.size() > max_znakow) {
			roznica = znaki.size() - max_znakow;

			for (auto Z = znaki.rbegin(); Z != znaki.rend(); Z++) {
				tmp++;
				if (*Z == ' ' && tmp >= roznica) {
					break;
				}
				else {
					buf += *Z;
					dlg_buf++;
				}
			}
			znaki.resize(c - tmp);
			tmp = 0;
		}

		*W = znaki;
		znaki.clear();
		if (dlg_buf > 0 && pom == dlg_w) {
			wiersze.push_back(znaki);
		}
	}
}

void statystyki(list<list<char>>& wiersze, int& w, int& zs, int& z) {
	w = 0; zs = 0; z = 0; // zmienne ze statystykami do wyœwietlenia
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz

	for (auto W = wiersze.begin(); W != wiersze.end(); W++) {   // pêtla obiegaj¹ca ca³y tekst
		znaki = *W; // przypisanie aktualnego wiersza do zmiennej pomocniczej		
		bool czy_spacija = 0; // zmienna pomocnicza do liczenia statystyk
		for (auto Z = znaki.begin(); Z != znaki.end(); Z++) {
			zs++;
			if (*Z != ' ') {
				z++;
				czy_spacija = 0;
			}
			if (*Z == ' ' && Z == znaki.begin()) {
				czy_spacija = 1;
			}
			if ((czy_spacija == 0 && *Z == ' ') || (czy_spacija == 0 && Z == --znaki.end())) {
				w++;
				czy_spacija = 1;
			}					
		}
	}	
}

void dodaj_wyraz(list<char>& znaki, int max_w_W, const int nr, string& wyraz, const int wybor, const int wystapienie, const string& wyraz_po) {

	if (wyraz.size() > max_w_W) {
		max_w_W = wyraz.size() + 1;
	}

	switch (wybor) {
	case 1:
	{
		reverse(wyraz.begin(), wyraz.end());
		auto Z = znaki.begin();
		if (!znaki.empty()) {
			if (*Z != ' ') {
				znaki.push_front(' ');
			}
		}
		for (char x : wyraz) {
			znaki.push_front(x);
		}
	}
	break;

	case 2:
	{
		auto Z = znaki.rbegin();
		if (!znaki.empty()) {
			if (*Z != ' ') {
				znaki.push_back(' ');
			}
		}
		for (char x : wyraz) {
			znaki.push_back(x);
		}
	}
	break;

	case 3:
	{
		auto Z = znaki.begin();
		bool jest = 0;
		int ilosc = 1;

		while (znajdz_wyraz(Z, wyraz_po, znaki) && ilosc < wystapienie) {
			ilosc++;
		}

		if (ilosc == wystapienie) {
			jest = 1;
		}

		if (jest) {
			if (Z != znaki.end()) Z++;
			if (Z == znaki.end()) {
				auto Z = znaki.rbegin();
				if (!znaki.empty()) {
					if (*Z != ' ') {
						znaki.push_back(' ');
					}
				}
				for (char x : wyraz) {
					znaki.push_back(x);
				}
			}
			else {
				if (*Z == ' ') {
					Z++;
					for (char x : wyraz) {
						znaki.insert(Z, x);
					}
					znaki.insert(Z, ' ');
				}
				else {
					Z++;
					znaki.insert(Z, ' ');
					for (char x : wyraz) {
						znaki.insert(Z, x);
					}
					znaki.insert(Z, ' ');
				}
			}
		}
	}
	break;
	}

}

void justowanie(list<list<char>>& wiersze, const int max_znakow) {
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz

	for (auto W = wiersze.begin(); W != wiersze.end(); W++) {
		znaki = *W;
		if (znaki.size() < max_znakow) {
			int ilosc_znakow_w_wierszu = znaki.size();
			int ilosc_spacji_w_wierszu = 0;
			for (auto Z = znaki.begin(); Z != znaki.end(); Z++) {
				if (*Z == ' ')
					ilosc_spacji_w_wierszu++;
			}
			if (ilosc_spacji_w_wierszu > 0) {
				int srednia_spacji_dodanie = (max_znakow - ilosc_znakow_w_wierszu) / (ilosc_spacji_w_wierszu);
				int dodatkowe_spacje_dodanie = ((max_znakow - ilosc_znakow_w_wierszu) % (ilosc_spacji_w_wierszu)-1);
				for (auto Z = znaki.begin(); Z != znaki.end(); Z++) {
					if (*Z == ' ') {
						for (int i = 0; i < srednia_spacji_dodanie; i++)
							znaki.insert(Z, ' ');
						if (dodatkowe_spacje_dodanie > 0) {
							znaki.insert(Z, ' ');
							dodatkowe_spacje_dodanie--;
						}					
					}
				}
			}
			else {
				int p = 0;
				for (int i = 0; i < ((max_znakow - ilosc_znakow_w_wierszu) / 2); i++) {
					znaki.push_front(' ');
					p++;
				}
				for (int i = 0; i < (max_znakow - ilosc_znakow_w_wierszu - p); i++)
					znaki.push_back(' ');
			}
			*W = znaki;
		}
	}
}

int wybor1zN(const int ile) {
	char a;
	bool jld = 0;
	int b;

	do {
		cin >> a;
		b = a - '0';
		if (b >= 1 && b <= ile) {
			jld = 0;
		}
		else {
			cout << "Nieprawidlowy wybor, sprobuj ponownie  ";
			jld = 1;
		}
	} while (jld);
	return b;
}

int ustaw_nr_wiersza(list<list<char>>& wiersze) {
	int nr = 0;
	cin >> nr;

	while (cin.fail() || nr < 1 || nr >= (wiersze.size() + 1)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Niepoprawny numer wiersza, sprobuj ponownie  ";
		cin >> nr;
	}
	return nr;
}

void przewin_do_wiersza(list<list<char>>& wiersze, std::list<list<char>>::iterator& W, const int nr_wiersza) {
	int c = 1;
	for (; W != wiersze.end(); W++) {
		if (c++ == nr_wiersza) {
			return;
		}
	}
}

void usun_lub_zamien_wyraz(list<list<char>>& wiersze, const string& wyraz, const int a, const int wystapienie, const int nr_wiersza, const bool zamien, const string& n_wyraz) {
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz
	int dlg_wyrazu = wyraz.size();

	switch (a) {
		// w ca³ym wierszu
	case 1: {
		auto W = wiersze.begin();
		przewin_do_wiersza(wiersze, W, nr_wiersza);
		znaki = *W;
		auto Z = znaki.begin();
		do {
			zamien_usun_wnetrze(n_wyraz, znaki, wyraz, dlg_wyrazu, zamien, Z);
			*W = znaki;
		} while (Z != znaki.end());
	}
		  break;

		  // jedno wyst¹pienie w wierszu
	case 2: {
		auto W = wiersze.begin();
		przewin_do_wiersza(wiersze, W, nr_wiersza);
		znaki = *W;
		auto Z = znaki.begin();

		bool jest = 0;
		int ilosc = 1;

		while (znajdz_wyraz(Z, wyraz, znaki) && ilosc < wystapienie) {
			ilosc++;
		}

		if (ilosc == wystapienie) {
			jest = 1;
			int x = wyraz.size();
			for (int i = 0; i < x; i++) {
				advance(Z, -1);
				if (Z == znaki.begin())
					break;
			}			
		}

		if (jest) {
			zamien_usun_wnetrze(n_wyraz, znaki, wyraz, dlg_wyrazu, zamien, Z);
		}
		*W = znaki;
	}
		  break;

		  // w ca³ym tekœcie
	case 3: {
		for (auto W = wiersze.begin(); W != wiersze.end(); W++) {
			znaki = *W;
			auto Z = znaki.begin();
			do {
				zamien_usun_wnetrze(n_wyraz, znaki, wyraz, dlg_wyrazu, zamien, Z);
				*W = znaki;
			} while (Z != znaki.end());
		}
	}
		  break;
	}
}

void zamien_usun_wnetrze(const string& n_wyraz, list<char>& znaki, const string& wyraz, const int dlg_wyrazu, const bool zamien, list<char>::iterator& Z) {
	if (znajdz_wyraz(Z, wyraz, znaki)) {
		if (Z != --znaki.end()) Z++;
		auto Z1 = Z;
		advance(Z1, -(dlg_wyrazu));

		Z++;
		if (!(Z1 == znaki.begin())) {
				Z1--;

			Z--;
			if (Z != znaki.end() && Z1 != znaki.end() && !(*Z == ' ' && *Z1 == ' ') && ((*Z >= 65 && *Z <= 90) || (*Z >= 97 && *Z <= 122)))
				Z++;
		}

		else {
			if (*--Z != ' ') {
				Z++;
				Z++;
			}
			else Z++;
		}

		if (Z1 != znaki.end() && * Z1 != ' ' && Z1 != znaki.begin())
			Z1++;

		// wstawienie nowego wyrazu, jeœli wykonywana jest zamiana
		if (zamien) {
			if (Z1 != znaki.begin()) {
				znaki.insert(Z1, ' ');
			}
			else if(Z != znaki.end()) {
				znaki.insert(Z, ' ');
				Z--;
			}

			for (char x : n_wyraz) {
				znaki.insert(Z1, x); // wstawienie nowego wyrazu
			}
		}
		znaki.erase(Z1, Z); // usuniêcie wyrazu
	}
}

bool znajdz_wyraz(list<char>::iterator& Z, const string& wyraz, const list<char>& znaki) {
	int dlg_wyrazu = wyraz.size();
	int temp = 0;
	int ilosc_pasujacych = 0;
	bool licz = 0;

	for (Z; Z != znaki.end(); Z++) {
		int znak = (int)*Z;

		if (!((znak >= 65 && znak <= 90) || (znak >= 97 && znak <= 122)) || Z == znaki.begin()) {
			temp = 0;
			licz = 1;
			ilosc_pasujacych = 0;
		}
		if(licz) {
			if (*Z != wyraz[temp]) {
				ilosc_pasujacych = 0;
				temp = 0;
			}

			else if (*Z == wyraz[temp]) {
				ilosc_pasujacych++;
				temp++;
			}
		}
		if (ilosc_pasujacych == dlg_wyrazu) {
			if(Z != znaki.end())
			Z++;
			if (Z == znaki.end()) {
				Z--;
				return 1;
			}
			if (Z != znaki.end()) {
				if (!((*Z >= 65 && *Z <= 90) || (*Z >= 97 && *Z <= 122))) {
					Z--;
					return 1;
				}
			}
			else {
				Z--;
			}
		}
	}
	return 0;
}

void ustaw_limit(list<list<char>>& wiersze, int& max_znakow) {
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz

	for (auto W = wiersze.begin(); W != wiersze.end(); W++) {
		znaki = *W;
		if (W == wiersze.begin()) {
			max_znakow = znaki.size();
		}
		else {
			if (znaki.size() > max_znakow)
				max_znakow = znaki.size();
		}
	}
}

int dlugosc_najdluzszego_wyrazu(list<list<char>>& wiersze) {
	list<char> znaki; // zmienna pomocnicza, zawieraj¹ca jeden wiersz
	int dlg_najdluzszego_wyrazu = 0;
	int pom = 0; // zmienna pomocnicza

	for (auto W = wiersze.begin(); W != wiersze.end(); W++) {
		znaki = *W;
		for (auto Z = znaki.begin(); Z != znaki.end(); Z++) {
			if (*Z == ' ' || Z == --znaki.end()) {
				if (pom > dlg_najdluzszego_wyrazu) {
					dlg_najdluzszego_wyrazu = pom;
				}
				pom = 0;
			}
			else {
				pom++;
			}
		}
		pom = 0;
	}
	return dlg_najdluzszego_wyrazu;
}


// $$$$$$$$$$$$$$$$$$$ MENU $$$$$$$$$$$$$$$$$$$


bool menu(list<list<char>>& wiersze, string& sciezkain, int& max_znakow, bool& czy_nr_w) {
	bool kontynuuj = 1;
	char a = 0;

	cout << "MENU" << endl;
	cout << "1. Wyswietl numery wierszy" << endl;
	cout << "2. Dodaj wyraz" << endl;
	cout << "3. Dodaj pusty wiersz" << endl;
	cout << "4. Usun wiersz" << endl;
	cout << "5. Usun wyraz" << endl;
	cout << "6. Zamien wyrazu" << endl;
	cout << "7. Statystyki" << endl;
	cout << "8. Justowanie" << endl;
	cout << "9. Zmien limit znakow w wierszu" << endl;
	cout << "S. Zapisz plik" << endl;
	cout << "O. Otworz inny plik" << endl;
	cout << "Q. Wyjdz z programu" << endl;
	cout << "Co chcesz zrobic?   ";
	cin >> a;
	switch (a)
	{
	case '1':
		czy_nr_w = !czy_nr_w;
		break;
	case '2':
		dodaj_wyraz_konsola(wiersze, max_znakow);
		sprawdz_limit_znakow(wiersze, max_znakow); // dostosowanie tekstu do limitu znaków w wierszu
		break;
	case '3':
		dodaj_wiersz_konsola(wiersze);
		break;
	case '4':
		usun_wiersz_konsola(wiersze);
		break;
	case '5':
		usun_wyraz_konsola(wiersze);
		break;
	case '6':
		zamien_wyraz_konsola(wiersze,max_znakow);
		sprawdz_limit_znakow(wiersze, max_znakow); // dostosowanie tekstu do limitu znaków w wierszu
		break;
	case '7':
		statystyki_konsola(wiersze);
		cout << endl;
		system("pause");
		break;
	case '8':
		justowanie(wiersze, max_znakow);
		break;
	case '9':
		zmiana_limitu_znakow(wiersze, max_znakow);
		sprawdz_limit_znakow(wiersze, max_znakow); // dostosowanie tekstu do limitu znaków w wierszu
		break;
	case 's':
	case 'S':
		ustaw_sciezke_zapisu(sciezkain);
		zapisz_plik_konsola(wiersze, sciezkain);
		system("pause");
		break;
	case 'Q':
	case 'q':
		kontynuuj = 0;
		break;
	case 'O':
	case 'o':
		wczytaj_nowy_plik_konsola(wiersze, sciezkain);
		break;

	default:
		cout << "Nieprawidlowa operacja, prosze podac znak odpowiadajacy jednej z podanych wyzej mozliwosci." << endl;
		system("pause");
		break;
	}

	return kontynuuj;
}
