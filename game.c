#include "game.h"

static void Update(Game *self) {
    self->board.Update(&self->board);

    if(self->board.selected != '\0') {
        bool found = self->word.Check(&self->word, self->board.selected);
        self->board.selected = '\0';
    }
}

static void Draw(Game *self) {
    self->hang.Draw(&self->hang);
    self->word.Draw(&self->word);
    self->board.Draw(&self->board);
}

Game GameCtr(const char *word) {
    return (Game){
        .hang = HangCtr(),
        .word = WordCtr(word),
        .board = KeyboardCtr(),
        .Update = Update,
        .Draw = Draw,
    };
}