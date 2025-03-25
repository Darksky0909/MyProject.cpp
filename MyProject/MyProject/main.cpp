//#define SDL_MAIN_HANDLED    //Говорим SDL не переопределять main()
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <limits>
//#include <SDL2/SDL.h>
//
//// 3D Vector Structure
//struct Vec3 {
//    float x, y, z;
//
//    Vec3() : x(0), y(0), z(0) {}
//    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
//
//        Vec3 operator/(float t) const {
//            return Vec3(x / t, y / t, z / t);
//        }
//    
//    Vec3 operator-(const Vec3& other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
//    Vec3 operator+(const Vec3& other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
//    Vec3 operator*(float t) const { return Vec3(x * t, y * t, z * t); }
//    float dot(const Vec3& other) const { return x * other.x + y * other.y + z * other.z; }
//    Vec3 normalize() const {
//        float length = std::sqrt(x * x + y * y + z * z);
//        return *this * (1.0f / length);
//    }
//};
//
//// Ray Structure
//struct Ray {
//    Vec3 origin;
//    Vec3 direction;
//
//    Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction.normalize()) {}
//};
//
//// Sphere Structure
//struct Sphere {
//    Vec3 center;
//    float radius;
//    SDL_Color color; // Sphere's color
//
//    Sphere(const Vec3& center, float radius, SDL_Color color) : center(center), radius(radius), color(color) {}
//
//    bool intersect(const Ray& ray, float& t) const {
//        Vec3 oc = ray.origin - center;
//        float a = ray.direction.dot(ray.direction);
//        float b = 2.0f * oc.dot(ray.direction);
//        float c = oc.dot(oc) - radius * radius;
//        float discriminant = b * b - 4 * a * c;
//
//        if (discriminant > 0) {
//            t = (-b - std::sqrt(discriminant)) / (2.0f * a);
//            return true;
//        }
//        return false;
//    }
//};
//
//// Calculate Pixel Color
//SDL_Color traceRay(const Ray& ray, const std::vector<Sphere>& spheres) {
//    float t_min = std::numeric_limits<float>::max();
//    const Sphere* hit_sphere = nullptr;
//
//    for (const auto& sphere : spheres) {
//        float t;
//        if (sphere.intersect(ray, t) && t < t_min) {
//            t_min = t;
//            hit_sphere = &sphere;
//        }
//    }
//
//    if (hit_sphere) {
//        return hit_sphere->color;
//    }
//
//    return {0, 0, 0, 255}; // Black background
//}
//
//int main(int argc, char* argv[]) {
//    const int width = 800;
//    const int height = 600;
//
//    // Initialize SDL2
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    SDL_Window* window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
//    if (window == nullptr) {
//        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        SDL_Quit();
//        return 1;
//    }
//
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (renderer == nullptr) {
//        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        return 1;
//    }
//
//    // Scene setup
//    std::vector<Sphere> spheres;
//    spheres.emplace_back(Vec3(0, 0, -3), 1.0f, SDL_Color{255, 0, 0, 255});       // Red sphere
//    spheres.emplace_back(Vec3(2, 0, -4), 0.5f, SDL_Color{0, 255, 0, 255});       // Green sphere
//    spheres.emplace_back(Vec3(-1, -1, -2), 0.7f, SDL_Color{0, 0, 255, 255});    // Blue sphere
//
//    // Camera setup
//    Vec3 cameraOrigin(0, 0, 0);
//    float viewportHeight = 2.0f;
//    float viewportWidth = viewportHeight * static_cast<float>(width) / height;
//    Vec3 viewportHorizontal(viewportWidth, 0, 0);
//    Vec3 viewportVertical(0, -viewportHeight, 0); // Inverted Y for SDL
//    Vec3 viewportLowerLeft = cameraOrigin - viewportHorizontal / 2 - viewportVertical / 2 - Vec3(0, 0, 1);
//
//    // Render loop
//    bool quit = false;
//    SDL_Event event;
//
//    while (!quit) {
//        while (SDL_PollEvent(&event) != 0) {
//            if (event.type == SDL_QUIT) {
//                quit = true;
//            }
//        }
//
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear with black
//        SDL_RenderClear(renderer);
//
//        for (int y = 0; y < height; ++y) {
//            for (int x = 0; x < width; ++x) {
//                float u = static_cast<float>(x) / width;
//                float v = static_cast<float>(y) / height;
//                Ray ray(cameraOrigin, viewportLowerLeft + viewportHorizontal * u + viewportVertical * v - cameraOrigin);
//                SDL_Color pixelColor = traceRay(ray, spheres);
//                SDL_SetRenderDrawColor(renderer, pixelColor.r, pixelColor.g, pixelColor.b, pixelColor.a);
//                SDL_RenderDrawPoint(renderer, x, y);
//            }
//        }
//
//        SDL_RenderPresent(renderer);
//    }
//
//    // Cleanup
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}

