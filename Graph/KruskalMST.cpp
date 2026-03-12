
#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int dest;
    int wt;
};
bool cmp(Edge e1 , Edge e2){
    return e1.wt < e2.wt;
}
int find(vector<int>&parent , int node){
    return (parent[node] == node) ? node : find(parent , parent[node]);
}
void Union(vector<int>&parent , vector<int>&rank , int nodeA , int nodeB){
    int parA = find(parent , nodeA);
    int parB = find(parent , nodeB);
    if(parA == parB)return;
    else{
        if(rank[parA] > rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        }
        else{
            parent[parA] = parB;
            rank[parB]++;
        }
    }
    return;
}
void kruskal(vector<Edge>&input , int n, int e){
    sort(input.begin(),input.end(), cmp);
    vector<int>parent(n+1);// initially every node will be parent of themselves
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
    vector<int>rank(n+1,0);// every node will have equal rank
    int edgeCount = 0;
    int i = 0;
    int res = 0;// store wt of final spanning tree
    while(edgeCount < (n-1) && i<input.size()){
        Edge curr = input[i];
        cout<<curr.src<<" "<<curr.dest<<" "<<curr.wt<<endl;
        int srcParent = find(parent, curr.src);
        int destParent = find(parent, curr.dest);
        if(srcParent != destParent){
            Union(parent,rank,srcParent,destParent);
            res += curr.wt;
            edgeCount++;
        }
        i++;
    }
    cout<<"res of mst is "<<res;
}
int main(){
    // int n,e;
    // vector<Edge>input;
    // for(int i=0; i<e; i++){
    //     int src,dst,wt;
    //     cin>>src;
    //     cin>>dest;
    //     cin>>wt;
    //     input[i].src = src;
    //     input[i].dest = dest;
    //     input[i].wt = wt;
    // }
    int n=5,e = 7;
    vector<Edge>input{{0,1,1}, {1,2,2}, {2,3,9}, {1,3,8}, {0,3,9}, {3,4,3}, {0,4,10}};
    kruskal(input, n, e);
    return 0;
}