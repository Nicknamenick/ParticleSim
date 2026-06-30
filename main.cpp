#include <iostream>
#include "particles/GlobalTypes.h"
#include "particles/Particle.h"
#include "GUI/Window.h"
#include "simulation/Simulation.h"
#include "raylib.h"
// 200, 400, 1000 ;; 50, 300, 600
#define RED_COUNT 400
#define GREEN_COUNT 100
#define BLUE_COUNT 900

using namespace std;
using namespace Types;

int main() {
    Window window(1200, 800, "Particle Simulation", 144);
    Simulation simulation;

    if (window.width >= MAX_X || window.height >= MAX_Y) {
        cout << "Window size is LARGER than the defined MAX_X or MAX_Y. Particles will be spawned within the defined bounds." << endl;
        simulation.spawnParticles(RED_COUNT, &Red, 50.0f, 100.0f
            , MIN_X, MAX_X, MIN_Y, MAX_Y);
        simulation.spawnParticles(GREEN_COUNT, &Green, 50.0f, 100.0f
            , MIN_X, MAX_X, MIN_Y, MAX_Y);
        simulation.spawnParticles(BLUE_COUNT, &Blue, 50.0f, 100.0f
            , MIN_X, MAX_X, MIN_Y, MAX_Y);
    }else {
        cout << "Window size is SMALLER than the defined MAX_X or MAX_Y. Particles will be spawned within the window bounds." << endl;
        simulation.spawnParticles(RED_COUNT, &Red, 50.0f, 100.0f
            , MIN_X, window.width, MIN_Y, window.height);
        simulation.spawnParticles(GREEN_COUNT, &Green, 50.0f, 100.0f
            , MIN_X, window.width, MIN_Y, window.height);
        simulation.spawnParticles(BLUE_COUNT, &Blue, 50.0f, 100.0f
            , MIN_X, window.width, MIN_Y, window.height);
    }

    while (!WindowShouldClose()) {
        window.initZoom();
        window.initPanning();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(window.camera);

        simulation.update(GetFrameTime());
        simulation.drawAll();

        EndMode2D();
        DrawText("Particle Life Simulation", 10, 10, 20, DARKGRAY);
        DrawFPS(10, 40);
        EndDrawing();
    }

    return 0;
}
