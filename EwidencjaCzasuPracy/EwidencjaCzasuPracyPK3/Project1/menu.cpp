#include "menu.h"

bool menu::wyswietl_menu() {
	system("cls");
	bool kontynuuj = 1;
	char a = 0;

	ustaw_dzien_tydzien_miesiac_rok_pracownikow();

	cout << "System Ewidencji Czasu Pracy" << endl;
	cout << "obecny dzien: " << obecny_dzien << endl;
	cout << "obecny tydzien: " << obecny_tydzien << endl;
	cout << "obecny miesiac: " << obecny_miesiac << endl;
	cout << "dzien miesiaca: " << dzien_miesiaca << endl;
	cout << "dzien tygodnia: " << oblicz_dzien_tygodnia() << ", " << dzien_tygodnia_nazwa(oblicz_dzien_tygodnia()) << endl;
	cout << "obecnie jest wyswietlana " << wyswietlanie_nazwa() << " lista pracownikow" << endl;
	cout << "1. Wyswietl liste pracownikow" << endl;
	cout << "2. Dodaj pracownika" << endl;
	cout << "3. Zapisz nowa prace pracownika" << endl;
	cout << "4. Edytuj parametry powiazane z pracownikiem" << endl;
	cout << "5. Usun pracownika" << endl;
	cout << "6. Parametry wyswietlania" << endl;
	cout << "7. Ustaw parametry programu" << endl;
	cout << "8. Wyswietl parametry programu" << endl;
	cout << "9. Zmien dzien" << endl;
	cout << "H - Zapisz parametry programu do pliku" << endl;
	cout << "G - Wczytaj parametry programu z pliku" << endl;
	cout << "T. pokaz czas pracy pracownika (z wybranego okresu)" << endl;
	cout << "P. Zapisz liste pracownikow do pliku" << endl;
	cout << "S. Zapisz plik" << endl;
	cout << "A. Statystyki" << endl;
	cout << "O. Otworz inny plik" << endl;
	cout << "N. Zapisz liste (serializacja)" << endl;
	cout << "M. Wczytaj liste (deserializacja)" << endl;
	cout << "I. Znajdz wszystkie pliki zapisu w katalogu" << endl;
	cout << "X. Wyczysc dane, pusty program" << endl;
	cout << "Q. Wyjdz z programu" << endl;
	cout << "Co chcesz zrobic?   ";
	cin >> a;
	czysc_wczytywanie();
	switch (a)
	{
	case '1':
		wyswietl_liste_pracownikow(cout);
		system("pause");
		break;
	case '2':
		dodaj_pracownika_konsola();
		break;
	case '3':
		dodaj_nowa_prace_pracownika();
		break;
	case '4':
		edytuj_pracownika_konsola();
		break;
	case '5':
		usun_pracownika_konsola();
		system("pause");
		break;
	case '6':
		parametry_wyswietlania();
		break;
	case '7':
		nowe_parametry_programu_konsola();
		break;
	case '8':
		wyswietl_parametry_programu();
		break;
	case '9':
		zmien_dzien();
		ustaw_tydzien();
		ustaw_miesiac();
		break;
	case 't':
	case 'T':
		pokaz_wybrany_czas_konsola();
		break;
	case 'p':
	case 'P':
		zapisz_liste_konsola();
		break;
	case 'n':
	case 'N':
		zapisz_plik_konsola(0);
		system("pause");
		break;
	case 'M':
	case 'm':
		pracownicy.wyczysc_liste();
		wczytaj_plik_konsola(0);
		ustaw_id();
		logi::utworz_log().loguj("zresetowano stan programu", "", typeid(*this).name(), __func__);
		system("pause");
		break;
	case 's':
	case 'S':
		zapisz_plik_konsola();
		system("pause");
		break;
	case 'Q':
	case 'q':
		kontynuuj = 0;
		break;
	case 'O':
	case 'o':
		wczytaj_nowy_plik_konsola();
		system("pause");
		break;
	case 'H':
	case 'h':
		zapisz_parametry_plik();
		break;
	case 'G':
	case 'g':
		wczytaj_parametry_plik();
		break;
	case 'I':
	case 'i':
		wyswietl_pliki_zapisu();
		system("pause");
		break;
	case 'A':
	case 'a':
		try {
			wyswietl_statystyki();
			logi::utworz_log().loguj("obliczono statystyki: ", "", typeid(*this).name(), __func__);
		}
		catch (Wyjatek_pusta_lista) {
			cout << "Wystapil blad, lista jest pusta i nie mozna wyswietlic statystyk" << endl;
		}
		system("pause");
		break;
	case 'X':
	case 'x': {
		wyczysc_liste();
		stringstream sx("0 0 0 0 0 1");
		menu::operator>>(sx);
	}break;

	default:
		cout << "Nieprawidlowa operacja, prosze podac znak odpowiadajacy jednej z podanych wyzej mozliwosci." << endl;
		system("pause");
		break;
	}

	return kontynuuj;
}


void menu::wyswietl_statystyki_konsola(const string& nazwa, double srednia, double var, double ods, double max, double min, bool medb, double med) {
	string kopia;
	wielkia_litera wl;
	transform(nazwa.begin(), nazwa.end(), std::back_inserter(kopia), wl);
	cout << std::setprecision(2) << std::fixed << kopia << endl << "Max wartosc: " << max << ", min wartosc: " << min << endl << "Srednia: " << srednia << endl;
	if (medb) cout << "Mediana: " << med << endl; cout << "Wariancja: " << var << ", odchylenie standardowe: " << ods << endl;
}

