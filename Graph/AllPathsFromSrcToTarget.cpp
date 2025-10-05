#include<bits/stdc++.h>
using namespace std;
vector<list<int>> gp;
void add_edge(int src , int dst){
    gp[src].push_back(dst);
}
void display(){
    for (int i = 0; i < gp.size(); i++){
        cout << i << "-->";
        for(int ele : gp[i]){
            cout << ele << ",";
        }
        cout << endl;
    }
}
void dfs(int src , int target, vector<int>&res, vector<vector<int>>&ans){
    res.push_back(src);
    if(src == target){
        ans.push_back(res);
        res.pop_back();
        return;
    }
    for(auto neigh : gp[src]){
        dfs(neigh, target, res, ans);   
    }
    res.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size();
    gp.resize(n, list<int>());
    for (int i = 0; i < graph.size(); i++)
    {
        for(int ele : graph[i]){
            add_edge(i, ele);
        }
    }
    // display();
    vector<int> res;
    vector<vector<int>> ans;
    dfs(0, n - 1,res,ans);

        return ans;
}

int main(){
    // vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
     allPathsSourceTarget(graph);
    return 0;
}