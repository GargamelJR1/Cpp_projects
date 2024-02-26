#include "pracownik.h"

int pracownik::numer = 1;

pracownik& pracownik::operator=(pracownik&& p) noexcept {
	identyfikator = p.identyfikator;
	imie = p.imie;
	nazwisko = p.nazwisko;
	wiek = p.wiek;
	praca_pracownika = p.praca_pracownika;
	return *this;
}

pracownik& pracownik::operator=(const pracownik& p) {
	if (this == &p)
		return *this;
	else {
		identyfikator = p.identyfikator;
		imie = p.imie;
		nazwisko = p.nazwisko;
		wiek = p.wiek;
		praca_pracownika = p.praca_pracownika;
		return *this;
	}
}

void pracownik::Wypisz() {
	cout << "imie: " << imie << ", nazwisko: " << nazwisko << ", wiek: " << wiek
		<< ", numer identyfikacyjny: " << identyfikator << ", przepracowane dni: " << get<2>(praca_pracownika.get_czas_pracy(1))
		<< ", godziny standardowe: " << get<0>(praca_pracownika.get_czas_pracy(1)) << ", godziny dodatkowe: "
		<< get<1>(praca_pracownika.get_czas_pracy(1)) << ", wymagana ilosc czynnosci: " << get<2>(praca_pracownika.get_wydajnosc(1))
		<< ", wykonana ilosc: " << get<0>(praca_pracownika.get_wydajnosc(1)) << ", stawka godzinowa std: "
		<< get<0>(praca_pracownika.get_stawki_godzinowe()) << ", dod: " << get<1>(praca_pracownika.get_stawki_godzinowe()) << endl;
}

bool pracownik::zwiekszCzasPracyStd(int std) {
	if (praca_pracownika.zwieksz_czas_pracy_std(std))
		return 1;
	else return 0;
}

bool pracownik::zmniejszCzasPracyStd(int std) {
	if (praca_pracownika.zmniejsz_czas_pracy_std(std))
		return 1;
	else return 0;
}

bool pracownik::zwiekszCzasPracyDod(int dod) {
	if (praca_pracownika.zwieksz_czas_pracy_dod(dod))
		return 1;
	else return 0;
}

void pracownik::zwiekszIloscCzynnosci(int dod_ilosc) {
	praca_pracownika.zwieksz_ilosc_czynnosci(dod_ilosc);
}

ostream& operator<<(ostream& os, pracownik& p1) {
	const string separator = " ";
	os << (p1).getID() << separator << (p1).getImie() << separator << (p1).getNazwisko() << separator << (p1).getWiek() << separator
		<< get<0>((p1).getStawkagodzinowa()) << separator << get<1>((p1).getStawkagodzinowa()) << separator;
	for (int i = 1; i < 366; i++) {
		os << get<0>((p1).getCzasPracy_wybrany_dzien(i)) << separator << get<1>((p1).getCzasPracy_wybrany_dzien(i))
			<< separator << get<0>((p1).getWydajnosc_wybrany_dzien(i)) << separator << get<2>((p1).getWydajnosc_wybrany_dzien(i)) << separator;
	}
	for (int i = 1; i < 54; i++) {
		os << get<0>((p1).getCzasPracy_wybrany_tydzien(i)) << separator << get<1>((p1).getCzasPracy_wybrany_tydzien(i))
			<< separator << get<0>((p1).getWydajnosc_wybrany_tydzien(i)) << separator << get<2>((p1).getWydajnosc_wybrany_tydzien(i)) << separator;
	}
	for (int i = 1; i < 13; i++) {
		os << get<0>((p1).getCzasPracy_wybrany_miesiac(i)) << separator << get<1>((p1).getCzasPracy_wybrany_miesiac(i))
			<< separator << get<0>((p1).getWydajnosc_wybrany_miesiac(i)) << separator << get<2>((p1).getWydajnosc_wybrany_miesiac(i)) << separator;
	}
	os << get<0>((p1).getCzasPracy_rok()) << separator << get<1>((p1).getCzasPracy_rok())
		<< separator << get<0>((p1).getWydajnosc_rok()) << separator << get<2>((p1).getWydajnosc_rok()) << separator;
	return os;
}

istream& operator>>(istream& is, pracownik& p1) {
	stringstream s;
	string wczytana_linia;
	getline(is, wczytana_linia);
	if (!wczytana_linia.empty()) {
		s << wczytana_linia;
		{
			double temp1ps = 0, temp2pd = 0;
			s >> p1.identyfikator >> p1.imie >> p1.nazwisko >> p1.wiek >> temp1ps >> temp2pd;
			p1.setStawkagodzinowa(temp1ps, temp2pd);
		}
		int temp1cz = 0, temp2cz = 0, temp3wy = 0, temp4wy = 0;
		for (int i = 1; i < 366; i++) {
			s >> temp1cz >> temp2cz >> temp3wy >> temp4wy;
			p1.set_czas_wybrany(temp1cz, temp2cz, 1, i);
			p1.setWydajnoscdzien(temp3wy, temp4wy, i);
		}
		for (int i = 1; i < 54; i++) {
			s >> temp1cz >> temp2cz >> temp3wy >> temp4wy;
			p1.set_czas_wybrany(temp1cz, temp2cz, 2, i);
			p1.setWydajnosctydzien(temp3wy, temp4wy, i);
		}
		for (int i = 1; i < 13; i++) {
			s >> temp1cz >> temp2cz >> temp3wy >> temp4wy;
			p1.set_czas_wybrany(temp1cz, temp2cz, 3, i);
			p1.setWydajnoscmiesiac(temp3wy, temp4wy, i);
		}
		s >> temp1cz >> temp2cz >> temp3wy >> temp4wy;
		p1.set_czas_wybrany(temp1cz, temp2cz, 4);
		p1.setWydajnoscrok(temp3wy, temp4wy);
	}
	return is;
}

string pracownik::operator[](int index) const {
	if (!(index < 0 || index > 3)) {
		switch (index) {
		case 0:
			return to_string(getID());
		case 1:
			return getImie();
		case 2:
			return getNazwisko();
		case 3:
			return to_string(getWiek());
		}
	}
	return " ";
}

void pracownik::setIlosc_wymagana(int dzien_tyg_mies_rocz, int ilosc, int nr) {
	switch (dzien_tyg_mies_rocz) {
	case 1:
		praca_pracownika.set_ilosc_wymagana_tygodniowa(nr, ilosc);
		break;
	case 2:
		praca_pracownika.set_ilosc_wymagana_miesieczna(nr, ilosc);
		break;
	case 3:
		praca_pracownika.set_ilosc_wymagana_roczna(ilosc);
		break;
	}
}

void pracownik::setDzien_tydzien_i_miesiac(int dzien, int tydzien, int miesiac) {
	praca_pracownika.czas_pracy_pracownika::set_dzien(dzien);
	praca_pracownika.wydajnosc_pracy_pracownika::set_dzien(dzien);
	praca_pracownika.czas_pracy_pracownika::set_tydzien(tydzien);
	praca_pracownika.wydajnosc_pracy_pracownika::set_tydzien(tydzien);
	praca_pracownika.czas_pracy_pracownika::set_miesiac(miesiac);
	praca_pracownika.wydajnosc_pracy_pracownika::set_miesiac(miesiac);
}

bool pracownik::setCzaspracy(int stdgodz, int dodgodz) {
	if (praca_pracownika.set_czas_pracy(stdgodz, dodgodz))
		return 1;
	else return 0;
}