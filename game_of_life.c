#include "game_of_life.h"
#include "input.h"
#include "logic.h"
#include "render.h"

#include <ncurses.h>
#include <stdio.h>

int main(void) {
    int board[WIDTH][HEIGHT] = {0};
    int delay = 100;
    int running = 1;
    int read_status = 0;
    int tty_ok = 1;

    read_status = read_board(board);

    if (freopen("/dev/tty", "r", stdin) == NULL) {
        tty_ok = 0;
    }

    if (read_status != 0) {
        fprintf(stderr, "Error: failed to read board from stdin\n");
        return 1;
    }

    if (tty_ok == 0) {
        fprintf(stderr, "Error: failed to open /dev/tty for keyboard input\n");
        return 1;
    }

    int next[WIDTH][HEIGHT] = {0};
    setup_terminal();
    while (running == 1) {
        clear_screen();
        print_board(board, delay);
        int key = read_key();
        update_delay(key, &delay, &running);
        next_generation(board, next);
        copy_board(board, next);
        napms(delay);
    }
    restore_terminal();

    return 0;
}