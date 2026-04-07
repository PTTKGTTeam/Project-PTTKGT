#include <bits/stdc++.h>
#include "maze.h"
#include "output.h"
using namespace std;

void printPath() {
    vector<pair<int,int>> path;
    int x = ex, y = ey;

    while (!(x == sx && y == sy)) {
        path.push_back({x, y});
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    path.push_back({sx, sy});

    reverse(path.begin(), path.end());

    cout << "Duong di:\n";
    for (auto p : path) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}