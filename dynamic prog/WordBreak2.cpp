#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool> Dict;
vector<string> ans;
void f(int idx , string &temp , string &s){
    if(idx == s.length()){
        ans.push_back(temp);
        return;
    }
    string temp2 = "";
    for (int i = idx; i < s.length(); i++){
        temp2 += s[i];
        if(Dict.find(temp2) != Dict.end()){
            string nexttemp = temp.empty() ? temp2 : temp + " " + temp2;
            f(i + 1 , nexttemp , s);
        }
    }
    return;
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    Dict.clear();
    for(string ele : wordDict){
        Dict[ele] = true;
    }
    string temp = "";
    f(0, temp, s);
    return ans;
}

int main(){
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> ans = wordBreak(s, wordDict);
    for(auto ele : ans){
        cout << ele << " ";
    }
    return 0;
}