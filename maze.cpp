#include <bits/stdc++.h>
#include "maze.h"
using namespace std;

int maze[N][N];
bool visited[N][N];
pair<int,int> parent[N][N];

int n, m;
int sx, sy, ex, ey;

void inputMaze() {
    cout << "Nhap n, m: ";
    cin >> n >> m;

    cout << "Nhap ma tran:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    cout << "Nhap start: ";
    cin >> sx >> sy;

    cout << "Nhap end: ";
    cin >> ex >> ey;
}