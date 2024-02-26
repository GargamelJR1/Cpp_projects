#include "praca.h"

double praca::oblicz_wynagrodzenie(int tydzien_miesiac_rok) {
	return  get<0>(get_czas_pracy(tydzien_miesiac_rok)) * stawka_std + get<1>(get_czas_pracy(tydzien_miesiac_rok)) * stawka_dod;
}

void praca::wyswietl_czas(int nr_id, int dzien_tyg_mies_rocz, int _miesiac, int _tydzien, int _dzien) {
	--_miesiac;
	--_tydzien;
	--_dzien;
	switch (dzien_tyg_mies_rocz) {
	case 1:
		cpptr = &czas_dzienny[_dzien];
		break;
	case 2:
		cpptr = &czas_tygodniowy[_tydzien];
		break;
	case 3:
		cpptr = &czas_miesieczny[_miesiac];
		break;
	case 4:
		cpptr = &czas_roczny;
		break;
	}
	cpptr->wypisz_czas_pracy(nr_id);
	cpptr = nullptr;
}