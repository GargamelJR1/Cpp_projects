#pragma once

class licznik {
	unsigned int licz;

public:
	licznik() :licz(0) {};

	licznik(const licznik&) = delete;
	licznik& operator=(const licznik&) = delete;
	licznik(int iniwar) :licz(iniwar) {};
	~licznik() = default;

	void zeruj() {
		licz = 0;
	}

	unsigned int pobierz_wartosc() {
		return licz;
	}

	void operator++() {
		licz++;
	}

	void operator++(int) {
		licz++;
	}

	void operator--() {
		licz--;
	}
	void operator--(int) {
		licz--;
	}
};

template <typename T>
class sha_ptr {
	licznik* liczba = nullptr;
	T* wskaznik = nullptr;

public:
	sha_ptr(std::nullptr_t nullp) :liczba(nullptr), wskaznik(nullptr) {};
	sha_ptr() :liczba(new licznik(0)), wskaznik(nullptr) {};
	sha_ptr(T* nowy) :wskaznik(nowy), liczba(new licznik(1)) {};
	//sha_ptr(T nowy) :wskaznik(&nowy), liczba(new licznik(1)) {};
	sha_ptr(const T& i) :liczba(new licznik(1)), wskaznik(new T(i)) {};

	sha_ptr(const sha_ptr& shp) : wskaznik(shp.wskaznik) {
		if (wskaznik == nullptr) {
			wskaznik = nullptr;
			liczba = nullptr;
		}
		else if (shp.liczba != nullptr) {
			liczba = shp.liczba;
			(*liczba)++;
		}
		else
			liczba = new licznik(1);
	};

	sha_ptr(sha_ptr&& shp) : wskaznik(shp.wskaznik), liczba(shp.liczba) {
		if (wskaznik == nullptr) {
			wskaznik = nullptr;
			liczba = nullptr;
		}
		else {
			shp.liczba = nullptr;
			shp.wskaznik = nullptr;
		}
	};

	sha_ptr& operator=(const sha_ptr& shp) {
		if (this != &shp) {
			wyczysc();
			if (shp.wskaznik == nullptr) {
				wskaznik = nullptr;
				liczba = nullptr;
				return *this;
			}
			wskaznik = shp.wskaznik;
			if (shp.liczba != nullptr) {
				liczba = shp.liczba;
				(*liczba)++;
			}
			else
				liczba = new licznik(1);
		}
		return *this;
	};

	sha_ptr& operator=(sha_ptr&& shp) noexcept {
		wyczysc();
		if (shp.wskaznik == nullptr) {
			wskaznik = nullptr;
			liczba = nullptr;
			return *this;
		}
		wskaznik = shp.wskaznik, liczba = shp.liczba;
		shp.liczba = nullptr, shp.wskaznik = nullptr;
		return *this;
	};

	bool operator== (const sha_ptr& i1) { return i1.wskaznik == wskaznik; };
	bool operator!= (const sha_ptr& i1) { return i1.wskaznik != wskaznik; };

	//template <typename X>
	//sha_ptr& operator=(const std::weak_ptr<T>& shp) { wskaznik = shp.lock().get(); if (shp.use_count() != 0) shp._Incref(); liczba = shp.use_count(); };

	unsigned int get_count() const {
		return liczba->pobierz_wartosc();
	}

	T* get() const {
		return wskaznik;
	}

	T* operator->() const {
		return wskaznik;
	}

	T& operator*()  const {
		return *wskaznik;
	}

	/*std::weak_ptr<T> zwroc_weak() {
		std::shared_ptr<T> sw = std::make_shared<T>(wskaznik);
		return sw;
	}*/

	~sha_ptr() {
		wyczysc();
	}

	void wyczysc() {
		if (liczba != nullptr) {
			(*liczba)--;
			if (liczba->pobierz_wartosc() == 0) {
				if (wskaznik != nullptr) {
					delete wskaznik;
					wskaznik = nullptr;
				}
				delete liczba;
				liczba = nullptr;
			}
		}
	}
};

template <typename T>
sha_ptr<T> make_sha(const T* twsk) {
	return sha_ptr<T>(twsk);
}

template <typename T>
sha_ptr<T> make_sha(const int twsk) {
	return sha_ptr<T>(twsk);
}

sha_ptr<int> make_sha(const int twsk);
