#include "raylib.h"
#include "config.h"
#include "keyboard.h"

int main(void) {
    InitWindow(CELL_SIZE*CELL_COUNT + OFFSET, CELL_SIZE*CELL_COUNT + OFFSET, "Retro Hangman");
    SetTargetFPS(60);
    
    Keyboard board = KeyboardCtr();

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BG_GREEN);
        board.Draw(&board);

        EndDrawing();
    }

    CloseWindow();
}