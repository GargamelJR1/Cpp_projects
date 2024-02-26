#include "logi.h"
bool logi::logujb = 1;

void logi::loguj(const string& komunikat, const string& wynik, const string& typ, const string& funkcja) const {
	if (logujb) {
		ofstream pliklog;
		pliklog.open("logi.txt", std::ofstream::app);
		string separator = "===================================";
		auto czasidata = std::chrono::zoned_time{ std::chrono::current_zone(), std::chrono::system_clock::now() };
		pliklog << separator << endl << czasidata << endl << "Komunikat: " << komunikat << endl
			<< "Typ: " << typ << endl << "Funkcja/metoda: " << funkcja << endl << "Wynik: " << wynik << endl;
		pliklog.close();
	}
	else
		return;
}