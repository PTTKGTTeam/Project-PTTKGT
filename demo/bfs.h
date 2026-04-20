#ifndef BFS_H
#define BFS_H
#include "matrix.h"
#include <iostream>
using namespace std;
struct Nodes {
    int x, y, dist;
};


void bfs(int map[][4], Node b, int i, int j);

#endif // BFS_H