void menu::wyswietl_statystyki() {
	if (!pracownicy.czy_nie_pusta()) throw Wyjatek_pusta_lista();
	int temp = dzien_tydzien_miesiac_rok;
	int dlg_listy = pracownicy.dlugosc();
	double suma_w = std::accumulate(pracownicy.begin(), pracownicy.end(), 0.0, [temp](double t, pracownik& p) {return p.getWynagrodzenie(temp) + t; });
	double srednie_w = suma_w / dlg_listy;
	map<double, int> zbior_plac;
	std::for_each(pracownicy.begin(), pracownicy.end(), [&zbior_plac, temp](pracownik& p)
		{
			double wy = get<0>(p.getStawkagodzinowa());
	auto el = zbior_plac.find(wy);
	if (el != zbior_plac.end()) {
		el->second++;
	}
	else {
		zbior_plac.emplace(wy, 1);
	}
		});
	double srpl = std::accumulate(zbior_plac.begin(), zbior_plac.end(), 0.0, doAcc_pair_double) / dlg_listy;
	vector<double> vd(zbior_plac.size());
	transform(zbior_plac.begin(), zbior_plac.end(), vd.begin(), [srpl](const pair<double, int>& t) {return ((srpl - t.first) * (srpl - t.first) * t.second); });
	double varp = reduce(execution::par, vd.begin(), vd.end()) / dlg_listy;
	double odspl = sqrt(varp);

	vector<int> godziny_pracy;
	transform(pracownicy.begin(), pracownicy.end(), back_insert_iterator(godziny_pracy), [temp](pracownik& p) {return get<0>(p.getCzasPracy(temp)); });
	sort(godziny_pracy.begin(), godziny_pracy.end());
	auto min_max = minmax_element(godziny_pracy.begin(), godziny_pracy.end());
	double sredniczas = std::reduce(godziny_pracy.begin(), godziny_pracy.end(), 0.0) / godziny_pracy.size();
	double varczas = transform_reduce(godziny_pracy.begin(), godziny_pracy.end(), 0.0, std::plus{}, [sredniczas](int pc) {return pow((pc - sredniczas), 2); }) / dlg_listy;
	int meczas = 0;
	int dlcz = static_cast<int>(godziny_pracy.size());

	try {
		if (dlcz % 2 == 0) {
			meczas = (godziny_pracy[dlcz / 2] + godziny_pracy[dlcz / 2 - 1]) / 2;
		}
		else
			meczas = godziny_pracy[dlcz / 2];
	}
	catch (...) {
		throw Wyjatek_pusta_lista();
	}

	cout << "STATYSTYKI DZIENNE\n\n";
	wyswietl_statystyki_konsola("placa godzinowa", srpl, varp, odspl, zbior_plac.rbegin()->first, zbior_plac.begin()->first);
	cout << endl;
	wyswietl_statystyki_konsola("standardowe godziny pracy", sredniczas, varczas, sqrt(varczas), *min_max.second, *min_max.first, 1, meczas);
	/*cout << std::setprecision(2) << std::fixed << "STATYSTYKI DZIENNE\n" << "Najwyzsza placa godzinowa: " << zbior_plac.rbegin()->first
		<< "\nNajnizsza placa godzinowa: " << zbior_plac.begin()->first << "\nSrednia placa godzinowa " << srpl << "\nWariancja placy godzinowej " << varp
		<< "\nOdchylenie standardowe placy godzinowej " << odspl << "\n\nSrednie wynagrodzenie " << srednie_w << endl;*/
}

void menu::wyczysc_liste() {
	queue<int> q;
	for (const auto& t : pracownicy) {
		q.push(t.getID());
	}
	int dlg = static_cast<int>(q.size());
	for (int i = 0; i < dlg; i++) {
		pracownicy.usun_element(q.front());
		q.pop();
	}
}

void menu::wyswietl_pliki_zapisu() {
	vector<string> pliki;
	znajdz_pliki_zapisu(pliki);
	cout << "Znalezione pliki zapisu\n";
	for (const auto& t : pliki) {
		cout << t << endl;
	}
}

void menu::znajdz_pliki_zapisu(vector<std::string>& vs) {
	using namespace std; using namespace filesystem;

	for (const directory_entry& plik : directory_iterator(current_path())) {
		string a = plik.path().extension().string();
		if (plik.path().extension().string() == ".txt") {
			auto sciezka = plik.path().filename();
			ifstream p(sciezka);
			const string naglowek = "zapisECP";
			string naglowek_sprawdz;
			getline(p, naglowek_sprawdz);
			p.close();
			if (naglowek_sprawdz == naglowek)
				vs.push_back(sciezka.string());
		}
	}
}

void menu::dodaj_pracownika_konsola() {
	string pr_imie, pr_nazwisko;
	int pr_wiek;
	cout << "Prosze podac imie pracownika     " << endl;
	std::istream_iterator<string> iit(std::cin);
	pr_imie = *iit;
	cout << "Prosze podac nazwisko pracownika     " << endl;
	cin.clear();
	pr_nazwisko = *++iit;
	cout << "Prosze podac wiek pracownika     " << endl;
	pr_wiek = wczytaj_liczbe_int_z_zakresu(16, 130);
	dodaj_pracownika(pr_imie, pr_nazwisko, pr_wiek);
}

