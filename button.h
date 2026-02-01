#ifndef button_h
#define button_h

#include "define.h"
#include "mouse.h"

#define button_is_selected 1
#define button_is_not_selected 0

typedef struct BUTTON
{
    SDL_Texture *texture;
    SDL_Rect rect;
    int button_selected;
} BUTTON;

BUTTON *create_button(int x_pos, int y_pos, int width, int height);
void display_button(SDL_Renderer *renderer, BUTTON *button, char file_path[20]);
void update_button(BUTTON *button, MOUSE *mouse);
void destroy_button(BUTTON *button);


#endif