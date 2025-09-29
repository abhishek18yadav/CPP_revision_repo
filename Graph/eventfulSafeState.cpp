#include<bits/stdc++.h>
using namespace std;

vector<list<int>> gp;
void add_edge(int src, int dst){
    gp[src].push_back(dst);
}

void display()
{
    for (int i = 0; i < gp.size(); i++)
    {
        cout << i << "->";
        for (auto ele : gp[i])
        {
            cout<<ele<<" ";
        }
        cout << endl;
    }
}
int dfs(int node, vector<bool>&instack, unordered_set<int>&vis){
    if(instack[node]){
        //if it is in cycle, then it will be in instack
        return true;
    }
    if(vis.count(node)){
        //if visited and not in stack , that means node is safe
        return false;
    }
    //if new node
    vis.insert(node);
    instack[node] = true;
    for(auto neigh : gp[node]){
        int ans =dfs(neigh, instack, vis);
        if(ans)
            return true;
    }
    instack[node] = false;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    gp.resize(n, list<int>());
    for (int i = 0; i < n; i++){
        for(auto ele : graph[i]){
            add_edge(i, ele);
        }
    }
    // display();
    unordered_set<int> vis;
    vector<bool> instack(n);
    for (int i = 0; i < n; i++){
        dfs(i, instack, vis);
    }
    vector<int> res;
    for (int i = 0; i < n; i++){
        if(!instack[i])
            res.push_back(i);
    }
    return res;
    
}
int main(){
    vector<vector<int>> graph{{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> res = eventualSafeNodes(graph);
   
    return 0;
}