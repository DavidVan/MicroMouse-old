#include <stdlib.h>
#include <stdio.h>

#include "Block.h"
#include "MazeSolver.h"

int main(int argc, char** arcv) {
    printf("Hello %d\n", sizeof(struct Block));
    struct Block maze[16][16];
    initializeMaze(&maze);
    printf("Maze initialized\n");
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("i: %d, j: %d\nNorth Wall: %d, South Wall: %d, East Wall: %d, West Wall: %d\nDistance: %d, Visited: %d\n\n", i, j, maze[i][j].northWall, maze[i][j].southWall, maze[i][j].eastWall, maze[i][j].westWall, maze[i][j].distance, maze[i][j].visited);
        }
    }
    printDistance(&maze);
    return 0;
}
