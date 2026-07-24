#ifndef _GAME_H_
#define _GAME_H_

#include "keyboard.h"
#include "word.h"
#include "hang.h"

typedef struct Game {
    Hang hang;
    Word word;
    Keyboard board;
    bool running;
    void (*Update)(struct Game *self);
    void (*Draw)(struct Game *self);
} Game;

Game GameCtr(const char *word);

#endif // _GAME_H_