void menu::dodaj_pracownika(string p_imie, string p_nazwisko, int p_wiek) {
	pracownik* n_pracownik = new pracownik(p_imie, p_nazwisko, p_wiek);
	n_pracownik->setStawkagodzinowa(pln_per_godzina_std, pln_per_godzina_dod);
	n_pracownik->setWydajnoscpracy(0, wymagana_ilosc_wykonanej_czynnosci);
	pracownicy.dodaj_element(*n_pracownik);
	delete n_pracownik;
}

void menu::wyswietl_liste_pracownikow(ostream& ofs) {
	system("cls");

	const int szer_im_naz = 12;
	const int szer_int = 10;
	const int szer_double = 11;
	const int ilosc_pol = 9;
	const string separator = " |";
	const int szer_wiersza = szer_im_naz * 2 + szer_int * 4 + szer_double * 3 + (int)separator.size() * ilosc_pol;
	const string wiersz = separator + string(szer_wiersza - 1, '=') + '|';


	ofs << wiersz << endl << separator
		<< setw(szer_int) << "Numer Id" << separator << setw(szer_im_naz) << "Imie" << separator
		<< setw(szer_im_naz) << "Nazwisko" << separator << setw(szer_int) << "Wiek" << separator
		<< setw(szer_int) << "Std czas" << separator
		<< setw(szer_int) << "Dod czas" << separator << setw(szer_double) << "Sredni czas" << separator
		<< setw(szer_double) << "Wydajnosc %" << separator << setw(szer_double) << "Placa" << separator << endl << wiersz << endl;

	auto begin = pracownicy.begin();
	auto end = pracownicy.end();
	if (kolejnosc) {
		begin = pracownicy.rbegin();
		end = pracownicy.rend();
	}

	for (auto t = begin; t != end;) {
		auto czas_pracy_p = t->getCzasPracy(dzien_tydzien_miesiac_rok);
		auto wydajnosc_pracy_p = t->getWydajnosc(dzien_tydzien_miesiac_rok);

		if (wysw_wydajnosc == 1) {
			if (get<1>(wydajnosc_pracy_p) < prog_wydajnosci) {
				kolejny(t, !kolejnosc);
				continue;
			}
		}
		else if (wysw_wydajnosc == 2) {
			if (get<1>(wydajnosc_pracy_p) >= prog_wydajnosci) {
				kolejny(t, !kolejnosc);
				continue;
			}
		}

		if (wysw_czas == 1) {
			if (t->getSumaCzasuPracy(dzien_tydzien_miesiac_rok) < wymagany_czas_pracy) {
				kolejny(t, !kolejnosc);
				continue;
			}
		}
		else if (wysw_czas == 2) {
			if (t->getSumaCzasuPracy(dzien_tydzien_miesiac_rok) >= wymagany_czas_pracy) {
				kolejny(t, !kolejnosc);
				continue;
			}
		}


		ofs << separator << std::setw(szer_int) << (*t)[0] << separator << std::setw(szer_im_naz) << (*t)[1] <<
			separator << std::setw(szer_im_naz) << (*t)[2] << separator
			<< setw(szer_int) << (*t)[3] << separator
			<< setw(szer_int) << get<0>(czas_pracy_p) << separator << setw(szer_int) << get<1>(czas_pracy_p) << separator
			<< fixed << std::setprecision(2) << setw(szer_double) << get<2>(czas_pracy_p) << separator << fixed
			<< std::setprecision(2) << setw(szer_double) << get<1>(wydajnosc_pracy_p) << separator << setw(szer_double)
			<< t->getWynagrodzenie(dzien_tydzien_miesiac_rok) << separator << endl;

		kolejny(t, !kolejnosc);
	}
	ofs << endl;
}

void menu::kolejny(lista::IteratorTS& i, bool plus_minus) {
	if (plus_minus) {
		i++;
	}
	else
		i--;
}

void menu::zapisz_parametry_plik() {
	string sciezkaout = ustaw_sciezke_zapisu_odczytu(1);
	if (czy_istnieje_plik(sciezkaout)) {
		cout << "Plik o podanej nazwie juz istnieje, czy chesz go nadpisac?" << endl
			<< "1 - nadpisz plik" << endl << "2 - anuluj" << endl;
		int wybor = wczytaj_liczbe_int_z_zakresu(1, 2);
		if (wybor == 2) {
			return;
		}
	}
	stringstream st;
	vector<string> bc; bc.reserve(6);
	st << std::fixed << std::setprecision(2) << (get<0>(get_wartosci_menu())) << " " << get<1>(get_wartosci_menu()) << " " << get<2>(get_wartosci_menu())
		<< " " << get<3>(get_wartosci_menu()) << " " << get<4>(get_wartosci_menu()) << " " << get<5>(get_wartosci_menu());
	copy(istream_iterator<string>(st), istream_iterator<string>(), back_inserter(bc));
	std::ofstream plik(sciezkaout);
	std::ostream_iterator<string> o(plik, " ");
	std::copy(bc.begin(), bc.end(), o);
	plik.close();
}

void menu::wczytaj_parametry_plik() {
	string sciezkain = ustaw_sciezke_zapisu_odczytu(0);
	ifstream plik(sciezkain);

	vector<string> temp;
	istream_iterator<string> ii(plik);
	while (ii != istream_iterator<string>()) {
		temp.push_back(*ii++);
	}

	stringstream s;
	for (auto& t : temp) {
		s << t << " ";
	}
	menu::operator>>(s);

	plik.close();
}

string menu::ustaw_sciezke_zapisu_odczytu(bool zapis) {
	string s;
	if (zapis)
		s = "wyjsciowego";
	else
		s = "wejsciowego";
	cout << "Podaj nazwe pliku " << s << " wraz z rozszerzeniem  ";
	s.clear();
	getline(cin >> ws, s);
	return s;
}

