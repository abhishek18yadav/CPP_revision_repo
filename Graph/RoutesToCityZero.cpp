#include<bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
vector<list<pp>> gp;

void addEdge(int src, int dst , bool isPres = true, bool bi_dir=true){
    gp[src].push_back({dst, isPres});
    if(bi_dir){
        gp[dst].push_back({src, !isPres});
    }
}
void display(){
    for (int i = 0; i < gp.size(); i++){
        cout << i << "-->";
        for(auto ele : gp[i]){
            cout << ele.first << ","<<ele.second<<"  ";
        }
        cout << "\n";
    }
}
int bfs(int src , unordered_set<int>&vis){
    queue<pp> que;
    que.push({src, 1});
    vis.insert(src);
    // que.push({NULL,NULL});
    int count = 0;
    while(!que.empty()){
        pp node = que.front();
        que.pop();
        // if(node.first == NULL){
        //     cout << "level crossed" << endl;
        //     if(!que.empty()){
        //         que.push({NULL, NULL});
        //     }
        //     continue;
        // }
        for(auto neigh : gp[node.first]){
            if(!vis.count(neigh.first)){
                vis.insert(neigh.first);
                if(neigh.second)// if true then reverse edge is not possibe and thats what we want
                    count++;
                que.push({neigh.first, neigh.second});
            }
        }
    }
    // cout << count;
    return count;
}
int minReorder(int n, vector<vector<int>> &connections)
{
    for (int i = 0; i < connections.size(); i++){
        addEdge(connections[i][0], connections[i][1], true);
    }
    // display();
    unordered_set<int> vis;
    return bfs(0, vis);
}

int main(){
    int n = 3;
    gp.resize(n ,list<pp>());
    // vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    // vector<vector<int>> connections = {{1,0},{1,2},{3,2},{3,4}};
    vector<vector<int>> connections = {{1,0},{2,0}};
    minReorder(n, connections);
    return 0;
}