#ifndef mouse_h
#define mouse_h

#include "define.h"

#define mouse_button_pressed 1
#define mouse_button_not_pressed 0
#define mouse_scroll_up 1
#define mouse_scroll_down -1
#define mouse_scroll_none 0

typedef struct MOUSE
{
    int x_pos;
    int y_pos;
    int left_button_pressed;
    int middle_button_pressed;
    int right_button_pressed;
    int mouse_wheel_y;
} MOUSE;

MOUSE * create_mouse(void);
void update_mouse(MOUSE *mouse, SDL_Event event);
void destroy_mouse(MOUSE *mouse);

#endif