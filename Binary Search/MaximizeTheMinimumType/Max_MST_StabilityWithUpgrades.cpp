#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++)parent[i] = i;
    }
    int find(int a){
        return (parent[a] == a) ? a : find(parent[a]);
    }
    void Union(int a , int b){
        int parA = find(a);
        int parB = find(b);
        if(parA != parB){
            if(rank[parA] > rank[parB]){
                parent[parB] = parA;
                rank[parA]++;
            }else{
                parent[parA] = parB;
                rank[parB]++;
            }
        }
        return;
    }
};

// bool check(vector<vector<int>>&edges , int k , int mid,int n){
//     DSU dsu(n);
//     vector<vector<int>>upgradingQueue;
//     for(auto e : edges){
        
//         int src = e[0];
//         int dst = e[1];
//         int s = e[2];
//         int mst = e[3];
//         if(mst == 1){
//             if(s < mid)return false;
//             dsu.Union(src,dst);
//         }else{
//             if(s >= mid){
//                 dsu.Union(src,dst);
//             }else{
//                 if(k == 0)return false;
//                 else if(2*s >= mid){
//                     upgradingQueue.push_back({src,dst});
//                 }
//             }
//         }
//     }
//     for(auto pir : upgradingQueue){
//         int s = pir[0];
//         int d = pir[1];
//         if(dsu.find(s) != dsu.find(d) ){
//             if (k == 0)return false;
//              else k--;
//             dsu.Union(s, d);
//         }
//     }
//     int rootParent  = dsu.find(0);
//     for(int i=1; i<n; i++)
//         if(dsu.find(i) != rootParent)return false;
//     return true;
// }
bool check( vector<vector<int>> &edges, int k, int mid , int n)
{
    DSU dsu(n);

    vector<vector<int>> upgradeCandidates;

    for (auto &edge : edges)
    { // E
        int u = edge[0];
        int v = edge[1];

        int s = edge[2];
        int m = edge[3];

        if (m == 1)
        {
            if (s < mid)
            {
                return false;
            }

            dsu.Union(u, v); // alpa
        }
        else
        {
            if (s >= mid)
            {
                // no need to upgrade
                dsu.Union(u, v);
            }
            else if (2 * s >= mid)
            {
                upgradeCandidates.push_back({u, v});
            }
        }
    }

    for (auto &edge : upgradeCandidates)
    { // O(E)
        int u = edge[0];
        int v = edge[1];

        if (dsu.find(u) != dsu.find(v))
        {
            if (k <= 0)
                return false;

            dsu.Union(u, v);
            k--; // upgrade
        }
    }

    int root = dsu.find(0);
    for (int node = 1; node <= n - 1; node++)
    { // O(n)
        if (dsu.find(node) != root)
            return false;
    }
    return true;
}

int maxStability(int n, vector<vector<int>>& edges, int k) {
    DSU dsu(n);
    for(auto e : edges){
        int src = e[0];
        int dst = e[1];
        int s = e[2];
        int mst = e[3];
        if(mst == 1){
            if(s < 1)return -1;
            dsu.Union(src,dst);
        }
    }
    /// we know that maximizing the minimun or minimizimg the maximium alwys use binary search so , we apply same across all possible stringth
    int left = 1;
    int right = 2* 10e5;
    int res = 0;
    while(left <= right){
        int mid = left +  (right - left)/2;
        if(check(edges , k,mid,n)){
            cout<<"mid "<<mid<<endl;
            res = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return res;
    // cout<<"check "<<check(edges , k,1999997,n)<<endl;
    //  return 0;
}

int main(){
    int n = 3;
    vector<vector<int>> edges = {{0, 1, 2, 1}, {1, 2, 3, 0}};
    int k = 1;
    cout<<maxStability(n,edges,k)<<endl;
    return 0;
}