CC=gcc
CCFLAGS=-Wall

SRCS=src/*.c src/elements/*.c
HEADERS=src/*.h

powdr: $(SRCS) $(HEADERS)
	$(CC) $(SRCS) -o $@ -lm -lSDL2

clean:
	rm -f powdr
