#include "Grid.h"
#include <iostream>

Grid::Grid(int r, int c) : rows(r), cols(c) {
    grid.resize(rows, std::vector<Cell>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
        }
    }
}

void Grid::setWall(int r, int c) {
    grid[r][c].isWall = true;
}

void Grid::setStart(int r, int c) {
    grid[r][c].distance = 0;
}

void Grid::setEnd(int r, int c) {
    
}

bool Grid::inBounds(int r, int c) const {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

Cell& Grid::getCell(int r, int c) {
    return grid[r][c];
}

std::pair<int, int> Grid::getStart() const {
    return { 0, 0 };
}

std::pair<int, int> Grid::getEnd() const {
    return { rows - 1, cols - 1 };
}

void Grid::resetVisited() {
    for (auto& row : grid) {
        for (auto& cell : row) {
            cell.visited = false;
            cell.distance = -1;
        }
    }
}

void Grid::print() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell.isWall)
                std::cout << "# ";
            else if (cell.visited)
                std::cout << ". ";
            else
                std::cout << "  ";
        }
        std::cout << "\n";
    }
}

int Grid::getRows() const { return rows; }
int Grid::getCols() const { return cols; }
