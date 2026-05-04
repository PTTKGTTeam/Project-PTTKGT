#include "solver.h"

int main(){
    string input;
    getline(cin,input);

    vector<int> nums;
    for(char c:input){
        if(isdigit(c)) nums.push_back(c-'0');
    }

    auto path = solve(nums);

    cout<<"[";
    for(int i=0;i<path.size();i++){
        cout<<"["<<path[i].first<<","<<path[i].second<<"]";
        if(i!=path.size()-1) cout<<",";
    }
    cout<<"]";
}