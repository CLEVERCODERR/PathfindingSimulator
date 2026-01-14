#include "Algorithms.h"
#include <queue>
#include <stack>
#include <cmath>

struct Node {
    Cell* cell;
    int cost;

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

static int manhattan(Cell* a, Cell* b) {
    return abs(a->row - b->row) + abs(a->col - b->col);
}

void runDijkstra(Grid& grid) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    Cell& start = grid.getCell(0, 0);
    Cell& end = grid.getCell(grid.getRows() - 1, grid.getCols() - 1);

    start.distance = 0;
    pq.push({ &start, 0 });

    int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

    while (!pq.empty()) {
        Cell* curr = pq.top().cell;
        pq.pop();

        if (curr->visited) continue;
        curr->visited = true;

        if (curr == &end) break;

        for (auto& d : dirs) {
            int nr = curr->row + d[0];
            int nc = curr->col + d[1];

            if (!grid.inBounds(nr, nc)) continue;

            Cell& next = grid.getCell(nr, nc);
            if (next.isWall) continue;

            int newDist = curr->distance + 1;
            if (newDist < next.distance) {
                next.distance = newDist;
                next.parent = curr;
                pq.push({ &next, newDist });
            }
        }
    }
}

void runAStar(Grid& grid) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    Cell& start = grid.getCell(0, 0);
    Cell& end = grid.getCell(grid.getRows() - 1, grid.getCols() - 1);

    start.distance = 0;
    pq.push({ &start, manhattan(&start, &end) });

    int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

    while (!pq.empty()) {
        Cell* curr = pq.top().cell;
        pq.pop();

        if (curr->visited) continue;
        curr->visited = true;

        if (curr == &end) break;

        for (auto& d : dirs) {
            int nr = curr->row + d[0];
            int nc = curr->col + d[1];

            if (!grid.inBounds(nr, nc)) continue;

            Cell& next = grid.getCell(nr, nc);
            if (next.isWall) continue;

            int g = curr->distance + 1;
            int h = manhattan(&next, &end);

            if (g < next.distance) {
                next.distance = g;
                next.parent = curr;
                pq.push({ &next, g + h });
            }
        }
    }
}
