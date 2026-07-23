#ifndef _HANG_H_
#define _HANG_H_

#include "raylib.h"
#include <stdint.h>

#define HANG_SPRITES 8

typedef enum HangState {
    EMPTY,
    HEAD,
    BODY,
    L_LEG,
    R_LEG,
    L_ARM,
    R_ARM,
    DEAD,
} HangState;

typedef struct Hang {
    Texture2D *sprites;
    HangState state;
    void (*Draw)(struct Hang *self);
} Hang;

Hang HangCtr();
void HangDstr(Hang *hang);

#endif // _HANG_H_