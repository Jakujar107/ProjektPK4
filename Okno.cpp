#include "Okno.h"

using namespace std;


template<typename t>
okno<t>::okno(t H,t W)
{
	display = NULL;
	display = al_create_display(H, W);
	if (!display) {
		cout << "failed to initialize display!\n" << endl;
	}

}
template<typename t>
okno<t>::~okno()
{

}