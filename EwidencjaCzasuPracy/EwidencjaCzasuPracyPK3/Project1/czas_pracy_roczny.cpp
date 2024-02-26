#include "czas_pracy_roczny.h"

void czas_pracy_roczny::wypisz_czas_pracy(int nrp) {
	cout << "Roczny czas pracy pracownika nr " << nrp << " wynosi " << endl;
	cout << "Godziny standardowe: " << get_czas_std() << endl;
	cout << "Godziny dodatkowe: " << get_czas_dod() << endl;
	cout << "Sredni czas pracy: " << get_sredni_czas_pracy() << endl;
	cout << "Calkowity roczny czas pracy: " << get_calkowity_czas_pracy() << endl;
}
