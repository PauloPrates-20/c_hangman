#include "keyboard.h"
#include <stdlib.h>
#include <stdio.h>

static void Draw(Keyboard *self) {
    for(int i = 0; i < LETTER_COUNT; i++) {
        self->letters[i].Draw(&self->letters[i]);
    }
}

static void Update(Keyboard *self) {
    static bool check = false;

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        check = true;
        return;
    }

    if(check) {
        for(int i = 0; i < LETTER_COUNT; i++) {
            if(self->letters[i].active && CheckCollisionPointRec(GetMousePosition(), self->letters[i].rec)) {
                self->letters[i].active = false;
                self->selected = self->letters[i].value;
            }
        }
        check = false;
    }
}

Keyboard KeyboardCtr() {
    Keyboard board = {
        .Draw = Draw,
        .Update = Update,
        .letters = malloc(sizeof(Letter)*LETTER_COUNT),
        .selected = '\0',
    };

    for(int i = 0; i < LETTER_COUNT; i++) {
        board.letters[i] = LetterCtr('A' + i, (Vector2){1 + i%(LETTER_COUNT/2), 11 + (i/(LETTER_COUNT/2))});
    }

    return board;
}

void KeyboardDstr(Keyboard *board) {
    free(board->letters);
    board->letters = NULL;
}