/*
    Function definitons for a textbox
*/

#include "define.h"
#include "mouse.h"
#include "textbox.h"


/*
Name: create_textbox
Description: Allocates a textbox and sets parameters
Inputs: TEXTBOX_CONFIG *tb_config: Configuration parameters for new textbox
        float scale: Amount to scale each position and size by
Outputs: TEXTBOX *: Pointer to a TEXTBOX struct
*/
TEXTBOX *create_textbox(TEXTBOX_CONFIG *tb_config, float scale)
{  
    SDL_Surface *prompt_surface = NULL;
    TEXTBOX *textbox = NULL;
    int prompt_width = 0;

    textbox = (TEXTBOX *)malloc(sizeof(TEXTBOX));

    if(textbox == NULL)
    {
        printf("\n***Failed to allocate memory for textbox***\n");
        exit(0);
    }

    textbox->font = TTF_OpenFont(tb_config->font_path, tb_config->font_size);

    // Determine prompt size
    SDL_Color color = {0,0,0};

    prompt_surface = TTF_RenderText_Blended(textbox->font, tb_config->prompt, color);

    if(prompt_surface == NULL)
    {
        printf("\n***Failed to allocate memory for textbox***\n");
        exit(0);
    }

    prompt_width = prompt_surface->w;
    SDL_FreeSurface(prompt_surface);


    textbox->prompt_rect.w = tb_config->width * scale;
    textbox->prompt_rect.h = tb_config->height * scale;
    textbox->prompt_rect.x = tb_config->x_pos * scale;
    textbox->prompt_rect.y = tb_config->y_pos * scale;

    textbox->textbox_rect.w = tb_config->width * scale;
    textbox->textbox_rect.h = tb_config->height * scale;
    textbox->textbox_rect.x = (tb_config->x_pos + prompt_width + 10) * scale;
    textbox->textbox_rect.y = tb_config->y_pos * scale;
    textbox->textbox_selected = TEXTBOX_IS_NOT_SELECTED;


    strcpy(textbox->prompt, tb_config->prompt);

    textbox->text[0] = '\0';

    return textbox;
}


/*
Name: display_textbox
Description: Displays textbox with prompt and text
Inputs: SDL_Surface *screen: Screen to display textbox
        TEXTBOX *textbox: Textbox to display
Outputs: N/A
*/
void display_textbox(SDL_Surface *screen, TEXTBOX *textbox)
{
    SDL_Surface *text_surface = NULL;
    SDL_Surface *prompt_surface = NULL;

    SDL_Color color = {0,0,0};
    prompt_surface = TTF_RenderText_Blended(textbox->font, textbox->prompt, color);

    if(prompt_surface == NULL)
    {
        printf("\n***Failed to generate prompt***\n");
        exit(0);
    }


    if(strlen(textbox->text) > 0)
    {
        text_surface = TTF_RenderText_Blended(textbox->font, textbox->text, color);

        if(text_surface == NULL)
        {
            printf("\n***Failed to generate text***\n");
            exit(0);
        }

        SDL_BlitSurface(text_surface, NULL, screen, &textbox->textbox_rect);
        SDL_FreeSurface(text_surface);

    }

    SDL_BlitSurface(prompt_surface, NULL, screen, &textbox->prompt_rect);
    SDL_FreeSurface(prompt_surface);

    return;
}