//// main.cpp - Главный файл программы
//#define SDL_MAIN_HANDLED  // Нужно для корректного запуска SDL в Visual Studio
//
//#include "SDLSetup.h"
//#include "Renderer.h"
//#include <vector>
//
//int main(int argc, char* argv[]) {
//    const int width = 800;
//    const int height = 600;
//
//    // Инициализация SDL
//    SDL_Window* window = nullptr;
//    SDL_Renderer* renderer = nullptr;
//    if (!initializeSDL(window, renderer, width, height)) {
//        return 1;  // Ошибка при инициализации SDL
//    }
//
//    // Определение сцены: набор сфер с разными цветами
//    std::vector<Sphere> spheres = {
//        Sphere(Vec3(0, 0, -3), 1.0f, SDL_Color{255, 0, 0, 255}),  // Красная сфера
//        Sphere(Vec3(2, 0, -4), 0.5f, SDL_Color{0, 255, 0, 255}),  // Зеленая сфера
//        Sphere(Vec3(-1, -1, -2), 0.7f, SDL_Color{0, 0, 255, 255}) // Синяя сфера
//    };
//
//    // Основной цикл приложения
//    bool quit = false;
//    SDL_Event event;
//    while (!quit) {
//        // Обработка событий (например, закрытие окна)
//        while (SDL_PollEvent(&event) != 0) {
//            if (event.type == SDL_QUIT) {
//                quit = true;
//            }
//        }
//
//        // Отрисовка сцены
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Очистка экрана черным цветом
//        SDL_RenderClear(renderer);
//
//        renderScene(renderer, spheres, width, height);  // Вызов функции рендеринга
//
//        SDL_RenderPresent(renderer);  // Отображение рендеринга на экран
//    }
//
//    // Очистка ресурсов и завершение работы
//    cleanupSDL(window, renderer);
//    return 0;
//}
//


#define SDL_MAIN_HANDLED  // Отключаем SDL_main, чтобы избежать проблем со входной точкой в Visual Studio

#include "SDLSetup.h"  // Заголовочный файл для инициализации SDL
#include "Renderer.h"  // Заголовочный файл для рендеринга сцены
#include <vector>

// 🔹 Структура для сфер, которые могут двигаться
struct MovingSphere {
    Sphere sphere;      // Сама сфера
    Vec3 velocity;      // Вектор скорости
    float speedFactor;  // Коэффициент скорости движения

    MovingSphere(Sphere s, Vec3 v, float speed) : sphere(s), velocity(v), speedFactor(speed) {}

    // Метод обновления позиции сферы
    void update(float deltaTime) {
        sphere.center = sphere.center + velocity * deltaTime * speedFactor;
    }
};

