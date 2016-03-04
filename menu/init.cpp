#include "init.h"

void initBase(){
	al_init();
	al_inhibit_screensaver(true);
}

void initImg(){
	al_init_image_addon();
}

void initAudio(){
	al_init_acodec_addon();
}