void menu::zapisz_do_pliku(const string& sciezkaout) {
	ofstream plik;
	plik.open(sciezkaout);
	const string naglowek = "zapisECP";
	plik << naglowek << endl;
	menu::utworz_menu().operator<<(plik) << endl;
	for (auto t = pracownicy.begin(); t != pracownicy.end(); t++) {
		plik << (*t) << endl;
	}
	logi::utworz_log().loguj("zapisano plik: " + sciezkaout, "", typeid(*this).name(), __func__);
	plik.close();
}

bool menu::wczytaj_plik(const string& sciezkain) {
	ifstream plik;
	plik.open(sciezkain);
	const string naglowek = "zapisECP";
	string naglowek_sprawdz;
	getline(plik, naglowek_sprawdz);
	if (naglowek_sprawdz == naglowek) {
		menu::operator>>(plik);
		pracownik* p = new pracownik(" ", " ", 0);
		while (plik >> *p) {
			pracownicy.dodaj_element(*p);
		}
		delete p;
		plik.close();
		ustaw_id();
		logi::utworz_log().loguj("wczytano plik: " + sciezkain, "", typeid(*this).name(), __func__);
		return 1;
	}
	plik.close();
	ustaw_id();
	logi::utworz_log().loguj("nie udalo sie wczytac pliu: " + sciezkain, "", typeid(*this).name(), __func__);
	return 0;
}

void menu::edytuj_pracownika_konsola() {
	int numer_id = 0;
	cout << "Prosze podac numer identyfikatora pracownika       ";
	numer_id = wczytaj_liczbe_int_dodatnia();
	if (czy_istnieje_pracownik(numer_id)) {
		auto PR = pracownicy.znajdz_wartosc(numer_id);
		(*PR).Wypisz();
		cout << endl << " Ktore parametry edytowac ? " << endl;
		cout << " 1 - imie" << endl << " 2 - nazwisko" << endl << " 3 - wiek"
			<< endl << " 4 - przepracowane godziny standardowe" << endl << " 5 - przepracowane godziny dodatkowe"
			<< endl << " 6 - wymagana ilosc czynnosci (w danym okresie czasu)" << endl << " 7 - wykonana ilosc czynnosci" << endl
			<< " 8 - stawka godzinowa standardowa" << endl << " 9 - stawka godzinowa dodatkowa" << endl
			<< "10 - zmiejsz ilosc wykonanej czynnosci" << endl << "11 - zmniejsz czas pracy" << endl << "12 - anuluj" << endl;
		int wybor = wczytaj_liczbe_int_z_zakresu(1, 12);
		if (wybor == 1 || wybor == 2) {
			cout << endl << "Prosze podac nowa wartosc:   ";
			string e_wartosc;
			cin >> e_wartosc;
			edytuj_pracownika(wybor, PR, e_wartosc);
		}
		else if (wybor == 6) {
			int e_wartosc;
			cout << "Prosze podac w jakim okresie czasu ustawic nowa ilosc" << endl;
			cout << "1 - dzien" << endl << "2 - tydzien" << endl << "3 - miesiac" << endl << "4 - rok" << endl;
			switch (wczytaj_liczbe_int_z_zakresu(1, 4)) {
			case 1:
				cout << "Prosze podac nowa wartosc:   ";
				e_wartosc = wczytaj_liczbe_int_dodatnia();
				edytuj_pracownika(wybor, PR, " ", e_wartosc);
				break;
			case 2: {
				cout << endl << "Prosze podac numer tygdodnia (1-53):   ";
				int nr_t = wczytaj_liczbe_int_z_zakresu(1, 53);
				cout << "Prosze podac nowa wartosc:   ";
				e_wartosc = wczytaj_liczbe_int_dodatnia();
				(PR)->setIlosc_wymagana(2, e_wartosc, nr_t);
			}
				  break;
			case 3: {
				cout << endl << "Prosze podac numer miesiaca (1-12):   ";
				int nr_m = wczytaj_liczbe_int_z_zakresu(1, 12);
				cout << "Prosze podac nowa wartosc:   ";
				e_wartosc = wczytaj_liczbe_int_dodatnia();
				(PR)->setIlosc_wymagana(3, e_wartosc, nr_m);
			}
				  break;
			case 4:
				cout << "Prosze podac nowa wartosc:   ";
				e_wartosc = wczytaj_liczbe_int_dodatnia();
				(PR)->setIlosc_wymagana(3, e_wartosc);
				break;
			}
		}
		else if (wybor == 8 || wybor == 9) {
			cout << "Prosze podac nowa wartosc:   ";
			double e_wartosc;
			e_wartosc = wczytaj_liczbe_double_dodatnia();
			edytuj_pracownika(wybor, PR, " ", 0, e_wartosc);
		}
		else if (wybor == 12) {
			return;
		}
		else if (wybor == 10) {
			cout << "Prosze podac ilosc o jaka zmniejszyc ilosc wykonanej czynnosci:   ";
			int e_wartosc = wczytaj_liczbe_int_dodatnia();
			(PR)->zmniejszIlosc_czynnosci(e_wartosc);
		}
		else if (wybor == 11) {
			cout << "Prosze podac ilosc o jaka zmniejszyc czas pracy (godz std):   ";
			int e_wartosc = wczytaj_liczbe_int_dodatnia();
			(PR)->zmniejszCzasPracyStd(e_wartosc);
		}
		else if (wybor != 11) {
			cout << "Prosze podac nowa wartosc:   ";
			int e_wartosc;
			e_wartosc = wczytaj_liczbe_int_dodatnia();
			if (!edytuj_pracownika(wybor, PR, " ", e_wartosc)) {
				cout << "Nie mozna ustawic podanej wartosci, sprawdz poprawnosc danych." << endl;
				system("pause");
			}
		}
	}
	else {
		cout << endl << "Nie istnieje pracownik o podanym numerze" << endl;
		system("pause");
		return;
	}
}

