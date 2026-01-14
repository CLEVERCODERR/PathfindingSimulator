#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Cell.h"

class Grid {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> grid;

public:
    Grid(int r, int c);

    void setWall(int r, int c);
    void setStart(int r, int c);
    void setEnd(int r, int c);

    bool inBounds(int r, int c) const;
    Cell& getCell(int r, int c);

    std::pair<int, int> getStart() const;
    std::pair<int, int> getEnd() const;

    void resetVisited();
    void print() const;

    int getRows() const;
    int getCols() const;
};

#endif
