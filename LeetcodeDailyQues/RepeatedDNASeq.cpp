#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    unordered_set<string> st;
    unordered_set<string> alreadyCounted;
    string seq = "";
    vector<string> ans;
    for (int i = 0; i < 10; i++)
    {
        seq += s[i];
    }
    st.insert(seq);
    for (int i = 10; i < s.length(); i++)
    {
        string temp = seq.substr(1, 9);
        temp += s[i];
        if (st.count(temp) and !alreadyCounted.count(temp))
        {
            ans.push_back(temp);
            alreadyCounted.insert(temp);
        }
        else st.insert(temp);
        seq = temp;
    }
    return ans;
}

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s);
    for (auto seq : res)
    {
        cout << seq << " ";
    }
    return 0;
}