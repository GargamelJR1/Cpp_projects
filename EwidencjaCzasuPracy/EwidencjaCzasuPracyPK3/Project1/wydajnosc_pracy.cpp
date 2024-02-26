#include "wydajnosc_pracy.h"

void wydajnosc_pracy::oblicz_wydajnosc(){
 if (wymagana_ilosc_czynnosci != 0)
	 wydajnosc_wyliczona = ((double)ilosc_wykonanej_czynnosci / (double)wymagana_ilosc_czynnosci) * 100;
 else
	 wydajnosc_wyliczona = 100;
}

