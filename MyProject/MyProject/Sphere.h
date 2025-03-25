// Sphere.h - Определение сферы и алгоритм пересечения с лучом
#ifndef SPHERE_H
#define SPHERE_H

#include "Vec3.h"
#include "Ray.h"
#include <SDL2/SDL.h>

struct Sphere {
    Vec3 center;
    float radius;
    SDL_Color color;
    
    Sphere(const Vec3& center, float radius, SDL_Color color) : center(center), radius(radius), color(color) {}

    bool intersect(const Ray& ray, float& t) const {
        Vec3 oc = ray.origin - center;
        float a = ray.direction.dot(ray.direction);
        float b = 2.0f * oc.dot(ray.direction);
        float c = oc.dot(oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            t = (-b - std::sqrt(discriminant)) / (2.0f * a);
            return t > 0; // Пересечение перед камерой
        }
        return false;
    }
};

#endif
#pragma once
