#pragma once
#include <fstream>
#include <chrono>
#include "funkcje.h"

using namespace std;

/**
* Klasa s�u��ca do obs�ugi log�w. Logi zapisywane s� do pliku. Klasa jest oparta o wzorzec singleton.
*/
class logi
{
private:

	static bool logujb;

	/**
	* Konstruktor prywatny, wywo�ywany przez publiczn� metod� klasy.
	*/
	logi() {
		if (czy_istnieje_plik("logi.txt")) {
			ofstream pliklogczysc;
			pliklogczysc.open("logi.txt", ios::trunc);
			pliklogczysc.close();
		}
	};

public:

	/**
	* Operator () klasy logi, wywo�uje loguj.
	*/
	auto operator()(const string& komunikat, const string& wynik, const string& typ, const string& funkcja) const {
		loguj(komunikat, wynik, typ, funkcja);
	}

	/**
	* Funkcja statyczna, tworz�c� obiekt typu log
	*/
	static logi& utworz_log() {
		static logi Log;
		return Log;
	}

	/**
	* Funkcja, kt�ra wy��cza logowanie poprzez ustawienie warto�ci pola statycznego bool logujb na 0
	*/
	void wylacz_logowanie() {
		logujb = 0;
	}

	/**
	* Funkcja loguj, zapisuj�ca do pliku logi
	* @param komunikat komunikat loga
	* @param wynik wynik operacji
	* @param typ typ obiektu, w kt�rym wywo�ywany jest log
	* @param funkcja funkcja, w kt�rej wywo�ywany jest log
	*/
	void loguj(const string& komunikat, const string& wynik, const string& typ, const string& funkcja) const;
};

