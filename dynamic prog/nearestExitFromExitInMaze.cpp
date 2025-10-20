#include<bits/stdc++.h>
using namespace std;
#define pp pair<int, int>
vector<vector<char>> mz;
int bfs(int r, int c)
{
    queue<pp> que;
    que.push({r, c});
    mz[r][c] = '+';
    que.push({-1000, -1000});
    int ans = 0;
    int steps = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!que.empty())
    {
        pp temp = que.front();
        que.pop();
        int t_r = temp.first;
        int t_c = temp.second;
        if (temp.first == -1000 and temp.second == -1000)
        {
            if (!que.empty()){
                que.push({-1000, -1000});
                ans++;
                steps++;
            }
            continue;
        }
        
        if ((t_r != r and t_c != c) and   (t_r == mz.size() - 1 or t_c == mz[t_r].size() - 1 or t_r == 0 or t_c == 0))
            return ans;
        
        for(auto dirc : dir){
            int n_r = t_r + dirc[0];
            int n_c = t_c + dirc[1];
            if (n_r < 0 or n_r >= mz.size() or n_c < 0 or n_c >= mz[t_r].size() or mz[n_r][n_c] == '+')
                continue;
            que.push({n_r, n_c});
            mz[n_r][n_c] = '+';
        }
    }
    return -1;
}
int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    mz = maze;
    int r = entrance[0];
    int c = entrance[1];
    // cout<<r<<" "<<c<<endl;
    return bfs(r, c);
}
int main(){
    // vector<vector<char>> maze = {
    //     {'+','+','.','+'},
    //     {'.','.','.','+'},
    //     {'+','+','+','.'}
    // };
    // vector<int> entrance = {1,2};
    // vector<vector<char>> maze = {
    //     {'.','+'}
        
    // };
    // vector<int> entrance = {0, 0};
    vector<vector<char>> maze = {
        {'+', '.', '+', '+', '+', '+', '+'},
        {'+', '.', '+', '.', '.', '.', '+'},
        {'+', '.', '+', '.', '+', '.', '+'},
        {'+', '.', '.', '.', '+', '.', '+'},
        {'+', '+', '+', '+', '+', '+', '.'}};
    vector<int> entrance = {0, 1};
    cout << nearestExit(maze, entrance);
    return 0;
}