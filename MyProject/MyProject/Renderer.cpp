#include "Renderer.h"
#include <limits>

// Функция трассировки лучей, которая вычисляет цвет пикселя
SDL_Color traceRay(const Ray& ray, const std::vector<Sphere>& spheres) {
    float t_min = std::numeric_limits<float>::max();
    const Sphere* hit_sphere = nullptr;

    for (const auto& sphere : spheres) {
        float t;
        if (sphere.intersect(ray, t) && t < t_min) {
            t_min = t;
            hit_sphere = &sphere;
        }
    }

    if (hit_sphere) {
        return hit_sphere->color;
    }

    return { 0, 0, 0, 255 }; // Чёрный фон
}

// Основная функция рендеринга, которая рисует сцену в буфер
void renderSceneToBuffer(Uint32* pixels, const std::vector<Sphere>& spheres, int width, int height, int pitch) {
    Vec3 cameraOrigin(0, 0, 0);
    float viewportHeight = 2.0f;
    float viewportWidth = viewportHeight * static_cast<float>(width) / height;
    Vec3 viewportHorizontal(viewportWidth, 0, 0);
    Vec3 viewportVertical(0, -viewportHeight, 0); // Инвертируем ось Y для SDL
    Vec3 viewportLowerLeft = cameraOrigin - viewportHorizontal / 2 - viewportVertical / 2 - Vec3(0, 0, 1);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float u = static_cast<float>(x) / width;
            float v = static_cast<float>(y) / height;
            Ray ray(cameraOrigin, viewportLowerLeft + viewportHorizontal * u + viewportVertical * v - cameraOrigin);
            SDL_Color pixelColor = traceRay(ray, spheres);

            // Записываем цвет в буфер
            Uint32* pixel = (Uint32*)((Uint8*)pixels + y * pitch) + x;
            *pixel = SDL_MapRGBA(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), pixelColor.r, pixelColor.g, pixelColor.b, pixelColor.a);
        }
    }
}
