#pragma once	  // Vec3.h - Определение структуры вектора
#ifndef VEC3_H
#define VEC3_H

#include <cmath>

struct Vec3 {
    float x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
    Vec3 operator-(const Vec3& other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
    Vec3 operator*(float t) const { return Vec3(x * t, y * t, z * t); }
    Vec3 operator/(float t) const { return Vec3(x / t, y / t, z / t); }

    float dot(const Vec3& other) const { return x * other.x + y * other.y + z * other.z; }

    Vec3 normalize() const {
        float length = std::sqrt(x * x + y * y + z * z);
        return (length > 0) ? *this * (1.0f / length) : Vec3(0, 0, 0);
    }
};

#endif

