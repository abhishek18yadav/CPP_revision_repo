#include<bits/stdc++.h>
using namespace std;


    vector<int> dp;
    unordered_map<string, bool> Dict;
    bool f(int idx, string &s)
    {
        if (idx == s.length())
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        string temp = "";
        for (int i = idx; i < s.length(); i++)
        {
            temp += s[i];
            if (Dict.find(temp) != Dict.end())
            {
                if (f(i + 1, s))
                    return dp[i] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        dp.resize(301, -1);
        Dict.clear();
        for (string word : wordDict)
        {
            Dict[word] = true;
        }
        return f(0, s);
    }

int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet", "ode"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}