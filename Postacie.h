#pragma once

#include "plansza.h"
#include "Globalne.h"

class Postacie
{
	
	
	bool key[5] = { false, false, false, false }; // zmienna która mówi czy gracz bêdzie sie rusza³
	bool key2[5] = { false, false, false, false };

public:
	ALLEGRO_BITMAP *bomberman = NULL;

	ALLEGRO_BITMAP *bomba = NULL;
	ALLEGRO_BITMAP *bomba2 = NULL;
	ALLEGRO_BITMAP *flame = NULL;
	ALLEGRO_BITMAP *flame2 = NULL;


	
	void rysuj(struct wspgracza player);
	Postacie();
	~Postacie();
	
	wspgracza poruszanie1(ALLEGRO_TIMER *timer, ALLEGRO_TIMER *boom, ALLEGRO_TIMER *boom2, ALLEGRO_TIMER *flamer, ALLEGRO_TIMER *flamer2, ALLEGRO_EVENT ev, struct wspgracza player1, int tab[15][21]);
	wspgracza poruszanie2(ALLEGRO_TIMER *timer, ALLEGRO_TIMER *boom, ALLEGRO_TIMER *boom2, ALLEGRO_TIMER *flamer, ALLEGRO_TIMER *flamer2, ALLEGRO_EVENT ev, struct wspgracza player2, int tab[15][21]);
	
	bool kolizjazgraczem(ALLEGRO_DISPLAY *display, float bomberman_x, float bomberman_y, float flame_x, float flame_y, float bomberman2_x, float bomberman2_y, float flame2_x, float flame2_y);


};

