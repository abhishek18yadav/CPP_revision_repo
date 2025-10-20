#include<bits/stdc++.h>
using namespace std;

vector<list<int>> gp;
void add_Edge(int src , int dst){
    gp[src].push_back(dst);
}
void display(){
    for (int i = 0; i < gp.size(); i++){
        cout << i << "-->";
        for(auto ele : gp[i]){
            cout << ele << " ";
        }
        cout << endl;
    }
}
void totalZeroIndegreevertices(unordered_map<int, int> &indegree){
    for (int i = 0; i < gp.size(); i++){
        for(auto ele : gp[i]){
            indegree[ele]++;
        }
    }
}


vector<int>findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    gp.resize(n, list<int>());
    for (int i = 0; i < edges.size(); i++){
        int src = edges[i][0];
        int dst = edges[i][1];
        add_Edge(src, dst);
    }
    unordered_map<int, int> indegree;
    totalZeroIndegreevertices(indegree);
    vector<int> res;
    for (int i = 0; i < n; i++){
        if(indegree[i]==0)
            res.push_back(i);
        
    }
    for(int ele : res)
        cout << ele << " ";
    return res;
}
int main(){
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    findSmallestSetOfVertices(n, edges);
    return 0;
}