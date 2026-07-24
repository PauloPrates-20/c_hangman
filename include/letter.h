#ifndef _LETTER_H_
#define _LETTER_H_

#include "raylib.h"

typedef struct Letter {
    char value;
    Vector2 pos;
    Rectangle rec;
    bool active;
    void (*Draw)(struct Letter *self);
} Letter;

Letter LetterCtr(char value, Vector2 pos);

#endif // _LETTER_H_