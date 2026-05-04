#include "grid.h"

int n=12,m=24;
vector<vector<int>> a;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && (a[x][y]==0 || a[x][y]==2);
}