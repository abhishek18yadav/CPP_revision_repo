#include<bits/stdc++.h>
using namespace std;

#define pp pair<int, int>
    vector<list<pp>> gp;
    vector<int> res;
    vector<vector<int>> dp;
    void add_edge(int src, int dst, int clr)
    {
        gp[src].push_back({dst, clr});
    }
    void display()
    {
        for (int i = 0; i < gp.size(); i++)
        {
            cout << i << "->";
            for (auto ele : gp[i])
            {
                cout << '(' << ele.first << " " << ele.second << ')';
            }
            cout << endl;
        }
    }
    int dfs(int finalTarget, int src, int prevclr, int count)
    {

        int minVal = INT_MAX;

        if (src == finalTarget)
        {
            minVal = min(minVal, count);
            res[finalTarget] = minVal;
            // cout << "dst"<<finalTarget<<"->"<<minVal << endl;

            return 1;
        }
        for (auto ele : gp[src])
        {
            if (ele.second != prevclr)
            {
                bool ans = dfs(finalTarget, ele.first, ele.second, count + 1);
                if (!ans)
                {
                    return -1;
                }
                // if (ele.first == finalTarget)
                //     break;
            }else
                continue;
        }
        return 1;
    }

    // void bfs(int finalTarget, int src, int prevclr)
    // {
    //     int n = gp.size();
    //     vector<vector<int>> vis(n, vector<int>(2, 0));
    //     queue<tuple<int, int, int>> que; // node, color, steps
    //     que.push({src, prevclr, 0});
    //     vis[src][prevclr] = 1;
    //     int minVal = INT_MAX;
    //     while (!que.empty())
    //     {
    //         auto tup = que.front();
    //         int node = get<0>(tup);
    //         int color = get<1>(tup);
    //         int steps = get<2>(tup);
    //         que.pop();
    //         if (node == finalTarget)
    //         {
    //             minVal = min(minVal, steps);
    //             res[node] = minVal;
    //             break;
    //         }
    //         for (auto ele : gp[node])
    //         {
    //             if (!vis[ele.first][ele.second] && ele.second != color)
    //             {
    //                 vis[ele.first][ele.second] = 1;
    //                 que.push({ele.first, ele.second, steps + 1});
    //             }
    //         }
    //     }
    // }
    void bfs(int finalTarget, int src, int prevclr){
        int n = gp.size();
        vector<vector<int>> vis(n, vector<int>(3, 0));
        vis[src][prevclr] = 1;
        queue<tuple<int, int, int>> que;
        int count = 0;
        que.push({src, prevclr, count});
        int maxVal = INT_MAX;
        while(!que.empty()){
            auto tuple = que.front();
            que.pop();
            int node = get<0>( tuple);
            int preclr = get<1>(tuple);
            int cnt = get<2>(tuple);
            if(node==finalTarget){
                maxVal = min(maxVal, cnt);
                res[node] = maxVal;
                break;
            }
            for(auto ele: gp[node]){
                if(!vis[ele.first][ele.second] and ele.second!= preclr){
                    vis[ele.first][ele.second] = 1;
                    que.push({ele.first, ele.second, cnt + 1});
                }
            }
        }
    }

        vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        gp.resize(n, list<pp>());
        res.resize(n, -1);
        for (int i = 0; i < redEdges.size(); i++)
        {
            add_edge(redEdges[i][0], redEdges[i][1], 1);
        }
        for (int i = 0; i < blueEdges.size(); i++)
        {
            add_edge(blueEdges[i][0], blueEdges[i][1], 0);
        }
        // display();
        for (int i = 0; i < n; i++)
        {
            bfs(i, 0, 2);
        }
        return res;
    }
    int main(){
    int n = 5;
    vector<vector<int>> redEdges = {{0, 1}, {1, 2},{2,3},{3,4}};
    vector<vector<int>> blueEdges = {{1, 2}, {2, 3},{3,1}}; 
    vector<int> ans = shortestAlternatingPaths(n, redEdges, blueEdges);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    }
