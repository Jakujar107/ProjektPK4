#include "plansza.h"
#include "Okno.h"
#include "Postacie.h"

 
using namespace std;

plansza::plansza()

{

	
	
}


void plansza::test(ALLEGRO_DISPLAY* display)
{
	try
	{
		std::cout << "Proba pierwsza\n";
		check(display);
		std::cout << "Proba druga\n";
		check(display);
	}

	catch (int)
	{
		std::cout << "Mowilem, zebys nie rzucal int >:/\n";
		// Rzuæ nowy, inny wyj¹tek
		throw std::logic_error("Nieoczekiwany int");
	}

}



void plansza::check(ALLEGRO_DISPLAY* display) {
	//sprawdzanie czy wszystkie elementu zosta³y dobrze zainicjalizowane 
	//timer

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		throw 1;
	}

	//wyswietlacz
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		throw 1;
	}

	//podloga
	if (!Background) {
		fprintf(stderr, "failed to create Background bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		throw 1;
	}
	//sciana
	if (!Wall) {
		fprintf(stderr, "failed to create wall bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		throw 1;
	}
	//kolejka wydarzen
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(Background);
		al_destroy_display(display);
		al_destroy_timer(timer);
		throw 1;
	}
	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		throw 1;
	}
}
void plansza::logika() {
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();

	boom = al_create_timer(1.0); // ustawianie czêstotliwoœci inkremenotwania stoperów
	boom2 = al_create_timer(1.0); //1 s
	flamer = al_create_timer(1.0 / 2);// 0.5s
	flamer2 = al_create_timer(1.0 / 2);
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		cout<<"no way";
	}


	okno<int> okienko(SCREEN_W, SCREEN_H);
	okienko.display;
	Background = al_load_bitmap("BackgroundTile.png");
	krata = al_load_bitmap("krata.png");
	Wall = al_load_bitmap("SolidBlock.png"); // przypisanie bitmapy œciany

	// powrót na wyœwietlacz
	al_set_target_bitmap(al_get_backbuffer(okienko.display));
	// tworzenie kolejki wydarzeñ
	event_queue = al_create_event_queue();

	// rejestrowanie wydarzeñ

	al_register_event_source(event_queue, al_get_display_event_source(okienko.display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	
	
	// wystartowanie timere czyli czêstotliwoœci odœwie¿ania
	al_start_timer(timer);

	// g³owna pêtla programu która jak zostanie przerwana to koñczy sie program
	Postacie gracz1;
	Postacie gracz2;
	try
	{
		test(okienko.display);
	}
	catch (std::logic_error & e)
	{
		std::cout << "nie udalo sie utworzyc jakiegos elementu: " << e.what() << '\n';
		
	}

	while (1)
	{
		al_wait_for_event(event_queue, &ev);
		

		
		// przerywanie pêtli jak nie uda³o siê czegoœ zainicjalizowaæ
		//jezeli nie udalo sie czegos stworzyc konczy program


		// gdy naciœniemy X na wyœwietlaczy koñczymy program
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (typeid(player1).name()) 
			player1 = gracz1.poruszanie1(timer, boom, boom2, flamer, flamer2, ev, player1, tab);
			ev = player1.ev;
			if (typeid(player2).name())

			player2 = gracz2.poruszanie2(timer, boom, boom2, flamer, flamer2, ev, player2, tab);
			ev = player2.ev;
		
		

		if (player1.ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (player1.ev.keyboard.keycode) {
			case ALLEGRO_KEY_LCTRL:
				// wciœniêcie LCTRL zadzia³a tylko je¿eli bomba ju¿ wybuch³a. W³¹czenie timera wysadzania bomby i ustawi wspó³rzêdne bomby równe graczowi
				if (al_get_timer_count(boom) == 0) {
					player1.bomba_x = player1.x;
					player1.bomba_y = player1.y + 64;
					al_start_timer(boom);
				}
				break;
			case ALLEGRO_KEY_RCTRL:
				// wciœniêcie LCTRL zadzia³a tylko je¿eli bomba ju¿ wybuch³a. W³¹czenie timera wysadzania bomby i ustawi wspó³rzêdne bomby równe graczowi
				if (al_get_timer_count(boom2) == 0) {
					player2.bomba2_x = player2.x;
					player2.bomba2_y = player2.y + 64;
					al_start_timer(boom2);
				}
				break;
			}
		}
		// gdy timer wysadznie bomby bedzie równy 3 zerujemy timer i zamiast tworzymy p³omienie
		if (al_get_timer_count(boom) == 3) {
			al_stop_timer(boom);
			al_set_timer_count(boom, 0);
			player1.flame_x = player1.bomba_x;
			player1.flame_y = player1.bomba_y;
			int fx = player1.flame_x / 64;
			int fy = player1.flame_y / 64;
			if (tab[fy-1][fx] == 1) {
				tab[fy-1][fx] = 0;
			}
			if (tab[fy ][fx + 1] == 1) {
				tab[fy ][fx + 1] = 0;
			}
			if (tab[fy ][fx - 1] == 1) {
				tab[fy ][fx - 1] = 0;
			}
			if (tab[fy + 1][fx] == 1) {
				tab[fy + 1][fx] = 0;
			}
			//ustawiamy bombe poza mapa
			player1.bomba_x = -128;
			player1.bomba_y = -128;
			al_start_timer(flamer);
		}
		//je¿eli timer p³omienia wynosi 1 to zatrzymujemy timer i zerujemy go a p³omienie ustawiamy poza mapa
		if (al_get_timer_count(flamer2) == 1) {
			al_stop_timer(flamer2);
			al_set_timer_count(flamer2, 0);
			player2.flame2_x = -500;
			player2.flame2_y = -500;
		}
		if (al_get_timer_count(boom2) == 3) {
			al_stop_timer(boom2);
			al_set_timer_count(boom2, 0);
			player2.flame2_x = player2.bomba2_x;
			player2.flame2_y = player2.bomba2_y;
			int fx = player2.flame2_x / 64;
			int fy = player2.flame2_y / 64;
			if (tab[fy-1][fx] == 1) {
				tab[fy-1][fx] = 0;
			}
			if (tab[fy ][fx + 1] == 1) {
				tab[fy ][fx + 1] = 0;
			}
			if (tab[fy ][fx - 1] == 1) {
				tab[fy ][fx - 1] = 0;
			}
			if (tab[fy + 1][fx] == 1) {
				tab[fy + 1][fx] = 0;
			}
			//ustawiamy bombe poza mapa
			player2.bomba2_x = -128;
			player2.bomba2_y = -128;
			al_start_timer(flamer2);
		}
		//je¿eli timer p³omienia wynosi 1 to zatrzymujemy timer i zerujemy go a p³omienie ustawiamy poza mapa
		if (al_get_timer_count(flamer) == 1) {
			al_stop_timer(flamer);
			al_set_timer_count(flamer, 0);
			player1.flame_x = -500;
			player1.flame_y = -500;
		}

				al_clear_to_color(al_map_rgb(0, 0, 0));


				tworzmape();// tworzenie planszy na danych z tablicy

				gracz1.rysuj(player1);
				gracz2.rysuj(player2);
				
				if (gracz1.kolizjazgraczem(okienko.display, player1.x, player1.y, player1.flame_x, player1.flame_y, player2.x, player2.y, player2.flame2_x, player2.flame2_y)) {
					break;
				}

				al_flip_display();
			

		}// usuwanie wszystkiego z pamiêci
		al_destroy_bitmap(Background);
		al_destroy_bitmap(Wall);
		al_destroy_timer(timer);
		al_destroy_display(okienko.display);
		al_destroy_event_queue(event_queue);
	}





void plansza::tworzmape() {
	int type;
	
	for (int y = 0; y < 15; y++) {

		for (int x = 0; x < 21; x++) {
			type = tab[y][x];
			if (type == 1) {
			/*	int liczba = (std::rand() % 3 + 10);

				if (liczba == 12) {
					al_draw_bitmap(Background, x * 64, y * 64, 0);
				} // podloga
				if (liczba == 10 || liczba == 11) {
				*/	al_draw_bitmap(krata, x * 64, y * 64, 0);
				} // podloga
			
			if (type == 0) {
				al_draw_bitmap(Background, x * 64, y * 64, 0);
			} // podloga


			if (type == 2) {
				al_draw_bitmap(Wall, x * 64, y * 64, 0); //sciana
			}
		}
	}
}


plansza::~plansza()
{

	


}
