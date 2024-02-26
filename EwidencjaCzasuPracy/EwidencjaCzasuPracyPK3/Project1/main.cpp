#include "menu.h"

const bool LOG = 1; // sta³a decyduj¹ca, czy bêd¹ tworzone logi

int main() {
	do {
		if (menu::utworz_menu(LOG).wyswietl_menu()); // wyœwietlanie i obs³uga menu
		else return 0;
	} while (true);
	return 0;
}