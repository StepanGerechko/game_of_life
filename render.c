#include "render.h"
#include <ncurses.h>

void clear_screen(void) {
    erase();
}

void print_board(const int board[WIDTH][HEIGHT], int delay) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printw("%d", board[x][y]);
        }
        printw("\n");
    }
    printw("Delay: %d ms | A: Faster | Z: Slower | Space: Exit\n", delay);
    refresh();
}