#ifndef CELL_H
#define CELL_H

struct Cell {
    int row;
    int col;
    bool isWall = false;
    bool visited = false;
    int distance = -1;
};

#endif
