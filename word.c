#include "word.h"
#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "config.h"
#include <ctype.h>

#define WORD_MAX 12

static char buffer[WORD_MAX] = {0};

static void Draw(Word *self) {
    const int LINE_THICK = 10;
    for(uint8_t i = 0; i < self->size; i++) {
        if(self->guessed & (1 << i)) {
            DrawText(TextFormat("%c", self->word[i]), (3 + i)*CELL_SIZE + 10 + OFFSET/2, 7*CELL_SIZE + OFFSET/2 - LINE_THICK/2, 50, SPRITE_GREEN);
        }

        DrawRectangle((3 + i)*CELL_SIZE + 5 + OFFSET/2, 8*CELL_SIZE + OFFSET/2 - LINE_THICK, CELL_SIZE - 5, LINE_THICK, SPRITE_GREEN);
    }
}

static bool Check(Word *self, char value) {
    bool found = false;
    self->complete = true;

    for(uint8_t i = 0; i < self->size; i++) {
        if(self->word[i] == tolower(value) || self->word[i] == toupper(value)) {
            found = true;
            self->guessed |= (1 << i);
        }
        
        if(!(self->guessed & (1 << i))) self->complete = false;
    }

    return found;
}

Word WordCtr(const char* str) {
    strncpy(buffer, str, WORD_MAX - 1);

    return (Word){
        .word = buffer,
        .size = strlen(buffer),
        .guessed = 0,
        .complete = false,
        .Draw = Draw,
        .Check = Check,
    };
}