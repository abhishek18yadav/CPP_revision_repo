#include<bits/stdc++.h>
// its weekly question of leetcode
using namespace std;
int minOperations(string s)
{
    int ans = -10;
    for (auto ele : s)
    {
        ans = max(ans, (26 - (ele - 'a')) % 26);
    }
    return ans;
}

int main(){
    string s = "abc";

    cout<<minOperations(s)<<endl;
    return 0;
}