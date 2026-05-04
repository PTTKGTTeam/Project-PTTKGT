#include "bfs.h"
#include "grid.h"

vector<pair<int,int>> bfs(pair<int,int> s, pair<int,int> t){
    queue<pair<int,int>> q;
    map<pair<int,int>, pair<int,int>> parent;
    map<pair<int,int>, bool> vis;

    q.push(s);
    vis[s]=true;

    while(!q.empty()){
        auto u=q.front(); q.pop();

        if(u==t){
            vector<pair<int,int>> path;
            while(u!=s){
                path.push_back(u);
                u=parent[u];
            }
            path.push_back(s);
            reverse(path.begin(),path.end());
            return path;
        }

        for(int i=0;i<4;i++){
            int nx=u.first+dx[i];
            int ny=u.second+dy[i];

            if(valid(nx,ny) && !vis[{nx,ny}]){
                vis[{nx,ny}]=true;
                parent[{nx,ny}]=u;
                q.push({nx,ny});
            }
        }
    }
    return {};
}

int dist(pair<int,int> a, pair<int,int> b){
    auto p = bfs(a,b);
    if(p.empty()) return 1e9;
    return p.size();
}