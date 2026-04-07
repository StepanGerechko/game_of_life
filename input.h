#ifndef INPUT_H
#define INPUT_H

#include "game_of_life.h"

void setup_terminal(void);
void restore_terminal(void);
int read_board(int board[WIDTH][HEIGHT]);
int read_key(void);
void update_delay(int key, int *delay, int *running);

#endif