/*
Name: update_textbox
Description: Get input text for the textbox
Inputs: TEXTBOX *textbox: Currenty textbox for input
        MOUSE *mouse: Mouse on screen
        SDL_EVENT *event: Log of events that occured
Outputs: N/A
*/
void update_textbox(TEXTBOX *textbox, MOUSE *mouse, SDL_Event *event)
{
    if(event->type == SDL_MOUSEBUTTONDOWN)
    {
        if(mouse->x_pos > textbox->textbox_rect.x && mouse->x_pos < textbox->textbox_rect.x + textbox->textbox_rect.w
            && mouse->y_pos > textbox->textbox_rect.y && mouse->y_pos < textbox->textbox_rect.y + textbox->textbox_rect.h
            && mouse->left_button_pressed == mouse_button_pressed)
        {
            SDL_StartTextInput();
            textbox->textbox_selected = TEXTBOX_IS_SELECTED;
        }
        else if(!(mouse->x_pos > textbox->textbox_rect.x && mouse->x_pos < textbox->textbox_rect.x + textbox->textbox_rect.w
            && mouse->y_pos > textbox->textbox_rect.y && mouse->y_pos < textbox->textbox_rect.y + textbox->textbox_rect.h)
            && mouse->left_button_pressed == mouse_button_pressed)
        {
            SDL_StopTextInput();
            textbox->textbox_selected = TEXTBOX_IS_NOT_SELECTED;
        }
    }

    if(textbox->textbox_selected == TEXTBOX_IS_SELECTED && event->type == SDL_TEXTINPUT)
    {
        if(strlen(textbox->text) + strlen(event->text.text) < MAX_TEXTBOX_BUFFER)
        {
            strcat(textbox->text, event->text.text);
        }
    }
    
    if(textbox->textbox_selected == TEXTBOX_IS_SELECTED && event->type == SDL_KEYDOWN)
    {
        if(event->key.keysym.sym == SDLK_BACKSPACE && strlen(textbox->text) > 0)
        {
            textbox->text[strlen(textbox->text) - 1] = '\0';
        }
    }

    return;
}


/*
Name: destory_textbox
Description: frees textbox memory
Inputs: TEXTBOX *textbox: Textbox to free
Outputs: N/A
*/
void destroy_textbox(TEXTBOX *textbox)
{
    if(textbox == NULL)
    {
        return;
    }

    TTF_CloseFont(textbox->font);
    
    free(textbox);
    
    return;
}


/*
Name: config_textbox
Description: Set textbox configurations
Inputs: TEXTBOX_CONFIG *tb_config[NUM_of_TEXTBOXES]: An array of text config structs
Outputs: N/A
*/
void config_textbox(TEXTBOX_CONFIG *tb_config[NUM_of_TEXTBOXES])
{
    // Configure Test box
    tb_config[TEST_BOX]->font_path = "assets/fonts/Roboto_Condensed-Black.ttf";
    strcpy(tb_config[TEST_BOX]->prompt, "Frequency: ");
    tb_config[TEST_BOX]->font_size = 24;
    tb_config[TEST_BOX]->x_pos = 500;
    tb_config[TEST_BOX]->y_pos = 500;
    tb_config[TEST_BOX]->width = 200;
    tb_config[TEST_BOX]->height = 50;

}


/*
Name: setup_textboxes
Description: Allocates memory for textboxes
Inputs: SDL_Window *window: The current sdl window
        SDL_Surface *screen[NUM_of_SCREENS]: An array of sdl surfaces
        TEXTBOX_CONFIG *tb_config[NUM_of_TEXTBOXES]: An array of textboxes
Outputs: N/A
*/
void setup_textboxes(SDL_Window *window, SDL_Surface *screen[NUM_of_SCREENS], TEXTBOX *textbox[NUM_of_TEXTBOXES])
{
    TEXTBOX_CONFIG *tb_config[NUM_of_TEXTBOXES];
    float scale = 0;

    for(int i = 0; i < NUM_of_TEXTBOXES; i++)
    {
        tb_config[i] = NULL;

        tb_config[i] = (TEXTBOX_CONFIG *)malloc(sizeof(TEXTBOX_CONFIG));

        if(tb_config[i] == NULL)
        {
            fprintf(stderr, "Error creating SDL Renderer.\n");
            exit(0);
        }
    }

    config_textbox(tb_config);

    // Set resolution scale
    scale = (float)screen[MAIN]->w / WIDTH;

    textbox[TEST_BOX] = create_textbox(tb_config[TEST_BOX], scale);

    for(int i = 0; i < NUM_of_TEXTBOXES; i++)
    {
        free(tb_config[i]);
        tb_config[i] = NULL;
    }

    return;
}


/*
Name: teardown_textboxes
Description: destory each textbox
Inputs: TEXTBOX *textbox[NUM_of_TEXTBOXES]: An array of textboxes
Outputs: N/A
*/
void teardown_textboxes(TEXTBOX *textbox[NUM_of_TEXTBOXES])
{
    for(int i = 0; i < NUM_of_TEXTBOXES; i++)
    {
        destroy_textbox(textbox[i]);
    }

    return;
}