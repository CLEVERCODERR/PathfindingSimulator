#include "Algorithms.h"
#include <queue>
#include <stack>

void runBFS(Grid& grid) {
    std::queue<Cell*> q;

    auto start = grid.getStart();
    Cell& startCell = grid.getCell(start.first, start.second);

    startCell.visited = true;
    q.push(&startCell);

    int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

    while (!q.empty()) {
        Cell* curr = q.front();
        q.pop();

        for (auto& d : dirs) {
            int nr = curr->row + d[0];
            int nc = curr->col + d[1];

            if (!grid.inBounds(nr, nc))
                continue;

            Cell& next = grid.getCell(nr, nc);
            if (next.visited || next.isWall)
                continue;

            next.visited = true;
            q.push(&next);
        }
    }
}

void runDFS(Grid& grid) {
    std::stack<Cell*> st;

    auto start = grid.getStart();
    Cell& startCell = grid.getCell(start.first, start.second);

    startCell.visited = true;
    st.push(&startCell);

    int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

    while (!st.empty()) {
        Cell* curr = st.top();
        st.pop();

        for (auto& d : dirs) {
            int nr = curr->row + d[0];
            int nc = curr->col + d[1];

            if (!grid.inBounds(nr, nc))
                continue;

            Cell& next = grid.getCell(nr, nc);
            if (next.visited || next.isWall)
                continue;

            next.visited = true;
            st.push(&next);
        }
    }
}