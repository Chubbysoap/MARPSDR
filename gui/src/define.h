#ifndef define_h
#define define_h

// Standard header files
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Custom header files
#include "button.h"
#include "mouse.h"
#include "screen.h"

// Resolution definitions
#define WIDTH 1920
#define HEIGHT 1080

// FPS definitions
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

// Screen definitions
#define NUM_of_SCREENS 2
#define MAIN 0
#define FM_RADIO 1

#endif