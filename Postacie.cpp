#include "Postacie.h"




Postacie::Postacie()
{
	bomberman = al_load_bitmap("Bman_F_f00.png");
	bomba = al_load_bitmap("bomba.png");
	bomba2 = al_load_bitmap("bomba2.png");
	flame = al_load_bitmap("flame.png");
	flame2 = flame;

}


Postacie::~Postacie()
{
}
void Postacie::rysuj(struct wspgracza player) {

	al_draw_bitmap(bomberman,player.x,player.y, 0);
	al_draw_bitmap(bomba, player.bomba_x, player.bomba_y, 0);
	al_draw_bitmap(bomba2, player.bomba2_x, player.bomba2_y, 0);
	al_draw_bitmap(flame, player.flame_x, player.flame_y, 0);
	al_draw_bitmap(flame, player.flame_x, player.flame_y - 64, 0);
	al_draw_bitmap(flame, player.flame_x, player.flame_y + 64, 0);
	al_draw_bitmap(flame, player.flame_x - 64, player.flame_y , 0);
	al_draw_bitmap(flame, player.flame_x + 64, player.flame_y , 0);
	al_draw_bitmap(flame, player.flame2_x, player.flame2_y, 0);
	al_draw_bitmap(flame, player.flame2_x, player.flame2_y - 64, 0);
	al_draw_bitmap(flame, player.flame2_x, player.flame2_y + 64, 0);
	al_draw_bitmap(flame, player.flame2_x - 64, player.flame2_y, 0);
	al_draw_bitmap(flame, player.flame2_x + 64, player.flame2_y, 0);




}
wspgracza Postacie::poruszanie1(ALLEGRO_TIMER *timer,ALLEGRO_TIMER *boom,ALLEGRO_TIMER *boom2,ALLEGRO_TIMER *flamer, ALLEGRO_TIMER *flamer2,ALLEGRO_EVENT ev,struct wspgracza player1, int tab[15][21]) {
	player1.ev = ev;
	


	if (player1.ev.type == ALLEGRO_EVENT_TIMER) {
		int y = (player1.y) / 64; //dzielimy przez 64 zeby zgadzalo sie z polem w tablicy
		int x = (player1.x) / 64;
	


		// wszystkie za³o¿enia które musz¹ zostaæ spe³nione, ¿eby mo¿na by³o ruszyæ graczem.
		if (key[KEY_UP] && player1.y >= 64.0 && tab[y][x] != 1 && tab[y][x] != 2) {
			player1.y -= 64.0;
			return player1;
		}
		if (key[KEY_DOWN] && player1.y <= SCREEN_H - 128 - 2 * bomberman_SIZE - 64.0 && tab[y + 2][x] != 1 && tab[y + 2][x] != 2) {
			player1.y += 64.0;
			return player1;

		}

		if (key[KEY_LEFT] && player1.x >= 128.0 && tab[y + 1][x - 1] != 1 && tab[y + 1][x - 1] != 2) {
			player1.x -= 64.0;
			return player1;

		}

		if (key[KEY_RIGHT] && player1.x <= SCREEN_W - 64 - 2 * bomberman_SIZE - 64.0 && tab[y + 1][x + 1] != 1 && tab[y + 1][x + 1] != 2) {
			player1.x += 64.0;
			return player1;

		}

		

	}
	// je¿eli dany klawisz jest wciœniêty to zamienia na czas wciœniêcia key z false na true i mo¿e zostaæ wykonane przesuniêcie gracza
	else if (player1.ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (player1.ev.keyboard.keycode) {
		case ALLEGRO_KEY_W:
			key[KEY_UP] = true;
			break;

		case ALLEGRO_KEY_S:
			key[KEY_DOWN] = true;
			break;

		case ALLEGRO_KEY_A:
			key[KEY_LEFT] = true;
			break;

		case ALLEGRO_KEY_D:
			key[KEY_RIGHT] = true;
			break;
		
	}
		
	}
	//podniesienie klawisza zmieni zmieni zmienne key na false i dziêki temu gracz nie bêdzie siê móg³ dalej przesuwaæ
	else if (player1.ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch (player1.ev.keyboard.keycode) {
		case ALLEGRO_KEY_W:
			key[KEY_UP] = false;
			break;

		case ALLEGRO_KEY_S:
			key[KEY_DOWN] = false;
			break;

		case ALLEGRO_KEY_A:
			key[KEY_LEFT] = false;
			break;

		case ALLEGRO_KEY_D:
			key[KEY_RIGHT] = false;
			break;
	

		}

	}


	return player1;
}

