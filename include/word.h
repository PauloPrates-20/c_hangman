#ifndef _WORD_H_
#define _WORD_H_

#include <stdint.h>

typedef struct Word {
    const char *word;
    uint8_t size;
    uint16_t guessed;
    bool complete;
    void (*Draw)(struct Word *self);
    bool (*Check)(struct Word *self, char value);
} Word;

Word WordCtr(const char *str);

#endif // _WORD_H_