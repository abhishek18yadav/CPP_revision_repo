#include<bits/stdc++.h>
using namespace std;
unordered_map<int, string> mp = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}};

void f(string &digits, int idx, string &path, vector<string>&ans)
{
    if(idx == digits.size()){
        ans.push_back(path);
        return;
    }
    for(char ele : mp[digits[idx]-'0']){
        path.push_back(ele);
        f(digits, idx + 1, path, ans);
        path.pop_back();
    }
}
vector<string>letterCombinations(string digits)
{
    string path = "";
    vector<string> ans;
    f(digits, 0, path, ans);
    return ans;
}

int main(){
    string digits = "234";
    vector<string> ans = letterCombinations(digits);
    for(string s : ans){
        cout << s << " ";
    }
    return 0;
}