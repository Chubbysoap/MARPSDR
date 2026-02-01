/*
    Function Definitions for mouse
*/


#include "define.h"

/*
Name: create_mouse
Description: Allocates memory for a struct for the mouse and initializes values
Inputs: N/A
Outputs: MOUSE structure pointer
*/
MOUSE * create_mouse(void)
{
    MOUSE *mouse = NULL;

    mouse = (MOUSE *)malloc(sizeof(MOUSE));

    if(mouse == NULL)
    {
        printf("\n***Failed to allocate memory for mouse***\n");
    }

    // Set initial values
    mouse->x_pos = 0;
    mouse->y_pos = 0;
    mouse->left_button_pressed = mouse_button_not_pressed;
    mouse->middle_button_pressed = mouse_button_not_pressed;
    mouse->right_button_pressed = mouse_button_not_pressed;
    mouse->mouse_wheel_y = mouse_scroll_none;

    return mouse;
}

/*
Name: update_mouse
Description: Updates values in mouse structure
Inputs: MOUSE structure pointer
Outputs: N/A
*/
void update_mouse(MOUSE *mouse, SDL_Event event)
{
    int button_mask = 0;

    button_mask = SDL_GetMouseState(&mouse->x_pos, &mouse->y_pos);
    
    // Update button presses
    if(button_mask & SDL_BUTTON_LMASK)
    {
        mouse->left_button_pressed = mouse_button_pressed;
        // printf("Left mouse pressed at (%d, %d)\n", mouse->x_pos, mouse->y_pos);
    }
    else
    {
        mouse->left_button_pressed = mouse_button_not_pressed;
    }

    if(button_mask & SDL_BUTTON_MMASK)
    {
        mouse->middle_button_pressed = mouse_button_pressed;
        // printf("Middle mouse pressed at (%d, %d)\n", mouse->x_pos, mouse->y_pos);
    }
    else
    {
        mouse->middle_button_pressed = mouse_button_not_pressed;
    }

    if(button_mask & SDL_BUTTON_RMASK)
    {
        mouse->right_button_pressed = mouse_button_pressed;
        // printf("Right mouse pressed at (%d, %d)\n", mouse->x_pos, mouse->y_pos);
    }
    else
    {
        mouse->right_button_pressed = mouse_button_not_pressed;
    }

    // Update scroll wheel
    if(event.wheel.y > 0) // scroll up
    {
        mouse->mouse_wheel_y = mouse_scroll_up;
        // printf("Mouse Scroll up\n");
    }
    else if(event.wheel.y < 0) // scroll down
    {
        mouse->mouse_wheel_y = mouse_scroll_down;
        // printf("Mouse Scroll down\n");
    }
    else
    {
        mouse->mouse_wheel_y = mouse_scroll_none;
    }

    return;
}


/*
Name: destroy_mouse
Description: Destroys memory for MOUSE structure
Inputs: MOUSE structure pointer
Outputs: N/A
*/
void destroy_mouse(MOUSE *mouse)
{
    free(mouse);

    mouse = NULL;

    return;
}