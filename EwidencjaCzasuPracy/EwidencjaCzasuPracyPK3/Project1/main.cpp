#include "menu.h"

const bool LOG = 1; // sta�a decyduj�ca, czy b�d� tworzone logi

int main() {
	do {
		if (menu::utworz_menu(LOG).wyswietl_menu()); // wy�wietlanie i obs�uga menu
		else return 0;
	} while (true);
	return 0;
}