#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>

//Strutture utilizzate per ogni personaggio su schermo che descrivono posizionamento e caratteristiche principali personaggi.
struct recLocation
{
	int X;
	int Y;
};
struct recPersonaggio
{
	short MoveSpeed;
	short HealthPoints;
	ALLEGRO_BITMAP *Sprite;
	recLocation Location;
	bool Visible = false;
};
//funzione di inizializzazione per maggiore pulizia del codice.
recLocation initrecLocation(int X, int Y){
	recLocation r;
	r.X = X;
	r.Y = Y;
	return r;
}
recPersonaggio initrecPersonaggio(short MoveSpeed, short HealthPoints, ALLEGRO_BITMAP *Sprite, recLocation Location, bool isVisible){
	recPersonaggio r;
	r.MoveSpeed = MoveSpeed;
	r.HealthPoints = HealthPoints;
	r.Sprite = Sprite;
	r.Location = Location;
	r.Visible = isVisible;
	return r;
}
//funzione di movimento utilizzata per ogni personaggio su schermo: dato il personaggio da muovere e la posizione obiettivo vengono settate la x e la y dell'oggetto e richiamata la funzione reRender.
void move(recPersonaggio &target, int targetX, int targetY){
	target.Location.X = targetX;
	target.Location.Y = targetY;
}
//Funzione che cancella ogni oggetto su schermo e lo ridisegna se il parametro visible dell'oggetto stesso è true.
void reRender(recPersonaggio test){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(test.Sprite, test.Location.X, test.Location.Y, 0);
	al_flip_display();
}

//Dichiarazione di variabili "ambientali" necessarie come base per la visualizzazione, quindi globali.
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_DISPLAY_MODE disp_data;
ALLEGRO_BITMAP *sfondo = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

const float FPS = 60;

int main(int argc, char **argv){
	//Dichiarazione variabili personaggi.
	recPersonaggio test;
	
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	timer = al_create_timer(1.0 / FPS);

	test = initrecPersonaggio(10, 10, al_load_bitmap("1.PNG"), initrecLocation(10, 10), true);

	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(1366, 768);

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(test.Sprite, test.Location.X, test.Location.Y, NULL);
	al_flip_display();
	
	//al_start_timer(timer);
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				test.Location.Y -= test.MoveSpeed;
				reRender(test);
				break;

			case ALLEGRO_KEY_S:
				test.Location.Y += test.MoveSpeed;
				reRender(test);
				break;

			case ALLEGRO_KEY_A:
				test.Location.X -= test.MoveSpeed;
				reRender(test);
				break;

			case ALLEGRO_KEY_D:
				test.Location.X += test.MoveSpeed;
				reRender(test);
				break;
			}
		}

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			reRender(test);
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	
	return 0;
}