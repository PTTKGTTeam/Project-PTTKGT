#include <queue>
#include "bfs.h"
#include <iostream>
#include <fstream>
using namespace std;

void bfs(int map[][4], Node b, int i, int j) {
    // đọc bản đồ từ file map.txt
    ifstream fin("map.txt");
    int a[5][5];
    //cout << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fin >> a[i][j];
            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }

    // BFS để tìm đường đi ngắn nhất từ B[i] đến B[j]
    queue<Nodes> q;
    bool visited[5][5] = {false};

    q.push({b.x, b.y, 0});
    visited[b.x][b.y] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        Nodes cur = q.front(); q.pop();
        if (cur.x==b.x && cur.y==b.y) {
            for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

                if (nx >= 0 && nx < 5 && ny >= 0 && ny < 10 &&
                    !visited[nx][ny] && a[nx][ny] != 1) {

                    visited[nx][ny] = true;
                    q.push({nx, ny, cur.dist + 1});
                }
            }
            continue;
        }
        if (a[cur.x][cur.y] == 2) {
            map[i][j] = map[j][i] = cur.dist; // lưu khoảng cách vào ma trận file matrix.txt
            //cout << "So buoc ngan nhat: " << cur.dist << endl;
            return;
        }

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 10 &&
                !visited[nx][ny] && a[nx][ny] != 1) {

                visited[nx][ny] = true;
                q.push({nx, ny, cur.dist + 1});
            }
        }
    }

    cout << "Khong tim thay duong!\n";
}