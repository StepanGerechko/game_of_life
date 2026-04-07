CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -I.
LDFLAGS = -lncurses

BUILD_DIR = build
TARGET = $(BUILD_DIR)/game_of_life

SRCS = game_of_life.c logic.c render.c input.c
HEADERS = game_of_life.h logic.h render.h input.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) -o $(TARGET)

clean:
	rm -rf $(BUILD_DIR)