/*
    Function definitons for button
*/

#include "define.h"

BUTTON *create_button(SDL_Surface *screen, char file_path[20], int x_pos, int y_pos)
{
    BUTTON *button = NULL;

    button = (BUTTON *)malloc(sizeof(BUTTON));

    if(button == NULL)
    {
        printf("\n***Failed to allocate memory for button***\n");
    }

    // Setup surface texture for button
    SDL_Surface * surface_temp = IMG_Load(file_path);
    button->surface = SDL_ConvertSurface(surface_temp, screen->format, 0);
    SDL_FreeSurface(surface_temp);

    // Initialize values
    button->button_selected = button_is_not_selected;
    button->rect.x = x_pos;
    button->rect.y = y_pos;
    button->rect.w = button->surface->w;
    button->rect.h = button->surface->h;

    return button;
}

void display_button(SDL_Surface *screen, BUTTON *button)
{

    SDL_BlitSurface(button->surface, NULL, screen, &button->rect);

    return;
}

void update_button(BUTTON *button, MOUSE *mouse)
{
    if(mouse->x_pos > button->rect.x && mouse->x_pos < button->rect.x + button->rect.w
        && mouse->y_pos > button->rect.y && mouse->y_pos < button->rect.y + button->rect.h
        && mouse->left_button_pressed == mouse_button_pressed)
    {
        button->button_selected = button_is_selected;
        // printf("Button is pressed\n");
    }
    else
    {
        button->button_selected = button_is_not_selected;
    }
}


void destroy_button(BUTTON *button)
{

    if(button == NULL)
    {
        return;
    }

    if(button->surface)
    {
        SDL_FreeSurface(button->surface);
    }

    free(button);

    button = NULL;

    return;
}