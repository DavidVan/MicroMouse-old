#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include <stdlib.h>
#include <stdbool.h>

void initializeMaze(struct Block (*)[][16]);
void calculateMazeDistance(struct Block (*)[][16]);
void flood(struct Block (*)[][16]);
int manhattanDistance(int, int, int, int);
int minimum(int, int, int, int);
void printDistance(struct Block (*)[][16]);

void initializeMaze(struct Block (*maze)[16][16]) { // Make sure all four sides of maze have walls.
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (i == 0 || i == 15 || j == 0 || j == 15) {
                if (i == 0) { // Top of maze.
                    (*maze)[i][j].northWall = true;
                    (*maze)[i][j].southWall = false;
                }
                else if(i == 15) { // Bottom of maze.
                    (*maze)[i][j].northWall = false;
                    (*maze)[i][j].southWall = true;
                }
                else {
                    (*maze)[i][j].northWall = false;
                    (*maze)[i][j].southWall = false;
                }
                if (j == 0) { // Left of maze.
                    (*maze)[i][j].eastWall = false;
                    (*maze)[i][j].westWall = true;
                }
                else if (j == 15) { // Right of maze.
                    (*maze)[i][j].eastWall = true;
                    (*maze)[i][j].westWall = false;
                }
                else {
                    (*maze)[i][j].eastWall = false;
                    (*maze)[i][j].westWall = false;
                }
                (*maze)[i][j].distance = -1;
            }
            else if ((i == 7 || i == 8) && (j == 7 || j == 8)) { // Center of maze.
                (*maze)[i][j].northWall = false;
                (*maze)[i][j].southWall = false;
                (*maze)[i][j].eastWall = false;
                (*maze)[i][j].westWall = false;
                (*maze)[i][j].distance = 0;
            }
            else { // Other areas of maze.
                (*maze)[i][j].northWall = false;
                (*maze)[i][j].southWall = false;
                (*maze)[i][j].eastWall = false;
                (*maze)[i][j].westWall = false;
                (*maze)[i][j].distance = -1;
            }
            (*maze)[i][j].visited = false;
        }
    }
    calculateMazeDistance(maze);
}

void calculateMazeDistance(struct Block (*maze)[16][16]) {
    // Objective is (7, 7), (7, 8), (8, 7), or (8, 8).
    // Calculate manhattan distance and use shortest one.
    int cornerOne = 7;
    int cornerTwo = 8;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            (*maze)[i][j].distance = minimum(
                                        manhattanDistance(i, j, cornerOne, cornerOne),
                                        manhattanDistance(i, j, cornerOne, cornerTwo),
                                        manhattanDistance(i, j, cornerTwo, cornerOne),
                                        manhattanDistance(i, j, cornerTwo, cornerTwo)
                                        );
        }
    }
}

void flood(struct Block (*maze)[16][16]) {

}

int manhattanDistance(int currentX, int currentY, int objectiveX, int objectiveY) {
    return abs(currentX - objectiveX) + abs(currentY - objectiveY);
}

int minimum(int a, int b, int c, int d) {
    int minimum = a;
    if (b < minimum) {
        minimum = b;
    }
    if (c < minimum) {
        minimum = c;
    }
    if (d < minimum) {
        minimum = d;
    }
    return minimum;
}

void printDistance(struct Block (*maze)[16][16]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if ((*maze)[i][j].distance >= 10) {
                printf("%d ", (*maze)[i][j].distance);
            }
            else {
                printf(" %d ", (*maze)[i][j].distance);
            }
        }
        printf("\n");
    }
}

#endif
