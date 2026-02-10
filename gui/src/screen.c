/*
    Fuction definitions for setting up and displaying certain screens
*/

#include "define.h"


void display_main_screen(SDL_Surface *screen, BUTTON *button)
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    display_button(screen, button);

    return;
}

void display_FM_screen(SDL_Surface *screen, BUTTON *button)
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 255));
    display_button(screen, button);

    return;
}