bool menu::edytuj_pracownika(int wybor, pracownik* PR, const string& ed_string, int ed_int, double ed_double) {

	switch (wybor) {
	case 1:
	{
		(PR)->setImie(ed_string);
		break;
	}
	case 2:
	{
		(PR)->setNazwisko(ed_string);
		break;
	}
	case 3:
	{
		(PR)->setWiek(ed_int);
		break;
	}
	case 4:
	{
		if ((PR)->setCzaspracy(ed_int, get<1>((PR)->getCzasPracy(1))))
			return 1;
		else
			return 0;
		break;
	}
	case 5:
	{
		if ((PR)->setCzaspracy(get<0>((PR)->getCzasPracy(1)), ed_int))
			return 1;
		else
			return 0;
		break;
	}
	case 7:
	{
		(PR)->setWydajnoscpracy(ed_int, get<2>((PR)->getWydajnosc(1)));
		break;
	}
	case 8:
	{
		(PR)->setStawkagodzinowa(ed_double, get<1>((PR)->getStawkagodzinowa()));
		break;
	}
	case 9:
	{
		(PR)->setStawkagodzinowa(get<0>((PR)->getStawkagodzinowa()), ed_double);
		break;
	}
	}
	return 1;
}

void menu::ustaw_nowe_parametry_programu(int ktory_parametr) {
	switch (ktory_parametr) {
	case 1:
		cout << "Prosze podac wynagrodzenie za godzine pracy (w zwyklym czasie pracy)     ";
		pln_per_godzina_std = wczytaj_liczbe_double_dodatnia();
		break;
	case 2:
		cout << "Prosze podac wynagrodzenie za godzine pracy (w dodatkowym czasie pracy)     ";
		pln_per_godzina_dod = wczytaj_liczbe_double_dodatnia();
		break;
	case 3:
		cout << "Prosze podac wymagana ilosc wykonanych czynnosci     ";
		wymagana_ilosc_wykonanej_czynnosci = wczytaj_liczbe_int_dodatnia();
		break;
	case 4:
		cout << "Prosze podac wymagany miesieczny czas pracy (do wyswietlania)    ";
		wymagany_czas_pracy = wczytaj_liczbe_int_dodatnia();
		break;
	case 5:
		cout << "Prosze podac prog wydajnosci (do wyswietlania)    ";
		prog_wydajnosci = wczytaj_liczbe_double_dodatnia();
		break;
	case 6:
		cout << "Prosze podac wynagrodzenie za godzine pracy (w zwyklym czasie pracy)     ";
		pln_per_godzina_std = wczytaj_liczbe_double_dodatnia();
		cout << "Prosze podac wynagrodzenie za godzine pracy (w dodatkowym czasie pracy)     ";
		pln_per_godzina_dod = wczytaj_liczbe_double_dodatnia();
		cout << "Prosze podac wymagana ilosc wykonanych czynnosci     ";
		wymagana_ilosc_wykonanej_czynnosci = wczytaj_liczbe_int_dodatnia();
		cout << "Prosze podac wymagany miesieczny czas pracy     ";
		wymagany_czas_pracy = wczytaj_liczbe_int_dodatnia();
		cout << "Prosze podac prog wydajnosci (do wyswietlania)    ";
		prog_wydajnosci = wczytaj_liczbe_double_dodatnia();
		cout << "Prosze podac pierwszy dzien tygodnia (nr) w roku   ";
		pierwszy_dzien_roku = wczytaj_liczbe_int_z_zakresu(1, 7) - 1;
		break;
	}
}

void menu::wczytaj_plik_konsola(bool norm) {
	bool anuluj = 0;
	string sciezkain = ustaw_sciezke_zapisu_odczytu(0);
	while (!czy_istnieje_plik(sciezkain)) {
		system("cls");
		cout << "Nie ma takiego pliku" << endl
			<< "Podaj sciezke do pliku wejsciowego lub nacisnij \"c\", aby anulowac   ";
		getline(cin >> ws, sciezkain);
		if (sciezkain == "c") {
			anuluj = 1;
			break;
		}
	}
	if (!anuluj) {
		if (norm) {
			if (wczytaj_plik(sciezkain))
				cout << "Pomyslnie wczytano plik" << endl;
			else {
				cout << "Plik nie jest prawidlowym plikiem zapisu progamu ECP +++ PRO 2022" << endl;
				wyczysc_liste();
			}
		}
		else {
			pracownicy.deserializuj_plik(sciezkain);
			cout << "Pomyslnie wczytano plik" << endl;
		}
	}
}

void menu::nowe_parametry_programu_konsola() {
	cout << "Ktore parametry maja byc zmienione:"
		<< endl << "1 - wynagrodzenie za godzine pracy (w zwyklym czasie pracy)"
		<< endl << "2 - wynagrodzenie za godzine pracy (w dodatkowym czasie pracy)"
		<< endl << "3 - wymagana ilosc wykonanych czynnosci (dla wyswietlania listy pracownikow)"
		<< endl << "4 - wymagany czas pracy (dla wyswietlania listy pracownikow)"
		<< endl << "5 - wymagana wydajnosc pracownika (dla wyswietlania listy pracownikow)"
		<< endl << "6 - wszystkie parametry programu"
		<< endl << "7 - anuluj" << endl;
	int x = wczytaj_liczbe_int_z_zakresu(1, 7);
	if (x == 7)
		return;
	else
		ustaw_nowe_parametry_programu(x);
}

