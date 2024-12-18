CC = gcc
CFLAGS = -Wall -g
TARGET = dungeon
OBJS = game.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean