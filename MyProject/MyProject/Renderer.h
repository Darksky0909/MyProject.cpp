#pragma once
// Renderer.h - Определение функций рендеринга
//#ifndef RENDERER_H
//#define RENDERER_H
//
//#include "Sphere.h"
//#include <vector>
//
//SDL_Color traceRay(const Ray& ray, const std::vector<Sphere>& spheres);
//void renderScene(SDL_Renderer* renderer, const std::vector<Sphere>& spheres, int width, int height);
//
//#endif
#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <vector>
#include "Sphere.h"

// Объявление функции рендеринга
void renderSceneToBuffer(Uint32* pixels, const std::vector<Sphere>& spheres, int width, int height, int pitch);

#endif // RENDERER_H