wspgracza Postacie::poruszanie2(ALLEGRO_TIMER *timer, ALLEGRO_TIMER *boom, ALLEGRO_TIMER *boom2, ALLEGRO_TIMER *flamer, ALLEGRO_TIMER *flamer2,ALLEGRO_EVENT ev, struct wspgracza player2, int tab[15][21]){


		player2.ev = ev;
		if (player2.ev.type == ALLEGRO_EVENT_TIMER) {

		int y2 = ((player2.y) / 64 + 1);
		int x2 = (player2.x) / 64;

		if (key2[KEY_UP] && player2.y >= 64.0 && tab[y2 - 1][x2] != 1 && tab[y2 - 1][x2] != 2) {
			player2.y -= 64.0;
			return player2;

		}

		if (key2[KEY_DOWN] && player2.y <= SCREEN_H - 64 - 2 * bomberman_SIZE - 64.0&&tab[y2 + 1][x2] != 1 && tab[y2 + 1][x2] != 2) {
			player2.y += 64.0;
			return player2;

		}

		if (key2[KEY_LEFT] && player2.x >= 128.0&&tab[y2][x2 - 1] != 1 && tab[y2][x2 - 1] != 2) {
			player2.x -= 64.0;
		}

		if (key2[KEY_RIGHT] && player2.x <= SCREEN_W - 64 - 2 * bomberman_SIZE - 64.0&&tab[y2][x2 + 1] != 1 && tab[y2][x2 + 1] != 2) {
			player2.x += 64.0;
			return player2;


		}


	}
	else if (player2.ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (player2.ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			key2[KEY_UP] = true;
			break;

		case ALLEGRO_KEY_DOWN:
			key2[KEY_DOWN] = true;
			break;

		case ALLEGRO_KEY_LEFT:
			key2[KEY_LEFT] = true;
			break;

		case ALLEGRO_KEY_RIGHT:
			key2[KEY_RIGHT] = true;
			break;
		

		}
	}
	else if (player2.ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch (player2.ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			key2[KEY_UP] = false;
			break;

		case ALLEGRO_KEY_DOWN:
			key2[KEY_DOWN] = false;
			break;

		case ALLEGRO_KEY_LEFT:
			key2[KEY_LEFT] = false;
			break;

		case ALLEGRO_KEY_RIGHT:
			key2[KEY_RIGHT] = false;

			break;
			//zwolnienie klawisza esc spowoduje zakoñczenie pêtli
		case ALLEGRO_KEY_ESCAPE:
			break;
		}
	}

	return player2;
}




bool Postacie::kolizjazgraczem(ALLEGRO_DISPLAY *display,float bomberman_x, float bomberman_y, float flame_x, float flame_y, float bomberman2_x, float bomberman2_y, float flame2_x, float flame2_y)
{
	bomberman_y = bomberman_y + 64;
	bomberman2_y = bomberman2_y +128;

	if ((bomberman_x == flame_x && bomberman_y == flame_y) || (bomberman_x == flame_x && bomberman_y == flame_y + 64) || (bomberman_x == flame_x && bomberman_y == flame_y - 64)
		|| (bomberman_x == flame_x - 64 && bomberman_y == flame_y) || (bomberman_x == flame_x + 64 && bomberman_y == flame_y)) {
		al_show_native_message_box(display, "koniec", "wygral", "gracz 1",
			NULL, ALLEGRO_MESSAGEBOX_WARN);
		return true;
	
	}
	if ((bomberman2_x == flame_x && bomberman2_y == flame_y) || (bomberman2_x == flame_x && bomberman2_y == flame_y + 64) || (bomberman2_x == flame_x && bomberman2_y == flame_y + 128)
		|| (bomberman2_x == flame_x - 64 && bomberman2_y == flame_y + 64) || (bomberman2_x == flame_x + 64 && bomberman2_y == flame_y + 64)) {
		al_show_native_message_box(display, "koniec", "wygral", "gracz 2",
			NULL, ALLEGRO_MESSAGEBOX_WARN);
		
		return true;
	}
	if ((bomberman2_x == flame2_x && bomberman2_y == flame2_y) || (bomberman2_x == flame2_x && bomberman2_y == flame2_y + 64) || (bomberman2_x == flame2_x && bomberman2_y == flame2_y + 128)
		|| (bomberman2_x == flame2_x - 64 && bomberman2_y == flame2_y + 64) || (bomberman2_x == flame2_x + 64 && bomberman2_y == flame2_y + 64)) {
		al_show_native_message_box(display, "koniec", "wygral", "gracz 2",
			NULL, ALLEGRO_MESSAGEBOX_WARN);
		
		return true;
	}

	if ((bomberman_x == flame2_x && bomberman_y == flame2_y) || (bomberman_x == flame2_x && bomberman_y == flame2_y + 64) || (bomberman_x == flame2_x && bomberman_y == flame2_y - 64)
		|| (bomberman_x == flame2_x - 64 && bomberman_y == flame2_y) || (bomberman_x == flame2_x + 64 && bomberman_y == flame2_y)) {
		al_show_native_message_box(display, "koniec", "wygral", "gracz 1",
			NULL, ALLEGRO_MESSAGEBOX_WARN);
		
		return true;
	}
	return false;
}