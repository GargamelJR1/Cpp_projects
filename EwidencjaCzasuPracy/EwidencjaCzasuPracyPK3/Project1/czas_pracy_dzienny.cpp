#include "czas_pracy_dzienny.h"

void czas_pracy_dzienny::wypisz_czas_pracy(int nrp) {
	cout << "Dzienny czas pracy pracownika nr " << nrp << " wynosi " << endl;
	cout << "Godziny standardowe: " << get_czas_std() << endl;
	cout << "Godziny dodatkowe: " << get_czas_dod() << endl;
	cout << "Sredni czas pracy: " << get_sredni_czas_pracy() << endl;
	cout << "Calkowity dzienny czas pracy: " << get_calkowity_czas_pracy() << endl;
}
