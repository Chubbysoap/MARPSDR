#include "define.h"


int main()
{
    int game_is_running = 1;
    int last_frame_time = 0;
    int time_to_wait = 0;

    // initialize window
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        game_is_running = 0;
    }

    if(IMG_Init(IMG_INIT_PNG) == 0)
    {
        fprintf(stderr, "Error initializing SDL Image.\n");
        game_is_running = 0;
    }

    SDL_Window *window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_BORDERLESS
        // SDL_WINDOW_FULLSCREEN
    );

    if(window == NULL)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        game_is_running = 0;
    }

    SDL_Surface *screen = SDL_GetWindowSurface(window);

    if(screen == NULL)
    {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        game_is_running = 0;
    }

    // Setup
    MOUSE *mouse = create_mouse();
    BUTTON *button = create_button(screen, "assets/TestButton.png", 100,200);

    // Loop
    while(game_is_running)
    {
        // Process input
        SDL_Event event;
        SDL_PollEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
                game_is_running = 0;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    game_is_running = 0;
                }
                break;
        }
        update_mouse(mouse, event);
        update_button(button, mouse);

        
        // Update
        // Logic to keep a fixed timestep
        time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

        if(time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
        {
            SDL_Delay(time_to_wait);
        }

        last_frame_time = SDL_GetTicks();

        // Render
        if(button->button_selected == button_is_selected)
        {
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 255));

        }
        else
        {
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        }

        display_button(screen, button);
        SDL_UpdateWindowSurface(window);
    }

    // Destroy window
    // SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // Cleanup
    destroy_mouse(mouse);
    destroy_button(button);


    return 0;
}