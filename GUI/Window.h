#ifndef PARTICLELIFE_WINDOW_H
#define PARTICLELIFE_WINDOW_H

#include "raylib.h"
#include <string>

class Window {
public:
    int width;
    int height;
    std::string title;
    int targetFPS;
    float maxZoom;
    float minZoom;
    Camera2D camera{};


    Window(const int width, const int height, std::string title, const int targetFPS = 144,
        const float maxZoom = 5.0f, const float minZoom = 0.1f)
        : width(width), height(height), title(std::move(title)), targetFPS(targetFPS), maxZoom(maxZoom),
    minZoom(minZoom){
        InitWindow(width, height, this->title.c_str());
        SetTargetFPS(targetFPS);
        camera.target = { static_cast<float>(width) / 2.0f, static_cast<float>(height) / 2.0f };
        camera.offset = { static_cast<float>(width) / 2.0f, static_cast<float>(height) / 2.0f };
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;
    }

    ~Window() {
        CloseWindow();
    }

    void initZoom();
    void initPanning();
};

#endif //PARTICLELIFE_WINDOW_H
