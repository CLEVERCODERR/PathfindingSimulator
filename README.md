# C++ Pathfinding Algorithms Visualizer

I made a console-based C++ project that demonstrates a graph and pathfinding algorithms in a grid-based environment. The program visualizes how different algorithms explore the grid and compute shortest paths while avoiding obstacles.

## Features
- Grid-based map representation
- Wall and obstacle handling
- Pathfinding algorithms:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Dijkstra’s Algorithm
  - A* Search (Manhattan heuristic)
- Path reconstruction using parent pointers
- Console-based visualization

## Technologies Used
- Language: C++
- Concepts: Data Structures & Algorithms
- STL: vectors, queues, stacks, priority_queue
- Paradigm: Object-Oriented Programming

## How It Works
- The grid is represented as a 2D vector of cells
- Each cell tracks distance, visited state, and parent
- Algorithms explore the grid step-by-step
- The final shortest path is reconstructed using parent pointers


## Algorithms Overview
- BFS: Unweighted shortest path
- DFS: Depth-first exploration
- Dijkstra: Weighted shortest path
- A*: Heuristic-based shortest path optimization
