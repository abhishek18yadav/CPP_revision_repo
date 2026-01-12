#include <bits/stdc++.h>
using namespace std;


    vector<vector<int>> dp;
    int f(int i, int j, string &s1, string &s2)
    {
        if (i == s1.length() or j == s2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int picked = INT_MIN, notMatched = INT_MIN;
        // if mayched
        if (s1[i] == s2[j])
        {
            picked = int(s1[i]) + f(i + 1, j + 1, s1, s2);
        }
        // if not matched
        else
            notMatched = max(f(i + 1, j, s1, s2), f(i, j + 1, s1, s2));

        return dp[i][j] = max(picked, notMatched);
    }
    int minimumDeleteSum(string s1, string s2)
    {
        dp.resize(1001, vector<int>(1001, -1));
        int sum1 = 0, sum2 = 0;
        for (auto ele : s1)
            sum1 += int(ele);
        for (auto ele : s2)
            sum2 += int(ele);
        int res = f(0, 0, s1, s2);
        return (sum1 + sum2) - (2 * res);
    }

    int main()
    {
        string s1 = "sea";
        string s2 = "eat";
        cout << minimumDeleteSum(s1, s2) << endl;
        return 0;
    }