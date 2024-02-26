#include "czas_pracy_pracownika.h"

bool czas_pracy_pracownika::set_czas_pracy(int czas_std, int czas_dod) {
	if (czas_std >= 0 && czas_std <= 24 && czas_dod >= 0 && czas_dod <= 24) {
		int _dzien = dzien - 1;
		int _tydzien = tydzien - 1;
		int _miesiac = miesiac - 1;

		int temp_czas_std = czas_std - czas_dzienny[_dzien].get_czas_std();
		int temp_czas_dod = czas_dod - czas_dzienny[_dzien].get_czas_dod();

		czas_dzienny[_dzien].set_czas_std(czas_std);
		czas_dzienny[_dzien].set_czas_dod(czas_dod);

		czas_tygodniowy[_tydzien] += temp_czas_std;
		czas_tygodniowy[_tydzien].zwieksz_dod_czas_pracy(temp_czas_dod);
		czas_miesieczny[_miesiac] += (temp_czas_std);
		czas_miesieczny[_miesiac].zwieksz_dod_czas_pracy(temp_czas_dod);
		czas_roczny += (temp_czas_std);
		czas_roczny.zwieksz_dod_czas_pracy(temp_czas_dod);
		return 1;
	}
	else
		return 0;
}

void czas_pracy_pracownika::set_czas_pracy_wybrany(int czas_std, int czas_dod, int dzien_tydzien_miesiac_rok, int wybor) {
	wybor--;
	switch (dzien_tydzien_miesiac_rok) {
	case 1: // dzienny
		czas_dzienny[wybor].set_czas_std(czas_std);
		czas_dzienny[wybor].set_czas_dod(czas_dod);
		break;
	case 2: // tygodniowy
		czas_tygodniowy[wybor].set_czas_std(czas_std);
		czas_tygodniowy[wybor].set_czas_dod(czas_dod);
		break;
	case 3: // miesiêczny
		czas_miesieczny[wybor].set_czas_std(czas_std);
		czas_miesieczny[wybor].set_czas_dod(czas_dod);
		break;
	case 4: // roczny
		czas_roczny.set_czas_std(czas_std);
		czas_roczny.set_czas_dod(czas_dod);
		break;
	}
}

tuple<int, int, double> czas_pracy_pracownika::get_czas_pracy_wybrany(int dzien_tydzien_miesiac_rok, int wybor) {
	wybor--;
	switch (dzien_tydzien_miesiac_rok) {
	case 1: // dzienny
		if (czy_lezy_w_zakrese(0, 364, wybor))
			return make_tuple(czas_dzienny[wybor].get_czas_std(), czas_dzienny[wybor].get_czas_dod(), czas_dzienny[wybor].get_sredni_czas_pracy());
	case 2: // tygodniowy
		if (czy_lezy_w_zakrese(0, 52, wybor))
			return make_tuple(czas_tygodniowy[wybor].get_czas_std(), czas_tygodniowy[wybor].get_czas_dod(), czas_tygodniowy[wybor].get_sredni_czas_pracy());
	case 3: // miesiêczny
		if (czy_lezy_w_zakrese(0, 11, wybor))
			return make_tuple(czas_miesieczny[wybor].get_czas_std(), czas_miesieczny[wybor].get_czas_dod(), czas_miesieczny[wybor].get_sredni_czas_pracy());
	case 4: // roczny
		return make_tuple(czas_roczny.get_czas_std(), czas_roczny.get_czas_dod(), czas_roczny.get_sredni_czas_pracy());
	default:
		return { 0,0,0 };
	}
}

bool czas_pracy_pracownika::zwieksz_czas_pracy_std(int zw_czas) {
	int _dzien = dzien - 1;
	int _tydzien = tydzien - 1;
	int _miesiac = miesiac - 1;
	if (czas_dzienny[_dzien].get_czas_std() + zw_czas > 24)
		return 0;
	else {
		czas_dzienny[_dzien] += zw_czas;
		czas_tygodniowy[_tydzien] += zw_czas;
		czas_miesieczny[_miesiac] += zw_czas;
		czas_roczny += zw_czas;
		return 1;
	}
}

bool czas_pracy_pracownika::zmniejsz_czas_pracy_std(int zm_czas) {
	int _dzien = dzien - 1;
	int _tydzien = tydzien - 1;
	int _miesiac = miesiac - 1;
	if (czas_dzienny[_dzien].get_czas_std() - zm_czas < 0)
		return 0;
	else {
		czas_dzienny[_dzien] -= zm_czas;
		czas_tygodniowy[_tydzien] -= zm_czas;
		czas_miesieczny[_miesiac] -= zm_czas;
		czas_roczny -= zm_czas;
		return 1;
	}
}

bool czas_pracy_pracownika::zwieksz_czas_pracy_dod(int zw_czas_d) {
	int _dzien = dzien - 1;
	int _tydzien = tydzien - 1;
	int _miesiac = miesiac - 1;
	if (czas_dzienny[_dzien].get_czas_dod() + zw_czas_d > 24)
		return 0;
	else {
		czas_dzienny[_dzien].zwieksz_dod_czas_pracy(zw_czas_d);
		czas_tygodniowy[_tydzien].zwieksz_dod_czas_pracy(zw_czas_d);
		czas_miesieczny[_miesiac].zwieksz_dod_czas_pracy(zw_czas_d);
		czas_roczny.zwieksz_dod_czas_pracy(zw_czas_d);
		return 1;
	}
}

tuple<int, int, double> czas_pracy_pracownika::get_czas_pracy(int dzien_tydzien_miesiac_rok) {
	int _dzien = dzien - 1;
	int _tydzien = tydzien - 1;
	int __miesiac = miesiac - 1;
	switch (dzien_tydzien_miesiac_rok) {
	case 1: // dzienny
		return make_tuple(czas_dzienny[_dzien].get_czas_std(), czas_dzienny[_dzien].get_czas_dod(), czas_dzienny[_dzien].get_sredni_czas_pracy());
	case 2: // tygodniowy
		return make_tuple(czas_tygodniowy[_tydzien].get_czas_std(), czas_tygodniowy[_tydzien].get_czas_dod(), czas_tygodniowy[_tydzien].get_sredni_czas_pracy());
	case 3: // miesiêczny
		return make_tuple(czas_miesieczny[__miesiac].get_czas_std(), czas_miesieczny[__miesiac].get_czas_dod(), czas_miesieczny[__miesiac].get_sredni_czas_pracy());
	case 4: // roczny
		return make_tuple(czas_roczny.get_czas_std(), czas_roczny.get_czas_dod(), czas_roczny.get_sredni_czas_pracy());
	default:
		return { 0,0,0 };
	}
}