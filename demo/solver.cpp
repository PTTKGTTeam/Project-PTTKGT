#include "solver.h"

vector<pair<int,int>> solve(vector<int> nums){

    a.assign(n,vector<int>(m));

    int idx=0;
    pair<int,int> start;
    vector<pair<int,int>> blackPoints;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=nums[idx++];
            if(a[i][j]==2) start={i,j};
            if(a[i][j]==3) blackPoints.push_back({i,j});
        }
    }

    vector<vector<pair<int,int>>> choices;

    for(auto p:blackPoints){
        vector<pair<int,int>> adj;
        for(int i=0;i<4;i++){
            int nx=p.first+dx[i];
            int ny=p.second+dy[i];

            if(valid(nx,ny) && a[nx][ny]==0){
                adj.push_back({nx,ny});
            }
        }
        if(adj.empty()) return {};
        choices.push_back(adj);
    }

    int bestCost = 1e9;
    vector<pair<int,int>> bestPath;
    vector<pair<int,int>> curChoice;

    function<void(int)> gen = [&](int idx){
        if(idx==choices.size()){
            vector<pair<int,int>> pts;
            pts.push_back(start);
            for(auto p:curChoice) pts.push_back(p);

            int k = pts.size();
            vector<int> perm(k-1);
            iota(perm.begin(),perm.end(),1);

            do{
                int cost=0;
                int cur=0;
                vector<pair<int,int>> full;

                for(int i=0;i<perm.size();i++){
                    auto path = bfs(pts[cur], pts[perm[i]]);
                    if(path.empty()) return;

                    cost += path.size();
                    full.insert(full.end(), path.begin(), path.end());
                    cur = perm[i];
                }

                auto back = bfs(pts[cur], pts[0]);
                if(back.empty()) return;

                cost += back.size();
                full.insert(full.end(), back.begin(), back.end());

                if(cost < bestCost){
                    bestCost = cost;
                    bestPath = full;
                }

            }while(next_permutation(perm.begin(),perm.end()));

            return;
        }

        for(auto p:choices[idx]){
            curChoice.push_back(p);
            gen(idx+1);
            curChoice.pop_back();
        }
    };

    gen(0);
    return bestPath;
}