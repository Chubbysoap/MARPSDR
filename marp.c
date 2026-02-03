#include "define.h"


int main()
{
    SDL_Surface *screen[NUM_of_SCREENS];
    int program_is_running = 1;
    int last_frame_time = 0;
    int time_to_wait = 0;


    // initialize window
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        program_is_running = 0;
    }

    if(IMG_Init(IMG_INIT_PNG) == 0)
    {
        fprintf(stderr, "Error initializing SDL Image.\n");
        program_is_running = 0;
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
        program_is_running = 0;
    }


    // Initialize screen surfaces
    for(int i = 0; i < NUM_of_SCREENS; i++)
    {
        screen[i] = NULL;

        screen[i] = SDL_GetWindowSurface(window);

        if(screen[i] == NULL)
        {
            fprintf(stderr, "Error creating SDL Renderer.\n");
            program_is_running = 0;
        }
    }

    // Setup
    MOUSE *mouse = create_mouse();
    BUTTON *button = create_button(screen[MAIN], "assets/TestButton.png", 100,200);
    BUTTON *exit_button = create_button(screen[FM_RADIO], "assets/exit.png", 200, 400);

    // Loop
    while(program_is_running)
    {
        // Process input
        SDL_Event event;
        SDL_PollEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
                program_is_running = 0;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    program_is_running = 0;
                }
                break;
        }
        update_mouse(mouse, event);
        update_button(button, mouse);
        update_button(exit_button, mouse);

        
        // Update
        // Logic to keep a fixed timestep
        time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

        if(time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
        {
            SDL_Delay(time_to_wait);
        }

        last_frame_time = SDL_GetTicks();

        if(exit_button->button_selected == button_is_selected)
        {
            button->button_selected = button_is_not_selected;
        }

        // Render
        if(button->button_selected == button_is_selected)
        {
            display_FM_screen(screen[FM_RADIO], exit_button);
        }
        else
        {
            display_main_screen(screen[MAIN], button);
        }
        

        SDL_UpdateWindowSurface(window);
    }

    // Destroy window
    SDL_DestroyWindow(window);
    SDL_Quit();

    // Cleanup
    destroy_mouse(mouse);
    destroy_button(button);


    return 0;
}