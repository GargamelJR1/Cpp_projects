#include "funkcje.h"

bool czy_istnieje_plik(const string& sciezkain) {
	using namespace filesystem;

	for (auto& p : directory_iterator(current_path()))
	{
		if (p.path().filename() == sciezkain)
			return 1;
	}

	return 0;
}

double wczytaj_liczbe_double_dodatnia() {
	double liczba;
	while (1) {
		cin >> liczba;
		if (!cin || liczba < 0)
		{
			wczytywanie_srodek_petli();
			continue;
		}
		else break;
	}
	czysc_wczytywanie();
	liczba = round(liczba * 100) / 100;
	return liczba;
}

int wczytaj_liczbe_int_dodatnia() {
	int liczba;
	while (1) {
		cin >> liczba;
		if (!cin || liczba < 0)
		{
			wczytywanie_srodek_petli();
			continue;
		}
		else break;
	}
	czysc_wczytywanie();
	return liczba;
}

int wczytaj_liczbe_int_z_zakresu(int min, int max) {
	int liczba;
	while (1) {
		cin >> liczba;
		if (!cin || liczba < min || liczba > max)
		{
			wczytywanie_srodek_petli();
			continue;
		}
		else break;
	}
	czysc_wczytywanie();
	return liczba;
}

void czysc_wczytywanie() {
	string temp;
	getline(cin, temp); // czyszczenie wczytywanej linii, zapobiega wczytaniu dodatkowych znaków
	cin.clear();
}

void wczytywanie_srodek_petli() {
	cout << "Nieprawidlowe dane. Sprobuj ponownie " << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool czy_lezy_w_zakrese(int min, int max, int liczba) {
	return (liczba >= min && liczba <= max);
}

double doAcc_pair_double(double sum, const pair<double, int>& t) {
	return t.first * t.second + sum;
}