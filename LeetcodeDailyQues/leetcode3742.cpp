
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int dp[201][201][1001];
int f(int i, int j, int k, int m, int n)
{
    if (i >= m or j >= n or k < 0)
        return INT_MIN;

    int score = g[i][j];
    int reduction = score > 0 ? 1 : 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if (i == m - 1 and j == n - 1)
    {
        if (k - reduction >= 0)
            return g[i][j];
        else
            INT_MIN;
    }

    int right = f(i, j + 1, k - reduction, m, n);
    int down = f(i + 1, j, k - reduction, m, n);
    return dp[i][j][k] = score + max(right, down);
}
int maxPathScore(vector<vector<int>> &grid, int k)
{
    
    g = grid;
    int m = g.size();
    int n = g[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for (int k = 0; k < 1000; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    int res = f(0, 0, k, m, n);
    return res <0 ? -1 : res;
}

    int main(){
        vector<vector<int>> grid{
            {0, 1}, {1, 2}};
        cout<<maxPathScore(grid, 1);
        return 0;
    }
