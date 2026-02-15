/*
    Fuction definitions for setting up and displaying certain screens
*/

#include "define.h"
#include "button.h"


/*
Name: setup_screens
Description: Generate surfaces for each screen
Inputs: SDL_Window *window: Window for the surfaces to display
        SDL_SURFACE *screen[NUM_of_SCREENS]: An array to hold each screen
Outputs: N/A
*/
void setup_screens(SDL_Window *window, SDL_Surface *screen[NUM_of_SCREENS])
{
    // Initialize screen surfaces
    for(int i = 0; i < NUM_of_SCREENS; i++)
    {
        screen[i] = NULL;

        screen[i] = SDL_GetWindowSurface(window);

        if(screen[i] == NULL)
        {
            fprintf(stderr, "Error creating SDL Renderer.\n");
            exit(0);
        }
    }

    return;
}


/*
Name: display_main_screen
Description: Displays the main screen
Inputs: SDL_SURFACE *screen: Screen to be displayed
        BUTTON *button: Buttons to display on screen
Outputs: N/A
*/
void display_main_screen(SDL_Surface *screen, BUTTON *button)
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    display_button(screen, button);

    return;
}


/*
Name: display_FM_screen
Description: Displays the FM screen
Inputs: SDL_SURFACE *screen: Screen to be displayed
        BUTTON *button: Buttons to display on screen
Outputs: N/A
*/
void display_FM_screen(SDL_Surface *screen, BUTTON *button)
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 255));
    display_button(screen, button);

    return;
}