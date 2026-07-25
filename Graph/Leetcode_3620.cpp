// not coreect
#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
vector<list<pair<int,int>>> gp;
void add_edge(int src, int dest, int wt){
    gp[src].push_back({dest,wt});
}
void display(){
    for(int i=0; i<gp.size(); i++){
        cout<<i<<"->";
        for(auto it : gp[i]){
            cout<<it.first<<"->"<<it.second<<endl;
        }
    }
}

bool dik(int src , int mid, int k, vector<bool> &online){
    unordered_map<int, int> mp;
    int n = online.size();
    for (int i = 0; i < n; i++){
        mp[i] = INT_MAX;
    }
    mp[src] = 0;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0, src});
    while(!pq.empty() and k > 0){
        pp curr = pq.top();
        pq.pop();
        if(mp[curr.second] < curr.first){
            continue;
        }
        for(auto nbr : gp[curr.second]){
            if(online[nbr.first] && mid <= nbr.second){
                int newDist = nbr.second + curr.first;
                if(mp[nbr.first] > newDist){
                    mp[nbr.first] = newDist;
                    pq.push({mp[nbr.first], nbr.first});
                }
            }
        }
    }
    // 
    // for(auto it : mp){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }

    return  mp[n - 1] <= k;
}
int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k){

    int n = online.size();
    gp.resize(n, list<pair<int,int>>());
    for (int i = 0; i<edges.size(); i++){
        int src = edges[i][0];
        int dest = edges[i][1];
        int wt = edges[i][2];
        add_edge(src, dest, wt);
    }
    int left = 0, right = 1000000000;
    int ans = INT_MIN;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(dik(0, mid, k, online)){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return ans == INT_MIN ? -1 : ans;
}


int main(){
    vector<vector<int>> edges = {{0, 1, 0}, {0, 2, 7}, {1, 3, 9}, {0, 4, 7}, {2, 4, 9}, {3, 4, 2}, {0, 3, 5}, {2, 3, 3}, {1, 4, 6}, {1, 2, 0}};

    vector<bool> online = {true, true, true, true, true};
    cout<<findMaxPathScore(edges, online, 5)<<endl;
    return 0;
}
