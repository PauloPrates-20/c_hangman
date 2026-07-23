#include "raylib.h"
#include "config.h"

int main(void) {
    InitWindow(CELL_SIZE*CELL_COUNT + OFFSET, CELL_SIZE*CELL_COUNT + OFFSET, "Retro Hangman");
    SetTargetFPS(60);
    
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BG_GREEN);

        EndDrawing();
    }

    CloseWindow();
}