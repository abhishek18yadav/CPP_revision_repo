
#include <bits/stdc++.h>
using namespace std;

bool closeStrings(string word1, string word2)
{
    unordered_map<char, int> mp1, mp2;

    vector<int> v1, v2;
    for (int i = 0; i < word1.length(); i++)
    {
        mp1[word1[i]]++;
    }
    for (int i = 0; i < word2.length(); i++)
    {
        if (mp1.find(word2[i]) == mp1.end())
            return false;
        mp2[word2[i]]++;
    }
    for (auto ele : mp1)
    {
        v1.push_back(ele.second);
    }
    for (auto ele : mp2)
    {
        v2.push_back(ele.second);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    return v1 == v2;
}

int main()
{
    string word1 = "a", word2 = "aa";
    if (closeStrings(word1, word2))
        cout << "true";
    else
        cout << "false";
    return 0;
}