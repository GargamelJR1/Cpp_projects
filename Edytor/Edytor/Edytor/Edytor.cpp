#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[]) {

	list<list<char>> wiersze; /// lista list znakow, zawieraj¹ca ca³y edytowany tekst
	string sciezkain; /// œcie¿ka pliku wejœciowego
	int max_znakow = 0; /// maksymalna iloœæ znaków w wierszu
	bool czy_nr_w = 0; /// zmienna okreslajaca, czy wiersze maja byc wyswietlane z numerem

	if (argc == 2) {
		sciezkain = argv[1];
	}
	else {
		cout << "Witaj w prostym edytorze tekstowym" << endl << "Program wyswietla menu, ktore obsluguje sie wpisujac odpowiednie znaki i zatwierzajac enterem" << endl << "Na poczatku program poprosi o wpisanie sciezki do pliku, ktory ma byc wczytany." << endl;
		system("pause"); // oczekiwanie na reakcjê u¿ytkownika
		system("cls"); // czyszczenie ekranu
	}
	
	if (!czy_istnieje_plik(sciezkain)){
		wczytaj_plik_konsola(wiersze,sciezkain);
	} 
	else {
		wczytaj_plik(wiersze,sciezkain);
	}

	ustaw_limit(wiersze, max_znakow); // ustalenie pocz¹tkowego limitu znakow w wierszu na d³ugoœæ najd³u¿szego wiersza
	
	do {		
		system("cls"); // czyszczenie ekranu
		wyswietl_tekst(wiersze, czy_nr_w); // wyœwietlanie tekstu
		cout << endl << endl; // odstep miêdzy tekstem, a menu
		if (menu(wiersze, sciezkain, max_znakow, czy_nr_w)); // wyœwietlanie i obs³uga menu
		else return 0;
	} while (true);
	
	return 0;
}