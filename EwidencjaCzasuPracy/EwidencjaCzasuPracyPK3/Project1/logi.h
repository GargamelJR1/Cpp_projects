#pragma once
#include <fstream>
#include <chrono>
#include "funkcje.h"

using namespace std;

/**
* Klasa s³u¿¹ca do obs³ugi logów. Logi zapisywane s¹ do pliku. Klasa jest oparta o wzorzec singleton.
*/
class logi
{
private:

	static bool logujb;

	/**
	* Konstruktor prywatny, wywo³ywany przez publiczn¹ metodê klasy.
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
	* Operator () klasy logi, wywo³uje loguj.
	*/
	auto operator()(const string& komunikat, const string& wynik, const string& typ, const string& funkcja) const {
		loguj(komunikat, wynik, typ, funkcja);
	}

	/**
	* Funkcja statyczna, tworz¹c¹ obiekt typu log
	*/
	static logi& utworz_log() {
		static logi Log;
		return Log;
	}

	/**
	* Funkcja, która wy³¹cza logowanie poprzez ustawienie wartoœci pola statycznego bool logujb na 0
	*/
	void wylacz_logowanie() {
		logujb = 0;
	}

	/**
	* Funkcja loguj, zapisuj¹ca do pliku logi
	* @param komunikat komunikat loga
	* @param wynik wynik operacji
	* @param typ typ obiektu, w którym wywo³ywany jest log
	* @param funkcja funkcja, w której wywo³ywany jest log
	*/
	void loguj(const string& komunikat, const string& wynik, const string& typ, const string& funkcja) const;
};