void menu::wczytaj_nowy_plik_konsola() {
	cout << "Obecne dane zostana utracone. Czy na pewno chcesz kontynuowac? 1 - kontynuuj, 2 - powrot do menu   ";
	switch (wczytaj_liczbe_int_z_zakresu(1, 2)) {
	case 2:
		return;
	case 1:
		wyczysc_liste();
		wczytaj_plik_konsola();
	}
}

void menu::parametry_wyswietlania() {
	cout << "1 - wyswietlanie pracownikow z okreslona wydajnoscia / czasem pracy" << endl
		<< "2 - dane dzienne/tygodniowe/miesieczne/roczne" << endl
		<< "3 - sortuj" << endl
		<< "4 - kolejnosc listy zwykla / odwrotna" << endl
		<< "5 - anuluj" << endl;
	switch (wczytaj_liczbe_int_z_zakresu(1, 5)) {
	case 5:
		return;
		break;
	case 1:
	{
		cout << "Wyswietlanie pracownikow" << endl
			<< "1 - Z czasem pracy, spelniajacym norme" << endl
			<< "2 - Z czasem pracy, niespelniajacym normy" << endl
			<< "3 - Z wydajnoscia, spelniajaca norme" << endl
			<< "4 - Z wydajnoscia, niespelniajaca normy" << endl
			<< "5 - Zresetuj ustawienia czasu pracy (1,2)" << endl
			<< "6 - Zresetuj ustawienia wydajnosci pracy (3,4)" << endl;
		switch (wczytaj_liczbe_int_z_zakresu(1, 6)) {
		case 1:
			wysw_czas = 1;
			break;
		case 2:
			wysw_czas = 2;
			break;
		case 3:
			wysw_wydajnosc = 1;
			break;
		case 4:
			wysw_wydajnosc = 2;
			break;
		case 5:
			wysw_czas = 0;
			break;
		case 6:
			wysw_wydajnosc = 0;
			break;
		}
	}
	break;
	case 2:
		cout << "1 - dane dzienne" << endl
			<< "2 - dane tygodniowe" << endl
			<< "3 - dane miesieczne" << endl
			<< "4 - dane roczne" << endl;
		dzien_tydzien_miesiac_rok = wczytaj_liczbe_int_z_zakresu(1, 4);
		break;
	case 3: {
		cout << "Sortuj wedlug" << endl
			<< "1 - numer identyfikatora" << endl
			<< "2 - czas pracy standardowy" << endl
			<< "3 - czas pracy dodatkowy" << endl
			<< "4 - imie" << endl
			<< "5 - nazwisko" << endl
			<< "6 - wydajnosc" << endl
			<< "7 - wynagrodzenie" << endl;
		sort_wybor = wczytaj_liczbe_int_z_zakresu(1, 7);

		auto poczatek = std::chrono::high_resolution_clock::now();
		pracownicy.sortowanie(sort_wybor, dzien_tydzien_miesiac_rok);
		auto koniec = std::chrono::high_resolution_clock::now();
		auto czas = duration_cast<std::chrono::microseconds>(koniec - poczatek);
		logi::utworz_log().loguj("Sortowanie, czas sortowania w us", to_string(czas.count()), typeid(*this).name(), __func__);
	}
		  break;
	case 4:
		kolejnosc = !kolejnosc;
		break;
	}
}

void menu::ustaw_id() {
	if (pracownicy.czy_nie_pusta()) {
		auto maxIDpracownik = pracownicy.najwiekszy_element_ID();
		(*maxIDpracownik).setMinID((*maxIDpracownik).getID());
	}
}

void menu::dodaj_nowa_prace_pracownika() {
	int numer_id = 0;
	cout << "Prosze podac numer identyfikatora pracownika       ";
	numer_id = wczytaj_liczbe_int_dodatnia();
	if (czy_istnieje_pracownik(numer_id)) {
		pracownik* PR = pracownicy.znajdz_wartosc(numer_id);
		cout << "Co chcesz zrobic? " << endl
			<< "1 - zwieksz czas pracy standardowy" << endl
			<< "2 - zwieksz czas pracy dodatkowy" << endl
			<< "3 - zwieksz ilosc wykonanej pracy" << endl
			<< "4 - anuluj" << endl;
		int wybor = wczytaj_liczbe_int_z_zakresu(1, 4);
		if (wybor != 4)
			cout << "Prosze podac ilosc do dodania:  " << endl;
		else {
			return;
		}
		int ilosc = wczytaj_liczbe_int_dodatnia();
		switch (wybor) {
		case 1:
			if (!(PR)->zwiekszCzasPracyStd(ilosc)) {
				cout << "Nie mozna ustawic podanej wartosci, sprawdz poprawnosc danych." << endl;
				system("pause");
			}
			break;
		case 2:
			if (!(PR)->zwiekszCzasPracyDod(ilosc)) {
				cout << "Nie mozna ustawic podanej wartosci, sprawdz poprawnosc danych." << endl;
				system("pause");
			}
			break;
		case 3:
			(PR)->zwiekszIloscCzynnosci(ilosc);
			break;
		}
	}
	else {
		cout << "Nie istnieje pracownik o podanym numerze. Powrot do menu." << endl;
		system("pause");
	}
}

