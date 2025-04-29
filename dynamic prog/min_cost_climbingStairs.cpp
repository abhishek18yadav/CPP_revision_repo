#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
    int f(int idx , vector<int>&cost){
        if(idx >= cost.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        return dp[idx]= cost[idx] + min(f(idx+1, cost) , f(idx+2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(1002,-1);
        return min(f(0,cost), f(1,cost));
    }
    
    int main() {
        vector<int> cost = {10, 15, 20}; // Example input
        cout << "Minimum cost to climb stairs: " << minCostClimbingStairs(cost) << endl;
        return 0;
    }