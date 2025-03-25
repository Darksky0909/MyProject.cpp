#pragma once
// SDLSetup.h - ”правление SDL
#ifndef SDLSETUP_H
#define SDLSETUP_H

#include <SDL2/SDL.h>

bool initializeSDL(SDL_Window*& window, SDL_Renderer*& renderer, int width, int height);
void cleanupSDL(SDL_Window* window, SDL_Renderer* renderer);

#endif