bool menu::czy_istnieje_pracownik(int numer_id) {
	if (pracownicy.czy_istnieje(numer_id))
		return 1;
	else {
		logi::utworz_log().loguj("brak pracownika o nr id: " + numer_id, " ", typeid(*this).name(), __func__);
		return 0;
	}
}

void menu::usun_pracownika(int numer_id) {
	pracownicy.usun_element(numer_id);
}

void menu::usun_pracownika_konsola() {
	cout << "Prosze podac numer identyfikatora pracownika       ";
	int numer_id = 0;
	numer_id = wczytaj_liczbe_int_dodatnia();
	try {
		usun_pracownika(numer_id);
		cout << "Pomyslnie usunieto pracownika o numerze id: " << numer_id << endl;
	}
	catch (Wyjatek_brak_elementu) {
		cout << "Nie istnieje pracownik o podanym numerze. Powrot do menu." << endl;
	}
	catch (Wyjatek_pusta_lista) {
		cout << "Wystapil blad, lista jest pusta" << endl;;
	}
}

void menu::wyswietl_parametry_programu() {
	cout << fixed << setprecision(2) << "Wynagrodzenie za godzine pracy(w zwyklym czasie pracy): " << get<0>(get_wartosci_menu()) << endl
		<< "Wynagrodzenie za godzine pracy (w dodatkowym czasie pracy): " << get<1>(get_wartosci_menu()) << endl
		<< "Wymagana ilosc wykonanych czynnosci (dla wyswietlania listy pracownikow): " << get<2>(get_wartosci_menu()) << endl
		<< "Wymagany czas pracy (dla wyswietlania listy pracownikow): " << get<3>(get_wartosci_menu()) << endl
		<< "Prog wydajnosci (dla wyswietlania listy pracownikow): " << get<4>(get_wartosci_menu()) << endl
		<< "Pierwszy dzien roku: " << get<5>(get_wartosci_menu()) + 1 << ", " << dzien_tygodnia_nazwa(get<5>(get_wartosci_menu()) + 1) << endl;
	system("pause");
}

void menu::zapisz_liste_konsola() {
	string nazwaout = ustaw_sciezke_zapisu_odczytu(1);
	ofstream pliklista(nazwaout);
	wyswietl_liste_pracownikow(pliklista);
	pliklista.close();
}

void menu::zapisz_plik_konsola(bool norm) {
	string sciezkaout = ustaw_sciezke_zapisu_odczytu(1);
	if (czy_istnieje_plik(sciezkaout)) {
		cout << "Plik o podanej nazwie juz istnieje, czy chesz go nadpisac?" << endl
			<< "1 - nadpisz plik" << endl << "2 - anuluj" << endl;
		int wybor = wczytaj_liczbe_int_z_zakresu(1, 2);
		if (wybor == 2) {
			return;
		}
	}
	if (norm)
		zapisz_do_pliku(sciezkaout);
	else {
		try {
			pracownicy.serializuj_do_pliku(sciezkaout);
		}
		catch (Wyjatek_pusta_lista) {
			cout << "Lista jest pusta" << endl;
			return;
		}
	}
	cout << "Pomyslnie zapisano plik" << endl;
}

void menu::zmien_dzien() {
	cout << "Zmiana dnia: " << endl
		<< "1 - wybrany dzien" << endl
		<< "2 - nastepny dzien" << endl
		<< "3 - poprzedni dzien" << endl
		<< "4 - anuluj" << endl;

	switch (wczytaj_liczbe_int_z_zakresu(1, 4)) {
	case 4:
		return;
	case 1:
		cout << "Prosze podac dzien: " << endl;
		obecny_dzien = wczytaj_liczbe_int_z_zakresu(1, 365);
		break;
	case 2:
		if (obecny_dzien < 365)
			obecny_dzien++;
		else {
			cout << "Nie ma wiecej dni w roku.";
			cout << endl;
			system("pause");
		}
		break;
	case 3:
		if (obecny_dzien != 1)
			obecny_dzien--;
		else {
			cout << "Obecny dzien to pierwszy dzien roku.";
			cout << endl;
			system("pause");
		}
		break;
	}
}

void menu::ustaw_dzien_tydzien_miesiac_rok_pracownikow() {
	for (auto t = pracownicy.begin(); t != pracownicy.end(); t++) {
		auto P = t;
		(P)->setDzien_tydzien_i_miesiac(obecny_dzien, obecny_tydzien, obecny_miesiac);
	}
}

void menu::pokaz_wybrany_czas_konsola() {
	cout << "Prosze podac numer identyfikatora pracownika       ";
	int numer_id = wczytaj_liczbe_int_dodatnia();
	if (czy_istnieje_pracownik(numer_id)) {
		auto PR = pracownicy.znajdz_wartosc(numer_id);
		cout << "Prosze podac jaki czas pracy podac" << endl
			<< "1 - dzienny" << endl
			<< "2 - tygodniowy" << endl
			<< "3 - miesieczny" << endl
			<< "4 - roczny" << endl;
		switch (wczytaj_liczbe_int_z_zakresu(1, 4)) {
		case 1:
			cout << "Prosze podac numer dnia (1-365):   ";
			(PR)->wyswietl_czas_pracownika(1, 0, 0, wczytaj_liczbe_int_z_zakresu(1, 365));
			break;
		case 2:
			cout << "Prosze podac numer tygodnia (1-53):   ";
			(PR)->wyswietl_czas_pracownika(2, 0, wczytaj_liczbe_int_z_zakresu(1, 53));
			break;
		case 3:
			cout << "Prosze podac numer miesiaca (1-12):   ";
			(PR)->wyswietl_czas_pracownika(3, wczytaj_liczbe_int_z_zakresu(1, 12));
			break;
		case 4:
			(PR)->wyswietl_czas_pracownika(4);
			break;
		}
	}
	else {
		cout << "Nie istnieje pracownik o podanym numerze. Powrot do menu." << endl;
	}
	system("pause");
}

