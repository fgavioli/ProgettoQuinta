#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
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
	al_install_audio();
}

void initKeyboard(){
	al_install_keyboard();
}

