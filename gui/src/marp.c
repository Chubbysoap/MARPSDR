
#include "define.h"
#include "button.h"
#include "mouse.h"
#include "screen.h"
#include "textbox.h"


int main()
{
    SDL_Surface *screen[NUM_of_SCREENS];
    TEXTBOX *textbox[NUM_of_TEXTBOXES];
    int program_is_running = 1;
    int last_frame_time = 0;
    int time_to_wait = 0;


    // Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        program_is_running = 0;
    }

    // Initialize image input
    if(IMG_Init(IMG_INIT_PNG) == 0)
    {
        fprintf(stderr, "Error initializing SDL Image.\n");
        program_is_running = 0;
    }

    // Initialize test input
    if(TTF_Init() != 0)
    {
        fprintf(stderr, "Error initializing TTF.\n");
        program_is_running = 0;
    }

    // Setup window
    SDL_Window *window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_BORDERLESS
        // SDL_WINDOW_FULLSCREEN
        // SDL_WINDOW_RESIZABLE
    );

    if(window == NULL)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        program_is_running = 0;
    }


    setup_screens(window, screen);
    setup_textboxes(window, screen, textbox);


    // Setup
    MOUSE *mouse = create_mouse();
    BUTTON *button = create_button(screen[MAIN], "assets/button_textures/TestButton.png", 100, 800);
    BUTTON *exit_button = create_button(screen[FM_RADIO], "assets/button_textures/exit.png", 200, 400);

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
        update_textbox(textbox[TEST_BOX], mouse, &event);


        
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
            exit_button->button_selected = button_is_not_selected;
        }

        // Render
        if(button->button_selected == button_is_selected)
        {
            display_FM_screen(screen[FM_RADIO], exit_button);
        }
        else
        {
            display_main_screen(screen[MAIN], button);
            display_textbox(screen[MAIN], textbox[TEST_BOX]);
        }
        

        SDL_UpdateWindowSurface(window);
    }

    // Destroy window
    SDL_DestroyWindow(window);
    SDL_StopTextInput();

    // Cleanup
    destroy_mouse(mouse);
    destroy_button(button);
    teardown_textboxes(textbox);
    TTF_Quit();
    SDL_Quit();


    return 0;
}