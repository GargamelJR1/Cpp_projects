#pragma once
#include "sha_ptr.h"
#include "pracownik.h"
#include "logi.h"
#include <functional>


/**
* Klasa wyj¹tku pustej listy.
*/
class Wyjatek_pusta_lista :exception {
public:
	Wyjatek_pusta_lista() {
		logi::utworz_log().loguj("Wystapil wyjatek, Wyjatek_pusta_lista", "", "", "");
	}
};

/**
* Klasa wyj¹tku braku elementu.
*/
class Wyjatek_brak_elementu :exception {
public:
	Wyjatek_brak_elementu() {
		logi::utworz_log().loguj("Wystapil wyjatek, Wyjatek_brak_elementu", "", "", "");
	}
};

class wezel {
	pracownik dane;
	//std::weak_ptr<wezel> poprzedni;
	sha_ptr<wezel> nastepny;
	sha_ptr<wezel> poprzedni;

public:
	wezel(const pracownik& dana) :dane(dana), nastepny(nullptr) {};

	friend class lista;
};

sha_ptr<wezel> make_shar(const pracownik& pr);

class lista {
	sha_ptr<wezel> pierwszy;
public:

	lista() = default;

	lista(const lista& cl) {
		if (cl.pierwszy.get() != nullptr) {
			pierwszy = make_shar(cl.pierwszy->dane);
			auto temp = cl.pierwszy->nastepny;
			auto temp2 = pierwszy;
			while (temp != nullptr) {
				temp2->nastepny = make_shar(temp->dane);
				temp2->nastepny->poprzedni = temp2;
				temp = temp->nastepny;
				temp2 = temp2->nastepny;
			}
		}
	}

	lista(lista&& cl) noexcept {
		pierwszy = cl.pierwszy;
		cl.pierwszy = nullptr;
	}

	lista& operator=(const lista& cl) {
		if (this == &cl)
			return *this;
		else if (pierwszy.get() != nullptr) {

			wyczysc_liste();

			pierwszy = make_shar(cl.pierwszy->dane);
			auto temp = cl.pierwszy->nastepny;
			auto temp2 = pierwszy;
			while (temp->nastepny != nullptr) {
				temp2->nastepny = temp;
				temp = temp->nastepny;
				temp2 = temp2->nastepny;
			}
		}
		return *this;
	}

	lista& operator=(lista&& cl) noexcept {
		pierwszy = cl.pierwszy;
		cl.pierwszy = nullptr;
		return *this;
	}

	void wyczysc_liste() {
		/*	if (pierwszy.get() != nullptr) {
				auto temp = pierwszy;
				while (temp->nastepny != nullptr) {
					temp = temp->nastepny;
				}

				while (temp->poprzedni != nullptr) {
					temp = nullptr;
				}
				pierwszy = nullptr;

			}*/
		while (pierwszy != nullptr) {
			usun_element(begin()->getID());
		}

	}


	void dodaj_element(const pracownik& ni) {
		if (pierwszy != nullptr) {
			auto temp = pierwszy;
			while (temp->nastepny != nullptr) {
				temp = temp->nastepny;
			}
			temp->nastepny = make_shar(ni);
			temp->nastepny->poprzedni = temp;
		}
		else {
			pierwszy = make_shar(ni);
		}
	}

	void usun_element(const int zi) {
		if (pierwszy.get() != nullptr) {
			if (pierwszy->dane.getID() == zi) {
				if (pierwszy->nastepny != nullptr) {
					pierwszy = pierwszy->nastepny;
					pierwszy->poprzedni = nullptr;
				}
				else
					pierwszy = nullptr;
			}
			else if (pierwszy->nastepny != nullptr) {
				auto temp = pierwszy->nastepny;
				auto temp2 = pierwszy;
				while (temp->nastepny != nullptr) {
					if (temp->dane.getID() == zi) {
						temp2->nastepny = temp->nastepny;
						if (temp == pierwszy)
							temp->poprzedni = nullptr;
						else
							temp->poprzedni = temp2;
						break;
					}
					if (temp->nastepny != nullptr) {
						temp = temp->nastepny;
						temp2 = temp2->nastepny;
						if (temp == nullptr || (temp->dane.getID() != zi && temp->nastepny == nullptr))
							throw Wyjatek_brak_elementu();
						if (temp != nullptr && temp->dane.getID() == zi) {
							if (temp->nastepny != nullptr) {
								temp2->nastepny = temp->nastepny;
								temp->poprzedni = temp2;
							}
							else {
								temp2->nastepny = nullptr;
							}
							break;
						}
					}
					else
						throw Wyjatek_brak_elementu();
				}
			}
			else
				throw Wyjatek_brak_elementu();
		}
		else
			throw Wyjatek_pusta_lista();
	}

