#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int f(int i, int j, int m, int n)
{
    if (i >= m or j >= n)
        return 0;
    if (i == m - 1 and j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int right = 0, down = 0;
    if (j + 1 < n)
    {
        right = f(i, j + 1, m, n);
    }
    if (i + 1 < m)
    {
        down = f(i + 1, j, m, n);
    }
    return dp[i][j] = right + down;
}
int uniquePaths(int m, int n)
{
    dp.resize(101, vector<int>(101, -1));
    return f(0, 0, m, n);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}