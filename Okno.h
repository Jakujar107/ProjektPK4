
#pragma once
#include "Globalne.h"


using namespace std;
template<typename t>
class okno
{
	t H;
	t W;


public:
	ALLEGRO_DISPLAY *display;
	okno(t H,t W);
	~okno();
};