#ifndef MAZE_H
#define MAZE_H

#include <utility>
using namespace std;

const int N = 100;

extern int maze[N][N];
extern bool visited[N][N];
extern pair<int,int> parent[N][N];

extern int n, m;
extern int sx, sy, ex, ey;

void inputMaze();

#endif