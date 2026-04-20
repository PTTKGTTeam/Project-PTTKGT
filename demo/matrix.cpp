#include "matrix.h"
#include "bfs.h"
#include <queue>
#include <fstream>

void matrix(int a[][5], int map[][4]) {
    queue<Node> q;
    Node B[3];
    int c[5][5];
    int n=0;
    // tìm tất cả các điểm đích và lưu vào mảng B
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == 2) {
                B[n] = {i, j};
                q.push(B[n]);
                n=n+1;
            }
        }
    }
    // tạo mạng c giống a nhưng không có điểm đích
    for (int i = 0; i < 5; i++) {
       for (int j = 0; j < 5; j++) {
            if (a[i][j] == 2) {
                a[i][j] = 0;
            }
            c[i][j]=a[i][j];
        }
    }
    // xét từng cặp đích B[i] và B[j]
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {

            // lưu bản đồ mảng c cùng với từng cặp điểm vào file map.txt để hàm bfs đọc
            ofstream fout("map.txt");
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    if (k == B[i].x && l == B[i].y) {
                        c[k][l] = 2;
                        fout << c[k][l] << " ";
                        c[k][l] = 0;
                    } else if (k == B[j].x && l == B[j].y) {
                        c[k][l] = 2;
                        fout << c[k][l] << " ";
                        c[k][l] = 0;
                    } else {
                        fout << c[k][l] << " ";
                    }

                }
                fout << endl;
            }
            fout.close();

            // hàm tính khoảng cách giữa B[i] và B[j];
            bfs(map, B[i], i, j);
            
        }
        // in vô mảng matrx[i][j] = khoảng cách giữa B[i] và B[j]
    }
}
