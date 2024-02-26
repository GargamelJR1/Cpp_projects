#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[]) {

	list<list<char>> wiersze; /// lista list znakow, zawieraj�ca ca�y edytowany tekst
	string sciezkain; /// �cie�ka pliku wej�ciowego
	int max_znakow = 0; /// maksymalna ilo�� znak�w w wierszu
	bool czy_nr_w = 0; /// zmienna okreslajaca, czy wiersze maja byc wyswietlane z numerem

	if (argc == 2) {
		sciezkain = argv[1];
	}
	else {
		cout << "Witaj w prostym edytorze tekstowym" << endl << "Program wyswietla menu, ktore obsluguje sie wpisujac odpowiednie znaki i zatwierzajac enterem" << endl << "Na poczatku program poprosi o wpisanie sciezki do pliku, ktory ma byc wczytany." << endl;
		system("pause"); // oczekiwanie na reakcj� u�ytkownika
		system("cls"); // czyszczenie ekranu
	}
	
	if (!czy_istnieje_plik(sciezkain)){
		wczytaj_plik_konsola(wiersze,sciezkain);
	} 
	else {
		wczytaj_plik(wiersze,sciezkain);
	}

	ustaw_limit(wiersze, max_znakow); // ustalenie pocz�tkowego limitu znakow w wierszu na d�ugo�� najd�u�szego wiersza
	
	do {		
		system("cls"); // czyszczenie ekranu
		wyswietl_tekst(wiersze, czy_nr_w); // wy�wietlanie tekstu
		cout << endl << endl; // odstep mi�dzy tekstem, a menu
		if (menu(wiersze, sciezkain, max_znakow, czy_nr_w)); // wy�wietlanie i obs�uga menu
		else return 0;
	} while (true);
	
	return 0;
}