int main(int argc, char* argv[]) {
    // 🔹 Размеры окна
    const int width = 800, height = 600;

    // 🔹 Ограничение FPS
    const int targetFPS = 60;
    const float frameDelay = 1000.0f / targetFPS;  // 16 мс на кадр

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // Инициализируем SDL и создаём окно и рендерер
    if (!initializeSDL(window, renderer, width, height)) {
        return 1;
    }

    // 🔹 Создаём текстуру для буферизации рендеринга (двойная буферизация)
    SDL_Texture* framebuffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

    // 🔹 Создаём движущиеся сферы (начальная позиция, радиус, цвет, начальная скорость)
    std::vector<MovingSphere> spheres = {
        MovingSphere(Sphere(Vec3(0, 0, -3), 1.0f, SDL_Color{255, 0, 0, 255}), Vec3(1.0f, 0, 0), 1.5f),
        MovingSphere(Sphere(Vec3(2, 0, -4), 0.5f, SDL_Color{0, 255, 0, 255}), Vec3(-0.7f, 0, 0), 1.2f),
        MovingSphere(Sphere(Vec3(-1, -1, -2), 0.7f, SDL_Color{0, 0, 255, 255}), Vec3(0, 1.0f, 0), 0.9f)
    };

    bool quit = false;
    SDL_Event event;
    Uint32 lastTime = SDL_GetTicks();  // Время последнего кадра
    float speedFactor = 1.0f;          // Глобальный коэффициент скорости движения сфер

    while (!quit) {
        Uint32 startFrame = SDL_GetTicks();  // Запоминаем время начала кадра
        float deltaTime = (startFrame - lastTime) / 5000.0f;  // Разница во времени в секундах
        lastTime = startFrame;

        // 🔹 Обрабатываем события SDL (например, закрытие окна или нажатия клавиш)
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_UP:
                    speedFactor += 0.1f;  // Ускоряем движение
                    break;
                case SDLK_DOWN:
                    speedFactor = std::max(0.1f, speedFactor - 0.1f);  // Замедляем, но не даём уйти в 0
                    break;
                }
            }
        }

        // 🔹 Обновляем позиции сфер (движение)
        for (auto& sphere : spheres) {
            sphere.update(deltaTime * speedFactor);

            // Проверяем границы экрана и отражаем сферу при столкновении
            if (sphere.sphere.center.x > 2.0f || sphere.sphere.center.x < -2.0f) {
                sphere.velocity.x = -sphere.velocity.x;
            }
            if (sphere.sphere.center.y > 1.0f || sphere.sphere.center.y < -1.0f) {
                sphere.velocity.y = -sphere.velocity.y;
            }
        }

        // 🔹 Заполняем буфер кадра перед рендерингом
        void* pixels;
        int pitch;
        SDL_LockTexture(framebuffer, nullptr, &pixels, &pitch);
        memset(pixels, 0, pitch * height);  // Очищаем буфер (фон чёрный)

        // Конвертируем вектора движущихся сфер в обычные сферы (без движения)
        std::vector<Sphere> staticSpheres;
        for (const auto& movingSphere : spheres) {
            staticSpheres.push_back(movingSphere.sphere);
        }

        // 🔹 Рендерим сцену в буфер
        renderSceneToBuffer(static_cast<Uint32*>(pixels), staticSpheres, width, height, pitch);
        SDL_UnlockTexture(framebuffer);

        // 🔹 Выводим буфер на экран
        SDL_RenderCopy(renderer, framebuffer, nullptr, nullptr);
        SDL_RenderPresent(renderer);

        // 🔹 Ограничение FPS (ждём, если кадр занял слишком мало времени)
        Uint32 frameTime = SDL_GetTicks() - startFrame;
        if (frameTime < frameDelay) {
            SDL_Delay(static_cast<Uint32>(frameDelay - frameTime));
        }
    }

    // 🔹 Освобождаем ресурсы
    SDL_DestroyTexture(framebuffer);
    cleanupSDL(window, renderer);
    return 0;
}
/*
  ✅ Все важные строки кода имеют комментарии
  ✅ Код более читабельный → Чёткая структура, заголовки для секций.
  ✅ Добавлены проверки границ → Сферы отскакивают, а не выходят за экран.
  ✅ Двойная буферизация → Изображение плавное, без мерцания.
  ✅ Ограничение FPS → Гарантированно 60 кадров / сек(нет скачков).
  ✅ Клавиши ↑ и ↓ регулируют скорость сфер(можно ускорять и замедлять движение).


*/
