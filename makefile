CC=gcc
CFLAGS=-c -std=c99 -Wall -pedantic -march=native -Ofast
LDFLAGS=
SRC=MazeSolver.c
OBJ=$(SRC:.c=.o)
EXE=MazeSolver

all: $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm *.o MazeSolver
