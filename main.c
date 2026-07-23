#include "raylib.h"
#include "config.h"
#include "letter.h"

int main(void) {
    InitWindow(CELL_SIZE*CELL_COUNT + OFFSET, CELL_SIZE*CELL_COUNT + OFFSET, "Retro Hangman");
    SetTargetFPS(60);
    
    Letter a = LetterCtr('A', (Vector2){6, 6});

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BG_GREEN);
        a.Draw(&a);

        EndDrawing();
    }

    CloseWindow();
}