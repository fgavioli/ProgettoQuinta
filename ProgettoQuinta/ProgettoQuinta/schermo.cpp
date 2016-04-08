#include "schermo.h"
#include "init.h"

recSchermata initrecSchermata(recSchermata sch, int schermoX, int schermoY){
	sch.schermo = al_create_display(schermoX, schermoY);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	return sch;
}
void sudoku_schermo(recSchermata sch){
	al_destroy_display(sch.schermo);
}