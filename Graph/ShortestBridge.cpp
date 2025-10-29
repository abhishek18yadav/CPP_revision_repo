#include<bits/stdc++.h>
using namespace std;

#define pp pair<int, int>
vector<pp> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> gr;
void dfs(int i, int j, queue<pp>&que)
{
    gr[i][j] = 2;
    que.push({i, j});
    for (auto ele : dir)
    {
        int r = ele.first + i;
        int c = ele.second + j;
        if (r < 0 or r >= gr.size() or c < 0 or c >= gr[r].size() or gr[r][c] == 0 or gr[r][c] == 2)
            continue;
        else
        {
            dfs(r, c,que);
        }
    }
    return;
}
int bfs(queue<pp>&que){
    int ans = 0;
    que.push({-1,-1});
    while(!que.empty()){
        pp node = que.front();
        que.pop();
        if(node.first == -1 and node.second == -1){
            ans++;
            if(!que.empty()){
                que.push({-1,-1});
            }
            continue;
        }
        for(auto el : dir){
            int r = node.first + el.first;
            int c = node.second + el.second;
            if(r < 0 or r >= gr.size() or c < 0 or c >= gr[r].size() or gr[r][c] == 2){
                continue;
            }
            if(gr[r][c] == 1){
                return ans;
            }
            gr[r][c] = 2;
            que.push({r,c});
        }
    }
    return ans;
}
int shortestBridge(vector<vector<int>> &grid)
{
    int ans = 0;
    gr = grid;
    int count = 0;
    queue<pp> que;
    for (int i = 0; i < gr.size(); i++)
    {
        for (int j = 0; j < gr[i].size(); j++)
        {
            if (count == 0 and gr[i][j] == 1)
            {
                count++;
                dfs(i, j,que);
                ans = bfs(que);
            }

            
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> grid{
        {1, 1, 1, 1, 1}, { 1, 0, 0, 0, 1 }, { 1, 0, 1, 0, 1 }, { 1, 0, 0, 0, 1 }, { 1, 1, 1, 1, 1 }};
    // vector<vector<int>> grid{
    //     {0, 1, 0}, { 0, 0, 0 }, { 0, 0, 1 }};
    cout<<shortestBridge(grid);
    return 0;
}