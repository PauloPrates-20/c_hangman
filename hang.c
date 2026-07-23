#include "hang.h"
#include "config.h"
#include <stdlib.h>
#include <stdio.h>

static void Draw(Hang *self) {
    DrawTexture(self->sprites[self->state], 1*CELL_SIZE + OFFSET/2, 2*CELL_SIZE + OFFSET/2, WHITE);
}

Hang HangCtr() {
    Texture2D *sprite_buffer = malloc(sizeof(Texture2D)*HANG_SPRITES);
    char path[25];

    for(uint8_t i = 0; i < HANG_SPRITES; i++) {
        sprintf(path, "assets/hangman%d.png", i);
        Image img = LoadImage(path);
        sprite_buffer[i] = LoadTextureFromImage(img);
        UnloadImage(img);
    }

    return (Hang) {
        .sprites = sprite_buffer,
        .state = EMPTY,
        .Draw = Draw,
    };
}

void HangDstr(Hang *hang) {
    for(uint8_t i = 0; i < HANG_SPRITES; i++) {
        UnloadTexture(hang->sprites[i]);
    }

    free(hang->sprites);
}