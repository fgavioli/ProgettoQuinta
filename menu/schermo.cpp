#include "schermo.h"

struct recSchermata{
	ALLEGRO_DISPLAY *schermo = NULL;
	ALLEGRO_DISPLAY_MODE disp_data1;
};

recSchermata initrecSchermata(recSchermata test, int schermoX, int schermoY){
	test.schermo = al_create_display(schermoX, schermoY);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	return test;
}
void sudoku_schermo(recSchermata test){
	al_destroy_display(test.schermo);
}