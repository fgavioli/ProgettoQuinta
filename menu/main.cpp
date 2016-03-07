#include "schermo.h"
#include "init.h"

recSchermata display;
void main(void){
	initBase();
	initImg();
	initAudio();
	initKeyboard();
	initrecSchermata(display, 1366, 768);
	
	sudoku_schermo(display);
}