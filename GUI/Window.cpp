#include "Window.h"

void Window::initZoom() {
    float wheelMove = GetMouseWheelMove();
    if (wheelMove != 0) {
        this->camera.zoom += wheelMove * 0.1f;
        if (this->camera.zoom > this->maxZoom) this->camera.zoom = this->maxZoom;
        if (this->camera.zoom < this->minZoom) this->camera.zoom = this->minZoom;
    }
}

void Window::initPanning() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mouseDelta = GetMouseDelta();
        this->camera.target.x -= mouseDelta.x / this->camera.zoom;
        this->camera.target.y -= mouseDelta.y / this->camera.zoom;
    }
}