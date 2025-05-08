#include "raylib.h"

int main(int argc, char* argv[]) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Elysium -Kiseki Battle Simulator");

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("There will be something here eventually...", 0, 0, 36, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}