#include <bits/stdc++.h>
using namespace std;

vector<list<int>> gp;
void add_edge(int src, int dest, bool bi_dir = false)
{
    gp[src].push_back(dest);
    if (bi_dir)
    {
        gp[dest].push_back(src);
    }
}

void dfs(int node, unordered_set<int> &st)
{
    for (auto ele : gp[node])
    {
        if (!st.count(ele))
        {
            st.insert(ele);
            dfs(ele, st);
        }
    }
    return;
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    gp.resize(20, list<int>());
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            if (isConnected[i][j] == 1)
            {
                // cout << i << j << endl;
                add_edge(i + 1, j + 1);
            }
        }
    }
    // display();
    unordered_set<int> st;
    int count = 0;
    for (int i = 1; i <= isConnected.size(); i++)
    {
        if (!st.count(i))
        {
            count++;
            st.insert(i);
            dfs(i, st);
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> isConnected{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout << findCircleNum(isConnected)<<endl;
    return 0;
}