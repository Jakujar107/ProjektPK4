
#include "Globalne.h"
#include "Okno.h"
#include "plansza.h"




int main()
{

	regex r1("[[:alpha:]|[:digit:]]*@[[:alpha:]|[:digit:]]*[.](com|pl)");
	string email;
	cout << "podaj maila zeby rozpoczac\n";
		cin >>  email;
		if (regex_match(email, r1) == 1) {
			if (!al_init()) {
				fprintf(stderr, "failed to initialize allegro!\n");

			}

			plansza p1;
			p1.logika();

		}
		else
			cout << "niepoprawny email\n";
	
		system("pause");
	return 0;
}