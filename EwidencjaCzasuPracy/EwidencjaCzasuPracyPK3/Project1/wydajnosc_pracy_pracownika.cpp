#include "wydajnosc_pracy_pracownika.h"

tuple<int, double, int> wydajnosc_pracy_pracownika::get_wydajnosc(int dzien_tydzien_miesiac_rok) {
	int _dzien = dzien - 1;
	int _tydzien = tydzien - 1;
	int _miesiac = miesiac - 1;
	switch (dzien_tydzien_miesiac_rok) {
	case 1: // dzienna
		return std::make_tuple(wydajnosc_dzienna[_dzien].get_ilosc_wykonanej_czynnosci(), wydajnosc_dzienna[_dzien].get_wydajnosc_wyliczona(), wydajnosc_dzienna[_dzien].get_wymagana_ilosc_czynnosci());
	case 2: // tygodniowa
		return std::make_tuple(wydajnosc_tygodniowa[_tydzien].get_ilosc_wykonanej_czynnosci(), wydajnosc_tygodniowa[_tydzien].get_wydajnosc_wyliczona(), wydajnosc_tygodniowa[_tydzien].get_wymagana_ilosc_czynnosci());
	case 3: // miesiêczna
		return std::make_tuple(wydajnosc_miesieczna[_miesiac].get_ilosc_wykonanej_czynnosci(), wydajnosc_miesieczna[_miesiac].get_wydajnosc_wyliczona(), wydajnosc_miesieczna[_miesiac].get_wymagana_ilosc_czynnosci());
	case 4: // roczna
		return std::make_tuple(wydajnosc_roczna.get_ilosc_wykonanej_czynnosci(), wydajnosc_roczna.get_wydajnosc_wyliczona(), wydajnosc_roczna.get_wymagana_ilosc_czynnosci());
	}
	return { 0,0,0 };
}


tuple<int,double,int> wydajnosc_pracy_pracownika::get_wydajnosc_wybrana(int dzien_tydzien_miesiac_rok, int wybor) {
	wybor--;
	switch (dzien_tydzien_miesiac_rok) {
	case 1: // dzienna
		if (czy_lezy_w_zakrese(0, 364, wybor))
			return std::make_tuple(wydajnosc_dzienna[wybor].get_ilosc_wykonanej_czynnosci(), wydajnosc_dzienna[wybor].get_wydajnosc_wyliczona(), wydajnosc_dzienna[wybor].get_wymagana_ilosc_czynnosci());
	case 2: // tygodniowa
		if (czy_lezy_w_zakrese(0, 52, wybor))
			return std::make_tuple(wydajnosc_tygodniowa[wybor].get_ilosc_wykonanej_czynnosci(), wydajnosc_tygodniowa[wybor].get_wydajnosc_wyliczona(), wydajnosc_tygodniowa[wybor].get_wymagana_ilosc_czynnosci());
	case 3: // miesiêczna
		if (czy_lezy_w_zakrese(0, 11, wybor))
			return std::make_tuple(wydajnosc_miesieczna[wybor].get_ilosc_wykonanej_czynnosci(), wydajnosc_miesieczna[wybor].get_wydajnosc_wyliczona(), wydajnosc_miesieczna[wybor].get_wymagana_ilosc_czynnosci());
	case 4: // roczna
		return std::make_tuple(wydajnosc_roczna.get_ilosc_wykonanej_czynnosci(), wydajnosc_roczna.get_wydajnosc_wyliczona(), wydajnosc_roczna.get_wymagana_ilosc_czynnosci());
	}
	return { 0,0,0 };
}

void wydajnosc_pracy_pracownika::set_wydajnosc_pracy(int ilosc_czynnosci, int wymagana_ilosc_czynnosci) {
	int _dzien = dzien - 1;
	int _tydzien = tydzien - 1;
	int _miesiac = miesiac - 1;

	int temp_wydajnosc = ilosc_czynnosci - wydajnosc_dzienna[_dzien].get_ilosc_wykonanej_czynnosci();

	wydajnosc_dzienna[_dzien].set_ilosc_wykonanej_czynnosci(ilosc_czynnosci);
	wydajnosc_dzienna[_dzien].set_wymagana_ilosc_czynnosci(wymagana_ilosc_czynnosci);

	wydajnosc_tygodniowa[_tydzien] += temp_wydajnosc;
	wydajnosc_miesieczna[_miesiac] += temp_wydajnosc;
	wydajnosc_roczna += temp_wydajnosc;
}

void wydajnosc_pracy_pracownika::set_ilosc_wymagana_tygodniowa(int wymagana_ilosc_czynnosci, int _tydzien) {
	_tydzien--;
	if (_tydzien > 0 && _tydzien <= 53) {
		wydajnosc_tygodniowa[_tydzien].set_wymagana_ilosc_czynnosci(wymagana_ilosc_czynnosci);
	}
}

void wydajnosc_pracy_pracownika::set_ilosc_wymagana_miesieczna(int _miesiac, int wymagana_ilosc_czynnosci) {
	_miesiac--;
	if (_miesiac > 0 && _miesiac <= 12) {
		wydajnosc_miesieczna[_miesiac].set_wymagana_ilosc_czynnosci(wymagana_ilosc_czynnosci);
	}
}

void wydajnosc_pracy_pracownika::zwieksz_ilosc_czynnosci(int plusilosc) {
	int _dzien = dzien - 1;
	int _tydzien = tydzien - 1;
	int _miesiac = miesiac - 1;
	wydajnosc_dzienna[_dzien] += plusilosc;
	wydajnosc_tygodniowa[_tydzien] += plusilosc;
	wydajnosc_miesieczna[_miesiac] += plusilosc;
	wydajnosc_roczna += plusilosc;
}

void wydajnosc_pracy_pracownika::zmniejsz_ilosc_czynnosci(int minusilosc) {
	int _dzien = dzien - 1;
	int _tydzien = tydzien - 1;
	int _miesiac = miesiac - 1;
	wydajnosc_dzienna[_dzien] -= minusilosc;
	wydajnosc_tygodniowa[_tydzien] -= minusilosc;
	wydajnosc_miesieczna[_miesiac] -= minusilosc;
	wydajnosc_roczna -= minusilosc;
}