	class IteratorTS {
		wezel* wskaznik_it;

		using value_type = pracownik;
		using pointer = pracownik*;
		using reference = pracownik&;

	public:
		IteratorTS(sha_ptr<wezel> wptr) : wskaznik_it(wptr.get()) {}
		reference operator*() const { return *&(wskaznik_it->dane); }
		pointer operator->() { return &(wskaznik_it->dane); }
		IteratorTS operator+(int ile) { IteratorTS temp = *this; temp += ile; return temp; }
		IteratorTS& operator+=(int ile) { for (int i = 0; i < ile; i++) wskaznik_it = wskaznik_it->nastepny.get(); return *this; }
		IteratorTS& operator++() { wskaznik_it = wskaznik_it->nastepny.get(); return *this; }
		IteratorTS operator++(int) { IteratorTS temp = *this; wskaznik_it = wskaznik_it->nastepny.get(); return temp; }
		IteratorTS operator-(int ile) { IteratorTS temp = *this; temp -= ile; return temp; }
		IteratorTS& operator-=(int ile) { for (int i = 0; i < ile; i++) wskaznik_it = wskaznik_it->poprzedni.get(); return *this; }
		IteratorTS& operator--() { wskaznik_it = wskaznik_it->poprzedni.get(); return *this; }
		IteratorTS operator--(int) { IteratorTS temp = *this; wskaznik_it = wskaznik_it->poprzedni.get(); return temp; }

		bool operator== (const IteratorTS& i1) { return i1.wskaznik_it == wskaznik_it; };
		bool operator!= (const IteratorTS& i1) { return i1.wskaznik_it != wskaznik_it; };
	};

	IteratorTS begin() {
		return IteratorTS(pierwszy);
	}

	IteratorTS rbegin() {
		auto temp = pierwszy;
		if (pierwszy != nullptr) {
			while (temp->nastepny != nullptr) {
				temp = temp->nastepny;
			}
		}
		return IteratorTS(temp);
	}

	IteratorTS end() {
		return IteratorTS(nullptr);
	}

	IteratorTS rend() {
		return IteratorTS(nullptr);
	}

	pracownik* znajdz_wartosc(const int zi) const {
		if (pierwszy.get() != nullptr) {
			if (pierwszy->dane.getID() == zi) {
				return &pierwszy.get()->dane;
			}
			else {
				auto temp = pierwszy;
				while (temp->nastepny != nullptr) {
					if (temp->dane.getID() == zi)
						return &temp->dane;
					temp = temp->nastepny;
				}
				if (temp != nullptr && temp->dane.getID() == zi)
					return &temp->dane;
			}
		}
		return nullptr;
	}

