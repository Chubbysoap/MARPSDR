#ifndef textbox_h
#define textbox_h

#include "define.h"

// Buffer size defintions
#define MAX_TEXTBOX_BUFFER 256

// Definitions
#define TEXTBOX_IS_SELECTED 1
#define TEXTBOX_IS_NOT_SELECTED 0


typedef struct TEXTBOX
{
    TTF_Font *font;
    SDL_Rect textbox_rect;
    SDL_Rect prompt_rect;
    char text[MAX_TEXTBOX_BUFFER];
    char prompt[MAX_TEXTBOX_BUFFER];
    int textbox_selected;
} TEXTBOX;


typedef struct TEXTBOX_CONFIG
{
    char *font_path;
    char prompt[MAX_TEXTBOX_BUFFER];
    int font_size;
    int x_pos;
    int y_pos;
    int width;
    int height;
    float scale;
} TEXTBOX_CONFIG;


TEXTBOX *create_textbox(TEXTBOX_CONFIG *tb_config, float scale);
void display_textbox(SDL_Surface *screen, TEXTBOX *textbox);
void update_textbox(TEXTBOX *textbox, MOUSE *mouse, SDL_Event *event);
void destroy_textbox(TEXTBOX *textbox);
void config_textbox(TEXTBOX_CONFIG *tb_config[NUM_of_TEXTBOXES]);
void setup_textboxes(SDL_Window *window, SDL_Surface *screen[NUM_of_SCREENS], TEXTBOX *textbox[NUM_of_TEXTBOXES]);
void teardown_textboxes(TEXTBOX *textbox[NUM_of_TEXTBOXES]);



#endif