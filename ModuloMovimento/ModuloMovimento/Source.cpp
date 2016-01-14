#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>
#include <thread>
#include <chrono>
using namespace std;

struct recPersonaggio{
	int X;
	int Y;
	int movespeed;
	ALLEGRO_BITMAP *frame1;
	ALLEGRO_BITMAP *frame2;
};

void muoviSu(recPersonaggio p)
{
	while (true)
	{
		p.Y -= p.movespeed;
	}
}
void muoviGiu(recPersonaggio p)
{
	while (true)
	{
		p.Y += p.movespeed;
	}
}
void muoviSx(recPersonaggio p)
{
	while (true)
	{
		p.X -= p.movespeed;
	}
}
void muoviDx(recPersonaggio p)
{
	while (true)
	{
		p.X += p.movespeed;
	}
}

ALLEGRO_DISPLAY *schermo;
int main(void){
	recPersonaggio s;
	ALLEGRO_EVENT_QUEUE *q = NULL;
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
	while (!esc)
	{
		ALLEGRO_EVENT a;
		ALLEGRO_TIMEOUT time;
		al_wait_for_event_until(q, &a, &time);
		if (a.keyboard.type == ALLEGRO_EVENT_KEY_DOWN)
			if (a.keyboard.keycode == VK_ESCAPE)
				esc = true;
			else if (a.keyboard.keycode == ALLEGRO_KEY_W)
				thread su(muoviSu, s);
			else if (a.keyboard.keycode == ALLEGRO_KEY_S)
				thread giu(muoviGiu, s);
			else if (a.keyboard.keycode == ALLEGRO_KEY_A)
				thread sx(muoviSx, s);
			else if (a.keyboard.keycode == ALLEGRO_KEY_D)
				thread dx(muoviDx, s);
			al_clear_to_color(al_map_rgb(127, 127, 127));
			al_draw_bitmap(s.frame1, s.X, s.Y, 0);
			al_flip_display();	
	}
	return 0;
}