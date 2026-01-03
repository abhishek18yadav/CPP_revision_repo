#include <bits/stdc++.h>
using namespace std;
    int md = 1e9 + 7;
    vector<string> colorList;
    vector<vector<int>> dp;
    void createList(int m, string str, int idx)
    {
        if (idx == m)
        {
            colorList.push_back(str);
            return;
        }
        for (auto ele : {'r', 'g', 'b'})
        {
            if (idx - 1 >= 0 and str[idx - 1] == ele)
                continue;
            createList(m, str + ele, idx + 1);
        }
    }
    int solve(int prevIdx, int remainCol)
    {
        if (remainCol == 0)
            return 1;
        int ways = 0;
        if(dp[prevIdx][remainCol] != -1)
            return dp[prevIdx][remainCol];
        for (int i = 0; i < colorList.size(); i++)
        {
            if (i == prevIdx)
                continue;
            bool valid = true;
            for (int j = 0; j < colorList[i].size(); j++)
            {
                if (colorList[prevIdx][j] == colorList[i][j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                ways = (ways + solve(i, remainCol - 1)) % md;
            }
        }
        return dp[prevIdx][remainCol]= ways;
    }
    int colorTheGrid(int m, int n)
    {
        createList(m, "", 0);
        int l = colorList.size();
        dp.resize(l, vector<int>(n + 1, -1));
        int ways = 0;
        for (int i = 0; i < colorList.size(); i++)
        {
            ways = (ways + solve(i, n - 1)) % md;
        }
        return ways;
    }

    int main(){
        int m = 5;
        int n = 5;
        cout<<colorTheGrid(m,n);
    }