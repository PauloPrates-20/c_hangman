#include "word.h"
#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "config.h"

#define WORD_MAX 12

static char buffer[WORD_MAX] = {0};

static void Draw(Word *self) {
    const int LINE_THICK = 10;
    for(uint8_t i = 0; i < self->size; i++) {
        DrawRectangle((3 + i)*CELL_SIZE + 5 + OFFSET/2, 8*CELL_SIZE + OFFSET/2 - LINE_THICK, CELL_SIZE - 5, LINE_THICK, SPRITE_GREEN);
    }
}

Word WordCtr(const char* str) {
    strncpy(buffer, str, WORD_MAX - 1);

    return (Word){
        .word = buffer,
        .size = strlen(buffer),
        .guessed = 0,
        .Draw = Draw,
    };
}