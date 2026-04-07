#include "logic.h"

void init_board(int board[WIDTH][HEIGHT]) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            board[x][y] = 0;
        }
    }
}

int wrap_index(int value, int limit) {
    int result = value;
    if (value < 0) {
        result = limit - 1;
    } else if (value >= limit) {
        result = 0;
    }
    return result;
}

int count_neighbors(const int board[WIDTH][HEIGHT], int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0) {
                int nx = wrap_index(x + dx, WIDTH);
                int ny = wrap_index(y + dy, HEIGHT);
                if (board[nx][ny] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

int get_next_state(const int board[WIDTH][HEIGHT], int x, int y) {
    int neighbors = count_neighbors(board, x, y);
    int current = board[x][y];
    int next_state = 0;

    if (current == 1) {
        if (neighbors == 2 || neighbors == 3) {
            next_state = 1;
        }
    } else {
        if (neighbors == 3) {
            next_state = 1;
        }
    }
    return next_state;
}

void next_generation(int board[WIDTH][HEIGHT], int next[WIDTH][HEIGHT]) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            next[x][y] = get_next_state(board, x, y);
        }
    }
}

void copy_board(int dst[WIDTH][HEIGHT], int src[WIDTH][HEIGHT]) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            dst[x][y] = src[x][y];
        }
    }
}