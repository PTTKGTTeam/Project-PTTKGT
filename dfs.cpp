#include <bits/stdc++.h>
#include "maze.h"
#include "dfs.h"
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool DFS(int x, int y) {
    visited[x][y] = true;

    if (x == ex && y == ey) return true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (!visited[nx][ny] && maze[nx][ny] == 0) {
                parent[nx][ny] = {x, y};
                if (DFS(nx, ny)) return true;
            }
        }
    }
    return false;
}