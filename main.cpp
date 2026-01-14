#include <iostream>
#include "Grid.h"
#include "Algorithms.h"

int main() {
    Grid grid(10, 20);

    // add some walls
    for (int i = 5; i < 15; i++) {
        grid.setWall(4, i);
    }

    std::cout << "BFS Traversal:\n";
    runBFS(grid);
    grid.print();

    grid.resetVisited();

    std::cout << "\nDFS Traversal:\n";
    runDFS(grid);
    grid.print();

    return 0;
}
