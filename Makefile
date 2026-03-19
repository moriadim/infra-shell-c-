CC = gcc
CFLAGS = -Wall -Wextra -g

all: shell

shell: main.c
	$(CC) $(CFLAGS) -o shell main.c

clean:
	rm -f shell *.o

.PHONY: all clean
