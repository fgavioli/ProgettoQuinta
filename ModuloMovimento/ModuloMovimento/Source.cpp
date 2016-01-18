#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>
#include <thread>
#include <iostream>
using namespace std;

struct recPersonaggio{
	int X;
	int Y;
	int movespeed;
	ALLEGRO_BITMAP *frame1;
	ALLEGRO_BITMAP *frame2;
};

void moveD(char direction, recPersonaggio s){
	if (direction == 'u')
		s.Y -= s.movespeed;
	if (direction == 'd')
		s.Y += s.movespeed;
	if (direction == 'l')
		s.X -= s.movespeed;
	if (direction == 'r')
		s.X += s.movespeed;
}

ALLEGRO_DISPLAY *schermo;
recPersonaggio s;
thread t[4];
int main(void){
	ALLEGRO_EVENT_QUEUE *q = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool esc = false;

	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	al_create_display(800, 600);
	q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	s.X = 10;
	s.Y = 10;
	s.movespeed = 5;
	s.frame1 = al_load_bitmap("1.png");
	s.frame2 = al_load_bitmap("2.png");

	al_clear_to_color(al_map_rgb(127, 127, 127));
	al_draw_bitmap(s.frame1, s.X, s.Y, NULL);
	al_flip_display();
	int k = 0;
	while (!esc)
	{
		ALLEGRO_EVENT EV;
		al_wait_for_event(q, &EV);
		if (EV.keyboard.type == ALLEGRO_EVENT_KEY_DOWN)
			if (EV.keyboard.keycode == VK_ESCAPE)
				esc = true;
			else if (EV.keyboard.keycode == ALLEGRO_KEY_W){
				t[0] = thread(moveD, 'u', s);
				k = 0;
			}
			else if (EV.keyboard.keycode == ALLEGRO_KEY_S){
				t[1] = thread(moveD, 'd', s);
				k = 1;
			}
			else if (EV.keyboard.keycode == ALLEGRO_KEY_A){
				t[2] = thread(moveD, 'l', s);
				k = 2;
			}
			else if (EV.keyboard.keycode == ALLEGRO_KEY_D){
				t[3] = thread(moveD, 'r', s);
				k = 3;
			}
			al_clear_to_color(al_map_rgb(127, 127, 127));
			al_draw_bitmap(s.frame1, s.X, s.Y, 0);
			al_flip_display();
			t[k].detach();
			t[k].join();
	}
	return 0;
}