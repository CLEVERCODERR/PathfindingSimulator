#ifndef CELL_H
#define CELL_H

struct Cell {
    int row;
    int col;

    bool isWall = false;
    bool visited = false;

    int distance = 1e9;      // for Dijkstra / A*
    int h = 0;       // for A*
    Cell* parent = nullptr;  // for path reconstruction
};

#endif
