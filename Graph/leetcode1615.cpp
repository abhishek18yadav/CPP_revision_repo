#include<bits/stdc++.h>
using namespace std;

    vector<list<int>> gp;
    void add_edge(int src, int dst)
    {
        gp[src].push_back(dst);
        gp[dst].push_back(src);
    }

    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        gp.resize(n, list<int>());
        int ans = INT_MIN;
        for (auto ele : roads)
        {
            int src = ele[0];
            int dst = ele[1];
            add_edge(src, dst);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int src = i;
                int dst = j;
                int sum = gp[src].size() + gp[dst].size();
                if (find(gp[src].begin(), gp[src].end(), dst) != gp[src].end())
                {
                    sum--;
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }

    int main(){
        vector<vector<int>>roads = {{0,1},{0,3},{1,2},{1,3}};
        int n = 4;
        cout<<maximalNetworkRank(n,roads);
        return 0;
    }