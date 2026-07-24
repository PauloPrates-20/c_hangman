#include "game.h"
#include "config.h"

static void Update(Game *self) {
    if(self->running) {
        self->board.Update(&self->board);
    
        if(self->board.selected != '\0') {
            bool found = self->word.Check(&self->word, self->board.selected);

            if(self->word.complete) {
                self->running = false;
                return;
            }
    
            if(!found) {
                self->hang.state++;

                if(self->hang.state == DEAD) {
                    self->running = false;
                }
            }
    
            self->board.selected = '\0';
        }
    }
}

static void Draw(Game *self) {
    self->hang.Draw(&self->hang);
    self->word.Draw(&self->word);
    self->board.Draw(&self->board);

    if(!self->running) {
        DrawText(
            self->word.complete ? "WELL DONE!!!" : "YOU LOST!!!",
            5*CELL_SIZE + OFFSET/2,
            2*CELL_SIZE + OFFSET/2,
            50,
            SPRITE_GREEN
        );
    }
}

Game GameCtr(const char *word) {
    return (Game){
        .hang = HangCtr(),
        .word = WordCtr(word),
        .board = KeyboardCtr(),
        .running = true,
        .Update = Update,
        .Draw = Draw,
    };
}