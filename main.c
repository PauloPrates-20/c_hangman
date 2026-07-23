#include "raylib.h"
#include "config.h"
#include "keyboard.h"

static void DrawFrame() {
    Rectangle rec = {
        .x = OFFSET - FR_THICK*2,
        .y = OFFSET - FR_THICK*2,
        .width = CELL_SIZE*CELL_COUNT - OFFSET/2 - FR_THICK*2,
        .height = CELL_SIZE*CELL_COUNT - OFFSET/2 - FR_THICK*2,
    };

    DrawRectangleLinesEx(rec, FR_THICK, SPRITE_GREEN);
}

int main(void) {
    InitWindow(CELL_SIZE*CELL_COUNT + OFFSET, CELL_SIZE*CELL_COUNT + OFFSET, "Retro Hangman");
    SetTargetFPS(60);
    
    Keyboard board = KeyboardCtr();

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BG_GREEN);
        DrawFrame();
        board.Draw(&board);

        EndDrawing();
    }

    CloseWindow();
}