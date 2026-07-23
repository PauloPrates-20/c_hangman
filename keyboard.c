#include "keyboard.h"
#include <stdlib.h>

static void Draw(Keyboard *self) {
    for(int i = 0; i < LETTER_COUNT; i++) {
        self->letters[i].Draw(&self->letters[i]);
    }
}

Keyboard KeyboardCtr() {
    Keyboard board = {
        .Draw = Draw,
        .letters = malloc(sizeof(Letter)*LETTER_COUNT),
    };

    for(int i = 0; i < LETTER_COUNT; i++) {
        board.letters[i] = LetterCtr('A' + i, (Vector2){7 + i%(LETTER_COUNT/2), 18 + (i/(LETTER_COUNT/2))});
    }

    return board;
}