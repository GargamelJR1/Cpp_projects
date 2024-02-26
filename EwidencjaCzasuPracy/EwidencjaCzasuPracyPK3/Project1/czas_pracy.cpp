#include "czas_pracy.h"

void czas_pracy::zwieksz_dod_czas_pracy(int czas_do_dodania) {
	dodatkowe_godziny += czas_do_dodania;
}

void czas_pracy::zmniejsz_dod_czas_pracy(int czas_do_dodania) {
	dodatkowe_godziny -= czas_do_dodania;
}

