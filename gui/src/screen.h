#ifndef screen_h
#define screen_h

#include "define.h"

void setup_screens(SDL_Window *window, SDL_Surface *screen[NUM_of_SCREENS]);
void display_main_screen(SDL_Surface *screen, BUTTON *button);
void display_FM_screen(SDL_Surface *screen, BUTTON *button);


#endif