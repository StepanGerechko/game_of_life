#ifndef LOGIC_H
#define LOGIC_H

#include "game_of_life.h"

void init_board(int board[WIDTH][HEIGHT]);
int wrap_index(int value, int limit);
int count_neighbors(const int board[WIDTH][HEIGHT], int x, int y);
int get_next_state(const int board[WIDTH][HEIGHT], int x, int y);
void next_generation(int board[WIDTH][HEIGHT], int next[WIDTH][HEIGHT]);
void copy_board(int dst[WIDTH][HEIGHT], int src[WIDTH][HEIGHT]);

#endif