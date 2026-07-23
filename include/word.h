#ifndef _WORD_H_
#define _WORD_H_

#include <stdint.h>

typedef struct Word {
    const char *word;
    uint8_t size;
    uint8_t guessed;
    void (*Draw)(struct Word *self);
} Word;

Word WordCtr(const char *str);

#endif // _WORD_H_