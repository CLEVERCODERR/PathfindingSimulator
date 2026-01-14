#include <iostream>
#include "Grid.h"
#include "Algorithms.h"

int main() {
    Grid grid(10, 20);

    for (int i = 4; i < 15; i++) {
        grid.setWall(5, i);
    }

    std::cout << "Dijkstra:\n";
    runDijkstra(grid);
    grid.print();

    grid.resetVisited();

    std::cout << "\nA* Search:\n";
    runAStar(grid);
    grid.print();

    return 0;
}
