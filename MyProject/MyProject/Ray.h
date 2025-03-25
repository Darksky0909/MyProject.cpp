#pragma once
// Ray.h - Определение структуры луча
#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

struct Ray {
    Vec3 origin;
    Vec3 direction;

    Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction.normalize()) {}
};

#endif
