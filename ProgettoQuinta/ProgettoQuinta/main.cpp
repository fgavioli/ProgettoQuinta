#include "schermo.h"
#include "fmov.h"
#include "init.h"

recSchermata display;
void main(void){
	initBase();
	initImg();
	initAudio();
	initKeyboard();
	initrecSchermata(display, 1366, 768);
	movCycle();
	sudoku_schermo(display);
}