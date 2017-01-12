CC=g++
CFLAGS=-c -std=c++1y -Wall -pedantic -march=native -Ofast
LDFLAGS=
SRC=MazeSolver.cpp
OBJ=$(SRC:.cpp=.o)
EXE=MazeSolver

all: $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm *.o MazeSolver
