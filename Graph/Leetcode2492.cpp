#include<bits/stdc++.h>
using namespace std;


#define pp pair<int, int>

    void add_edge(int src, int dst, int wt, vector<list<pp>> &gp, bool bi_dir = true)
    {
        gp[src].push_back({dst, wt});
        if (bi_dir)
        {
            gp[dst].push_back({src, wt});
        }
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<list<pp>> gp(n + 1);
        for (int i = 0; i < roads.size(); i++)
        {
            int src = roads[i][0];
            int dst = roads[i][1];
            int wt = roads[i][2];
            add_edge(src, dst, wt, gp);
        }
        // displayGraph(n);
        queue<pp> que;
        que.push({1, 0});
        unordered_set<int> vis;
        vis.insert(1);
        int ans = INT_MAX;
        while (!que.empty())
        {
            pp node = que.front();
            que.pop();
            if (node.first == n)
            {
                ans = min(ans, node.second);
            }
            for (auto el : gp[node.first])
            {
                ans = min(ans, el.second);
                if (!vis.count(el.first))
                {
                    vis.insert(el.first);
                    que.push({el.first, el.second});
                }
            }
        }
        return ans;
    }

int main(){
    int n = 4;
    vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    cout<<minScore(n,roads);
    return 0;
}