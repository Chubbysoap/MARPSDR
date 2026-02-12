/*
    Function definitons for a button
*/

#include "define.h"


/*
Name: create_button
Description: Allocates memory for a struct for a button and initializes values with texture
Inputs: SDL_Surface *screen: Pointer to screen where the button will be displayed
        char *file_path: File path to the texture to be loaded
        int x_pos: X axis location for the top left of the button
        int y_pos: Y axis location for the top left of the button
Outputs: BUTTON structure pointer
*/
BUTTON *create_button(SDL_Surface *screen, char *file_path, int x_pos, int y_pos, float scale)
{
    BUTTON *button = NULL;
    SDL_Surface * surface_temp = NULL;
    SDL_Surface * surface_opt = NULL;
    int scaled_w = 0;
    int scaled_h = 0;
    int scaled_x = 0;
    int scaled_y = 0;

    button = (BUTTON *)malloc(sizeof(BUTTON));

    if(button == NULL)
    {
        printf("\n***Failed to allocate memory for button***\n");
        exit(0);
    }

    // Setup surface texture for button
    surface_temp = IMG_Load(file_path);

    if(surface_temp == NULL)
    {
        printf("\n**Failed to load image \"%s\"", file_path);
        exit(0);
    }

    // button->surface = SDL_ConvertSurface(surface_temp, screen->format, 0);
    surface_opt = SDL_ConvertSurface(surface_temp, screen->format, 0);
    SDL_FreeSurface(surface_temp);

    // Set scale
    scaled_w = surface_opt->w * scale;
    scaled_h = surface_opt->h * scale;
    scaled_x = x_pos * scale;
    scaled_y = y_pos * scale;
    

    // Create a new surface for the scaled button image
    button->surface = SDL_CreateRGBSurface(0, scaled_w, scaled_h,
                                           screen->format->BitsPerPixel,
                                           screen->format->Rmask,
                                           screen->format->Gmask,
                                           screen->format->Bmask,
                                           screen->format->Amask);

    // Initialize values
    button->button_selected = button_is_not_selected;
    button->rect.x = scaled_x;
    button->rect.y = scaled_y;
    button->rect.w = scaled_w;
    button->rect.h = scaled_h;

    // Scale surface
    SDL_BlitScaled(surface_opt, NULL, button->surface, NULL);
    SDL_FreeSurface(surface_opt);

    return button;
}


/*
Name: display_button
Description: Draws the button to the screen
Inputs: SDL_Surface *screen: Screen for the button to be displayed on
        BUTTON *button: Button to be displayed
Outputs: N/A
*/
void display_button(SDL_Surface *screen, BUTTON *button)
{

    SDL_BlitSurface(button->surface, NULL, screen, &button->rect);

    return;
}


/*
Name: update_button
Description: Handles button logic for press events
Inputs: BUTTON *button: Button to be checked
        MOUSE *mouse: Mouse to be checked
Outputs: N/A
*/
void update_button(BUTTON *button, MOUSE *mouse)
{
    if(mouse->x_pos > button->rect.x && mouse->x_pos < button->rect.x + button->rect.w
        && mouse->y_pos > button->rect.y && mouse->y_pos < button->rect.y + button->rect.h
        && mouse->left_button_pressed == mouse_button_pressed)
    {
        button->button_selected = button_is_selected;
        // printf("Button is pressed\n");
    }

    return;
}

/*
Name: destroy_button
Description: Frees memory for the button
Inputs: BUTTON *button: Button to free
Outputs: N/A
*/
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