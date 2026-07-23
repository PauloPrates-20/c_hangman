#include "raylib.h"

int main(void) {
    InitWindow(750, 750, "Retro Hangman");
    SetTargetFPS(60);
    
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        EndDrawing();
    }

    CloseWindow();
}