// Write your code here
//walmart ques
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> dp;
long long noOfways(int target, int curr)
{
    if (curr > target)
        return 0;
    if (curr == target)
        return 1;
    if(dp[curr]!= -1)
        return dp[curr];
    long long ans = 0;
    for (int i = curr + 1; i <= target; i++)
    {
        if (i % (i - curr) == 0)
        {
            ans += noOfways(target, i);
        }
    }
    return dp[curr]= ans % MOD;
}
int main()
{
    dp.resize(100001, -1);
    int target = 89;
    // cin >> target;
    cout << noOfways(target, 1);
    
    return 0;
}