#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> cst;

int f(int r , int c , int prev_col){
    if(r >= cst.size())
        return 0;
    int ans = INT_MAX;
    for (int i = 0; i < cst[r].size(); i++){
        if(i==prev_col)
            continue;
        ans = min(ans, cst[r][i] + f(r + 1, c, i));
    }
    return ans;
}
int minCost(vector<vector<int>>&costs){
    cst = costs;
    return f(0, 0, -10);
}
int main(){
    // vector<vector<int>> costs = {{17,2,17},{16,16,5},{14,3,19}}; // case 1
    // vector<vector<int>> costs = {{7,6,2},{5,8,6},{7,2,8}}; // case 2
    vector<vector<int>> costs = {{1,2,3},{1,4,6}}; // case 3
    cout<<minCost(costs);
    return 0;
}