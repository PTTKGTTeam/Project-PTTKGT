#include <bits/stdc++.h>
#include "maze.h"
#include "bfs.h"
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool BFS() {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == ex && y == ey) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (!visited[nx][ny] && maze[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}