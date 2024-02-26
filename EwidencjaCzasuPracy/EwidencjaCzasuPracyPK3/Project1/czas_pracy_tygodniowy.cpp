#include "czas_pracy_tygodniowy.h"

void czas_pracy_tygodniowy::wypisz_czas_pracy(int nrp){
	cout << "Tygodniowy czas pracy pracownika nr " << nrp << " wynosi " << endl;
	cout << "Godziny standardowe: " << get_czas_std() << endl;
	cout << "Godziny dodatkowe: " << get_czas_dod() << endl;
	cout << "Sredni czas pracy: " << get_sredni_czas_pracy() << endl;
	cout << "Calkowity tygodniowy czas pracy: " << get_calkowity_czas_pracy() << endl;
}
