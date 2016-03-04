#include <allegro5\allegro.h>

struct recSchermata {
	ALLEGRO_DISPLAY *schermo = NULL;
	ALLEGRO_DISPLAY_MODE disp_data1;
};

recSchermata initrecSchermata(recSchermata test, int schermoX, int schermoY);
void sudoku_finale(recSchermata test);