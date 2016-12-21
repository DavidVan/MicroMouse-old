#ifndef BLOCK_H
#define BLOCK_H

#include <stdbool.h>

struct Block {
    bool northWall;
    bool southWall;
    bool eastWall;
    bool westWall;
    int distance;
    bool visited;
};

#endif
