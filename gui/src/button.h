#ifndef button_h
#define button_h

#include "define.h"
#include "mouse.h"

#define button_is_selected 1
#define button_is_not_selected 0

typedef struct BUTTON
{
    SDL_Surface *surface;
    SDL_Rect rect;
    int button_selected;
} BUTTON;

BUTTON *create_button(SDL_Surface *screen, char *file_path, int x_pos, int y_pos);
void display_button(SDL_Surface *surface, BUTTON *button);
void update_button(BUTTON *button, MOUSE *mouse);
void destroy_button(BUTTON *button);


#endif