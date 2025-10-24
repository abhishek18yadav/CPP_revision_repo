#include<bits/stdc++.h>
using namespace std;

#define pp pair<int, int>
vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int solve(vector<vector<int>> &grid, int i, int j)
{
    int ans = 1;
    queue<pp> que;
    que.push({i, j});
    grid[i][j] = 0;
    //  cout<<"Visiting: "<<i<<","<<j<<endl;
    while (!que.empty())
    {
        pp temp = que.front();
        que.pop();
        for (auto ele : dir)
        {
            int r = temp.first + ele[0];
            int c = temp.second + ele[1];
            if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
                continue;
            if (grid[r][c] == 1)
            {
                // cout<<"Visiting: "<<r<<","<<c<<endl;
                que.push({r, c});
                grid[r][c] = 0;
                ans++;
            }
        }
    }
    return ans;
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int maxarea = -100;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                // cout<<"Found island at: "<<i<<","<<j<<endl;
                int area = solve(grid, i, j);
                maxarea = max(maxarea, area);
            }
        }
    }
    return (maxarea == -100) ? 0 : maxarea;
}

int main(){
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}