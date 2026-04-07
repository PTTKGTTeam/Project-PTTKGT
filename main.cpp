#include <bits/stdc++.h>
#include "maze.h"
#include "dfs.h"
#include "bfs.h"
#include "output.h"
using namespace std;

int main() {
    inputMaze();

    cout << "\nDFS:\n";
    memset(visited, false, sizeof(visited));
    if (DFS(sx, sy)) printPath();
    else cout << "Khong tim thay duong\n";

    cout << "\nBFS:\n";
    memset(visited, false, sizeof(visited));
    if (BFS()) printPath();
    else cout << "Khong tim thay duong\n";

    return 0;
}