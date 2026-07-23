#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "letter.h"

#define LETTER_COUNT 26

typedef struct Keyboard {
    Letter *letters;
    void (*Draw)(struct Keyboard *self);
    void (*Update)(struct Keyboard *self);
} Keyboard;

Keyboard KeyboardCtr();
void KeyboardDstr(Keyboard *board);

#endif // _KEYBOARD_H_