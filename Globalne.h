#pragma once
#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>                       
#include <allegro5/allegro_image.h> // plik nag��wkowy
#include <allegro5/allegro_native_dialog.h> // plik nag��wkowy do funkcji sprawdzaj�cej wczytanie bitmapy.
#include <cmath>
#include <typeinfo>
#include <regex>


const float FPS = 10; // czestotliwosc od�wie�ania ekranu
const int SCREEN_W = 1344; // wielkosc wy�wietlacza
const int SCREEN_H = 960;
const int SIZE = 64;//rozmiar jednej kratki
const int bomberman_SIZE = 32;//rozmiar bombermana


enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, bomb
};

struct wspgracza {
	float x; // wsp�rzedne gracza gdzie zaczyna gra�
	float y;
	float bomba_x; // wsp�rz�dne bomby
	float bomba_y;
	float bomba2_x;
	float bomba2_y;
	float flame_x, flame2_x, flame2_y, flame_y; // wsp�rz�dne p�omienia

	ALLEGRO_EVENT ev;
	
	
		




};


