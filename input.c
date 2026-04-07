#include "input.h"
#include <ncurses.h>
#include <stdio.h>

void setup_terminal(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
}

void restore_terminal(void) {
    endwin();
}

int read_board(int board[WIDTH][HEIGHT]) {
    int result = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (scanf("%d", &board[x][y]) != 1) {
                result = -1;
            }
        }
    }
    return result;
}

int read_key(void) {
    int key = getch();
    return key;
}

void update_delay(int key, int *delay, int *running) {
    if (key == 'a' || key == 'A') {
        *delay -= 10;
        if (*delay < 10) {
            *delay = 10;
        }
    } else if (key == 'z' || key == 'Z') {
        *delay += 10;
        if (*delay > 1000) {
            *delay = 1000;
        }
    } else if (key == ' ') {
        *running = 0;
    }
}