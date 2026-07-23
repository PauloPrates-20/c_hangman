#include "letter.h"
#include "config.h"
#include <stdio.h>

#define LINE_THICK 3.0f

static void Draw(Letter *self) {
    DrawRectangleRoundedLinesEx(self->rec, 0.5f, 6, LINE_THICK, SPRITE_GREEN);
    DrawText(
        TextFormat("%c", self->value),
        self->pos.x*CELL_SIZE + OFFSET/2 + LINE_THICK*3,
        self->pos.y*CELL_SIZE + OFFSET/2 + LINE_THICK,
        CELL_SIZE - LINE_THICK*2,
        SPRITE_GREEN
    );
}

static void Update(Letter *self) {
    if(CheckCollisionPointRec(GetMousePosition(), self->rec)) {
        printf("Pressed: %c\n", self->value);
    }
}

Letter LetterCtr(char value, Vector2 pos) {
    Rectangle rec = {
        .x = pos.x*CELL_SIZE + OFFSET/2 + LINE_THICK,
        .y = pos.y*CELL_SIZE + OFFSET/2 + LINE_THICK,
        .width = CELL_SIZE - 1 - LINE_THICK*2,
        .height = CELL_SIZE - 1 - LINE_THICK*2,
    };
    
    return (Letter){
        value,
        pos,
        rec,
        Draw,
        Update,
    };
}