int menu::oblicz_dzien_tygodnia() {
	int x = (((obecny_dzien - (obecny_tydzien - 1) * 7) + pierwszy_dzien_roku - 1) % 7) + 1;
	return x;
}

string menu::dzien_tygodnia_nazwa(int nr_dnia)
{
	string dzien;
	switch (nr_dnia) {
	case 1:
		dzien = "poniedzialek";
		break;
	case 2:
		dzien = "wtorek";
		break;
	case 3:
		dzien = "sroda";
		break;
	case 4:
		dzien = "czwartek";
		break;
	case 5:
		dzien = "piatek";
		break;
	case 6:
		dzien = "sobota";
		break;
	case 7:
		dzien = "niedziela";
		break;
	}
	return dzien;
}

string menu::wyswietlanie_nazwa() {
	string nazwa;
	switch (dzien_tydzien_miesiac_rok) {
	case 1:
		nazwa = "dzienna";
		break;
	case 2:
		nazwa = "tygodniowa";
		break;
	case 3:
		nazwa = "miesieczna";
		break;
	case 4:
		nazwa = "roczna";
		break;
	}
	return nazwa;
}

ostream& menu::operator<<(ostream& os) {
	const string separator = " ";
	os << fixed << setprecision(2) << get<0>(get_wartosci_menu()) << separator << get<1>(get_wartosci_menu()) << separator << get<2>(get_wartosci_menu())
		<< separator << get<3>(get_wartosci_menu()) << separator << get<4>(get_wartosci_menu()) << separator << get<5>(get_wartosci_menu());
	return os;
}

istream& menu::operator>>(istream& is) {
	stringstream s;
	string wczytana_linia;
	getline(is, wczytana_linia);
	s << wczytana_linia;
	double menu_double_wartosci[3] = { 0 };
	int menu_int_wartosci[3] = { 0 };
	for (int i = 0; i < 2; i++)
		s >> menu_double_wartosci[i];
	for (int i = 0; i < 2; i++)
		s >> menu_int_wartosci[i];
	s >> menu_double_wartosci[2];
	s >> menu_int_wartosci[2];
	set_wartosci_menu(menu_double_wartosci[0], menu_double_wartosci[1], menu_int_wartosci[0], menu_int_wartosci[1], menu_double_wartosci[2], menu_int_wartosci[2] - 1);
	return is;
}

void menu::ustaw_miesiac() {
	if (czy_lezy_w_zakrese(1, 181, obecny_dzien)) {
		if (czy_lezy_w_zakrese(1, 90, obecny_dzien)) {
			if (czy_lezy_w_zakrese(1, 59, obecny_dzien)) {
				if (czy_lezy_w_zakrese(1, 31, obecny_dzien)) {
					obecny_miesiac = 1;
					dzien_miesiaca = obecny_dzien;
				}
				else
				{
					obecny_miesiac = 2;
					dzien_miesiaca = obecny_dzien - 31;
				}
			}
			else {
				obecny_miesiac = 3;
				dzien_miesiaca = obecny_dzien - 59;
			}
		}
		else
			if (czy_lezy_w_zakrese(91, 181, obecny_dzien)) {
				if (czy_lezy_w_zakrese(91, 151, obecny_dzien)) {
					if (czy_lezy_w_zakrese(91, 120, obecny_dzien)) {
						obecny_miesiac = 4;
						dzien_miesiaca = obecny_dzien - 90;
					}
					else {
						obecny_miesiac = 5;
						dzien_miesiaca = obecny_dzien - 120;
					}
				}
				else {
					obecny_miesiac = 6;
					dzien_miesiaca = obecny_dzien - 151;
				}
			}
	}
	else {
		if (czy_lezy_w_zakrese(182, 273, obecny_dzien)) {
			if (czy_lezy_w_zakrese(182, 243, obecny_dzien)) {
				if (czy_lezy_w_zakrese(182, 212, obecny_dzien)) {
					obecny_miesiac = 7;
					dzien_miesiaca = obecny_dzien - 181;
				}
				else {
					obecny_miesiac = 8;
					dzien_miesiaca = obecny_dzien - 212;
				}
			}
			else {
				obecny_miesiac = 9;
				dzien_miesiaca = obecny_dzien - 243;
			}
		}
		else
			if (czy_lezy_w_zakrese(274, 365, obecny_dzien)) {
				if (czy_lezy_w_zakrese(274, 334, obecny_dzien)) {
					if (czy_lezy_w_zakrese(274, 304, obecny_dzien)) {
						obecny_miesiac = 10;
						dzien_miesiaca = obecny_dzien - 273;
					}
					else {
						obecny_miesiac = 11;
						dzien_miesiaca = obecny_dzien - 304;
					}
				}
				else {
					obecny_miesiac = 12;
					dzien_miesiaca = obecny_dzien - 334;
				}
			}
	}
}

void menu::ustaw_tydzien() {
	for (int i = 1; i < 54; i++) {
		if (czy_lezy_w_zakrese(((7 * (i - 1)) + 1), (7 * i), obecny_dzien)) {
			obecny_tydzien = i;
			break;
		}
	}
	return;
}