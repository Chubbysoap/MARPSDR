/*
    Function definitons for button
*/

#include "define.h"

BUTTON *create_button(int x_pos, int y_pos, int width, int height)
{
    BUTTON *button = NULL;

    button = (BUTTON *)malloc(sizeof(BUTTON));

    if(button == NULL)
    {
        printf("\n***Failed to allocate memory for button***\n");
    }

    // Initialize values
    button->texture = NULL;
    button->button_selected = button_is_not_selected;
    button->rect.x = x_pos;
    button->rect.y = y_pos;
    button->rect.w = width;
    button->rect.h = height;

    return button;
}

void display_button(SDL_Renderer *renderer, BUTTON *button, char file_path[20])
{

    // SDL_Surface *surface = SDL_ConvertSurface(IMG_Load(file_path), )
    // SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    // SDL_RenderFillRect(renderer, &button->rect);

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
    free(button);

    button = NULL;
}