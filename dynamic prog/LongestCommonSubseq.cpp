#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int f(string &t1, string &t2 , int idx1 , int idx2){
    if(idx1 == t1.length()|| idx2 == t2.length()){
        return 0;
    }
    if(dp[idx1][idx2]!= -1)
        return dp[idx1][idx2];
    int ans =0;

    if(t1[idx1]==t2[idx2]){
        ans = 1+ f(t1, t2, idx1 + 1, idx2 + 1);
    }
    else{
        ans = max(f(t1, t2, idx1 + 1, idx2), f(t1, t2, idx1, idx2 + 1));
    }
    if(ans != INT_MIN){
        return dp[idx1][idx2]=ans;
    }
    else
        return 0;
}

int longestCommonSubsequence(string text1, string text2){
    dp.resize(1001, vector<int>(1001, -1));
    return f(text1, text2, 0, 0);
}

int main(){
    int ans=longestCommonSubsequence("abed", "acbd");
    cout << ans;
    return 0;
}