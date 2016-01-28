#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_font.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define MAX_CHARACTERS 50



//Strutture utilizzate per ogni personaggio su schermo che descrivono posizionamento e caratteristiche principali personaggi.
struct recLocation
{
	int X;
	int Y;
};
struct recPersonaggio
{
	char *name;
	short MoveSpeed;
	short HealthPoints;
	ALLEGRO_BITMAP *Sprite;
	recLocation Location;
	bool Visible = false;
};
//funzioni di inizializzazione per maggiore pulizia del codice.
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


//Dichiarazione di variabili "ambientali" necessarie come base per la visualizzazione, quindi globali.
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *sfondo = NULL;
ALLEGRO_EVENT_QUEUE *coda = NULL;
ALLEGRO_TIMER *timer = NULL;
int buffer[4] = { NULL, NULL, NULL, NULL };

recPersonaggio personaggi[MAX_CHARACTERS];
int npg;

const float FPS = 60;


//funzione di movimento utilizzata per ogni personaggio su schermo.
void move(recPersonaggio &target, int targetX, int targetY){
	target.Location.X = targetX;
	target.Location.Y = targetY;
}

//Procedura che cancella ogni oggetto su schermo e lo ridisegna se il parametro visible dell'oggetto stesso è true.
void reRender(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (short i = 0; i < npg; i++)
		if (personaggi[i].Visible)
			al_draw_bitmap(personaggi[i].Sprite, personaggi[i].Location.X, personaggi[i].Location.Y, 0);
	al_flip_display();
}

//Procedure per inizializzare variabili di evento e addons allegro.
void initAddons(){
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
}

int main(int argc, char **argv){
	initAddons();
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(1366, 768);
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	coda = al_create_event_queue();
	al_register_event_source(coda, al_get_display_event_source(display));
	al_register_event_source(coda, al_get_timer_event_source(timer));
	al_register_event_source(coda, al_get_keyboard_event_source());
	srand(time(NULL));

	personaggi[0] = initrecPersonaggio(10, 10, al_load_bitmap("1.PNG"), initrecLocation(10, 10), true);
	npg++;
	personaggi[1] = initrecPersonaggio(10, 10, al_load_bitmap("1.PNG"), initrecLocation(300, 300), true);
	npg++;
	al_start_timer(timer);
	bool redraw = false;
	int sasso = 0;
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(coda, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (buffer[UP]) {
				personaggi[0].Location.Y -= personaggi[0].MoveSpeed;
			}

			if (buffer[DOWN]) {
				personaggi[0].Location.Y += personaggi[0].MoveSpeed;
			}

			if (buffer[LEFT]) {
				personaggi[0].Location.X -= personaggi[0].MoveSpeed;
			}

			if (buffer[RIGHT]) {
				personaggi[0].Location.X += personaggi[0].MoveSpeed;
			}
			int movement = rand() % 10;
			sasso++;
			if (sasso == 30)
			{
				if (movement == 0)
					personaggi[1].Location.X += personaggi[1].MoveSpeed;
				else if (movement == 1)
					personaggi[1].Location.X -= personaggi[1].MoveSpeed;
				else if (movement == 2)
					personaggi[1].Location.Y += personaggi[1].MoveSpeed;
				else if (movement == 3)
					personaggi[1].Location.Y -= personaggi[1].MoveSpeed;
				else if (movement == 4)
				{
					personaggi[1].Location.X += personaggi[1].MoveSpeed;
					personaggi[1].Location.Y += personaggi[1].MoveSpeed;
				}
				else if (movement == 5)
				{
					personaggi[1].Location.X += personaggi[1].MoveSpeed;
					personaggi[1].Location.Y -= personaggi[1].MoveSpeed;
				}
				else if (movement == 6)
				{
					personaggi[1].Location.X -= personaggi[1].MoveSpeed;
					personaggi[1].Location.Y += personaggi[1].MoveSpeed;
				}
				else if (movement == 7)
				{
					personaggi[1].Location.X -= personaggi[1].MoveSpeed;
					personaggi[1].Location.Y -= personaggi[1].MoveSpeed;
				}
				sasso = 0;
			}
			redraw = true;
		}else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_W:
				buffer[UP] = true;
				break;
				 
			case ALLEGRO_KEY_S:
				buffer[DOWN] = true;
				break;

			case ALLEGRO_KEY_A:
				buffer[LEFT] = true;
				break;

			case ALLEGRO_KEY_D:
				buffer[RIGHT] = true;
				break;
			}
		}else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_W:
				buffer[UP] = false;
				break;

			case ALLEGRO_KEY_S:
				buffer[DOWN] = false;
				break;

			case ALLEGRO_KEY_A:
				buffer[LEFT] = false;
				break;

			case ALLEGRO_KEY_D:
				buffer[RIGHT] = false;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(coda)) {
			redraw = false;
			reRender();
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(coda);
	
	return 0;
}