#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_color.h>
#include <allegro5\events.h>
#include "fmov.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


bool key_buffer[] { NULL, NULL, NULL, NULL };

//funzioni di inizializzazione per maggiore pulizia del codice.
recPersonaggio initrecPersonaggio(short MoveSpeed, short HealthPoints, ALLEGRO_BITMAP *Sprite, recLocation Location, bool isVisible){
	recPersonaggio r;
	r.MoveSpeed = MoveSpeed;
	r.HealthPoints = HealthPoints;
	r.Sprite = Sprite;
	r.Location = Location;
	r.Visible = isVisible;
	return r;
}
recLocation initrecLocation(int x, int y){
	recLocation r;
	r.X = x;
	r.Y = y;
	return r;
}
//funzione di movimento utilizzata per ogni personaggio su schermo: dato il personaggio da muovere e la posizione obiettivo vengono settate la x e la y dell'oggetto e richiamata la funzione reRender.
void move(recPersonaggio &target, int targetX, int targetY){
	target.Location.X = targetX;
	target.Location.Y = targetY;
}

//Funzione che cancella ogni oggetto su schermo e lo ridisegna se il parametro visible dell'oggetto stesso è true.
void reRender(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(sfondo, 0, 0, 0);

}

//Dichiarazione di variabili "ambientali" necessarie come base per la visualizzazione, quindi globali.
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *sfondo = NULL;
recPersonaggio target;
bool redraw = false;
void movCycle(){
	target = initrecPersonaggio(10, 10, al_load_bitmap("sprite.png"), initrecLocation(100, 100), true);
	ALLEGRO_EVENT_QUEUE *coda;
	ALLEGRO_TIMER* timer;
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(coda, al_get_timer_event_source(timer));
	al_register_event_source(coda, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!false)
	{
		ALLEGRO_EVENT e;
		al_wait_for_event(coda, &e);
		if (e.type == ALLEGRO_EVENT_TIMER)
			redraw = player_action();
		else if (e.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				key_buffer[UP] = true;
				break;

			case ALLEGRO_KEY_S:
				key_buffer[DOWN] = true;
				break;

			case ALLEGRO_KEY_A:
				key_buffer[LEFT] = true;
				break;

			case ALLEGRO_KEY_D:
				key_buffer[RIGHT] = true;
				break;
			}
		}

		else if (e.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				key_buffer[UP] = false;
				break;

			case ALLEGRO_KEY_S:
				key_buffer[DOWN] = false;
				break;

			case ALLEGRO_KEY_A:
				key_buffer[LEFT] = false;
				break;

			case ALLEGRO_KEY_D:
				key_buffer[RIGHT] = false;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(coda))
			reRender();
	}
}

bool player_action() {
	bool redr = false;
	if (key_buffer[UP])
	{
		target.Location.Y -= target.MoveSpeed;
		redr = true;
	}
	if (key_buffer[DOWN])
	{
		target.Location.Y += target.MoveSpeed;
		redr = true;
	}
	if (key_buffer[LEFT])
	{
		target.Location.X -= target.MoveSpeed;
		redr = true;
	}
	if (key_buffer[RIGHT])
	{
		target.Location.X += target.MoveSpeed;
		redr = true;
	}
	return redr
}