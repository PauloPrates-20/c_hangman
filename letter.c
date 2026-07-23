#include "letter.h"
#include "config.h"

static void Draw(Letter *self) {
    const float LINE_THICK = 3.0f;
    Rectangle rec = {
        .x = self->pos.x*CELL_SIZE + OFFSET + LINE_THICK,
        .y = self->pos.y*CELL_SIZE + OFFSET + LINE_THICK,
        .width = CELL_SIZE - 1 - LINE_THICK*2,
        .height = CELL_SIZE - 1 - LINE_THICK*2,
    };

    DrawRectangleRoundedLinesEx(rec, 0.5f, 6, LINE_THICK, SPRITE_GREEN);
    DrawText(
        TextFormat("%c", self->value),
        self->pos.x*CELL_SIZE + OFFSET + LINE_THICK + 3,
        self->pos.y*CELL_SIZE + OFFSET + LINE_THICK,
        20,
        SPRITE_GREEN
    );
}


Letter LetterCtr(char value, Vector2 pos) {
    return (Letter){
        value,
        pos,
        Draw,
    };
}