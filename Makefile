CC = gcc
CFLAGS = -Wall -Wextra -O2
DEBUG_FLAGS = -Wall -Wextra -g

SRC = main.c parser.c exec.c
OBJ = $(SRC:.c=.o)
EXEC = shell

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Debug target built with memory debugging symbols (for valgrind)
debug:
	$(CC) $(DEBUG_FLAGS) -o $(EXEC) $(SRC)

%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) *.o

.PHONY: all clean debug