	void sortowanie(int wybor = 1, int dz_ms_rk = 1) {
		int rozm = 0;

		if (pierwszy != nullptr) {
			rozm = 1;
			auto temp = pierwszy;
			while (temp->nastepny != nullptr) {
				temp = temp->nastepny;
				rozm++;
			}

			pracownik** tab = new pracownik * [(rozm)];
			temp = pierwszy;
			tab[0] = new pracownik(temp->dane);
			int i = 1;
			while (temp->nastepny != nullptr) {
				temp = temp->nastepny;
				tab[i++] = new pracownik(temp->dane);
			}

			function<int(pracownik&)> f = &pracownik::getID;
			function<std::string(pracownik&)> fs = &pracownik::getImie;
			function<double(pracownik&, int tyd_mies_rok)> fd = &pracownik::getWynagrodzenie;
			function<tuple<int, double, int>(pracownik&, int tyd_mies_rok)> ftw = &pracownik::getWydajnosc;
			function<tuple<int, int, double>(pracownik&, int tyd_mies_rok)> ftc = &pracownik::getCzasPracy;

			if (wybor == 4)
				fs = &pracownik::getImie;
			else if (wybor == 5)
				fs = &pracownik::getNazwisko;


			// algorytm sortowanie przez proste wybieranie ze skryptu "AiSD Wybrane zagadnienia"
			for (int i = 0; i < rozm - 1; i++) {
				int k = i; pracownik* x = tab[i];
				for (int j = i + 1; j < rozm; j++) {
					switch (wybor) {
					case 1:
						if (f(*tab[j]) < f(*x)) {
							k = j; x = tab[j];
						}
						break;
					case 2:
						if (get<0>(ftc(*tab[j], dz_ms_rk)) > get<0>(ftc(*x, dz_ms_rk))) {
							k = j; x = tab[j];
						}
						break;
					case 3:
						if (get<1>(ftc(*tab[j], dz_ms_rk)) > get<1>(ftc(*x, dz_ms_rk))) {
							k = j; x = tab[j];
						}
						break;
					case 4: case 5:
						if (fs(*tab[j]) < fs(*x)) {
							k = j; x = tab[j];
						}
						break;
					case 6:
						if (get<1>(ftw(*tab[j], dz_ms_rk)) > get<1>(ftw(*x, dz_ms_rk))) {
							k = j; x = tab[j];
						}
						break;
					case 7:
						if (fd(*tab[j], dz_ms_rk) > fd(*x, dz_ms_rk)) {
							k = j; x = tab[j];
						}
						break;
					}
				}
				tab[k] = tab[i]; tab[i] = x;
			}


			auto temp2 = pierwszy;
			for (int s = 0; s < rozm; s++) {
				temp2->dane = *tab[s];
				temp2 = temp2->nastepny;
			}

			for (int s = 0; s < rozm; s++) {
				delete tab[s];
			}
			delete[] tab;
		}
	}

	int dlugosc() {
		int rozm{ 0 };
		if (pierwszy != nullptr) {
			rozm = 1;
			auto temp = pierwszy;
			while (temp->nastepny != nullptr) {
				temp = temp->nastepny;
				rozm++;
			}
		}
		return rozm;
	}

	bool czy_nie_pusta() {
		return (pierwszy != nullptr);
	}

	bool czy_istnieje(int nr) {
		return (znajdz_wartosc(nr) != nullptr);
	}

	void serializuj_do_pliku(const string& nazwa) {
		if (pierwszy != nullptr) {
			auto temp = pierwszy;
			ofstream out(nazwa);
			while (temp != nullptr) {
				out << temp->dane << endl;
				temp = temp->nastepny;
			}
			out.close();
		}
		else
			throw Wyjatek_pusta_lista();
	}

	void deserializuj_plik(const string& nazwa) {
		filesystem::path sciezka(filesystem::current_path());
		filesystem::path sciezka_do_pliku(sciezka / nazwa);
		ifstream plik(sciezka_do_pliku);
		pracownik* p = new pracownik(" ", " ", 0);

		while (plik >> *p) {
			dodaj_element(*p);
		}
		delete p;
		plik.close();

		plik.close();
	}

	pracownik* najwiekszy_element_ID() {
		if (pierwszy != nullptr) {
			auto temp = pierwszy;
			auto max = pierwszy;
			while (temp->nastepny != nullptr) {
				temp = temp->nastepny;
				if (temp->dane.getID() > max->dane.getID())
					max = temp;
			}
			return &max->dane;
		}
		else
			return nullptr;
	}


	~lista() {
		/*if (pierwszy != nullptr) {
			auto temp = pierwszy;
			while (temp->nastepny != nullptr) {
				temp->poprzedni = nullptr;
				temp = temp->nastepny;
			}
		}*/
		wyczysc_liste();
	}
};
