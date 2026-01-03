#include <bits/stdc++.h>
using namespace std;
    vector<vector<int>> dp;
    bool f(int si, int pi, string &s, string &p)
    {
        if (pi == p.length())
        {
            return si == s.length();
        }
        if (dp[si][pi] != -1)
            return dp[si][pi];
        bool sameChar = false;
        if (si < s.length() and (s[si] == p[pi] or p[pi] == '.'))
            sameChar = true;
        // if(p[pi]== '.')return f(si + 1, pi+1, s,p);
        if (p[pi + 1] == '*')
        {
            int nottake = f(si, pi + 2, s, p);
            int take = (sameChar and f(si + 1, pi, s, p));
            return dp[si][pi]=take or nottake;
        }
        else if (p[pi] == '.')
            return dp[si][pi] = f(si + 1, pi + 1, s, p);
        else
        {
            return dp[si][pi] = (si < s.length() and pi < p.length() and s[si] == p[pi] and f(si + 1, pi + 1, s, p));
        }
        return dp[si][pi] = false;
    }
    bool isMatch(string s, string p)
    {
        dp.resize(s.length() + 1, vector<int>(p.length() + 1, -1));
        return f(0, 0, s, p);
    }
    int main()
    {
        string s = "aab";
        string p = "c*a*b";
        cout << isMatch(s, p);
        return 0;
    }
