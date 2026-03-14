#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pp pair<int,int>

vector<list<pp>> gp;// gp->graph

void addEdge(int src,int dst , int wt, bool bi_dir = true){
    gp[src].push_back({dst,wt});
    if(bi_dir){
        gp[dst].push_back({src,wt});
    }
}
void displayGraph(int n){
    for (int i = 0; i < n; i++){
        cout<<i<<"->";
        for(auto nbrs : gp[i]){
            cout<<"("<<nbrs.first<<","<<nbrs.second<<") ";
        }
        cout<<endl;
    }
}
void dijkstra(int src , int n){
    vector<int> via(n); // this is similar to parent in kruskal's algorithm
    unordered_map<int, int> mp;
    // this (map) is only different in dijkstra from prims because it store the distance of the node from the source node(i.e cummulative distance)
    for (int i = 0; i < n; i++){
        mp[i] = INT_MAX;
    }
    unordered_set<int> vis;
    mp[src] = 0;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0, src});
    int nodeCount = 0;
    int ttlWt = 0;
    while(!pq.empty() and nodeCount < n ){
        pp curr = pq.top();
        pq.pop();
        if(vis.count(curr.second)){
            continue;
        }
        vis.insert(curr.second);
        nodeCount++;
        ttlWt+=curr.first;
        cout<<curr.second<<" is selected with weight "<<curr.first<<endl;
        for(auto nbrs : gp[curr.second]){
            if(!vis.count(nbrs.first) and mp[nbrs.first] > nbrs.second + curr.first){
                mp[nbrs.first] = nbrs.second + curr.first;
                pq.push({mp[nbrs.first], nbrs.first});
                via[nbrs.first] = curr.second;
            }
        }
    }
    cout<<"Total weight of the MST is "<<ttlWt<<endl;
    cout<<"path selected for the MST is "<<endl;
    for (int i = 0; i < n; i++){
        cout<<i<<" via "<<via[i]<<endl;
    }
    return;
}

int main(){
    int n = 5, e = 7;
    gp.resize(n, list<pp>());
    addEdge(0, 1, 1);
    addEdge(0, 2, 9);
    addEdge(1, 2, 8);
    addEdge(1, 3, 2);
    addEdge(2, 3, 3);
    addEdge(2, 4, 9);
    addEdge(0, 4, 10);
    dijkstra(0, n);

    return 0;
}