#include<bits/stdc++.h> 
using namespace std;
vector<int> p;
int dp[100001][3][2];
int f(int idx, int k, bool buy)
{
    if (idx >= p.size())
        return 0;
    if (dp[idx][k][buy] != -1)
        return dp[idx][k][buy];
    if (buy and k < 2)
    {
        return dp[idx][k][buy] = max(-p[idx] + f(idx + 1, k + 1, !buy), f(idx + 1, k, buy));
    }
    if (!buy)
    {
        return dp[idx][k][buy] = max(p[idx] + f(idx + 1, k, !buy), f(idx + 1, k, buy));
    }
    else
        return dp[idx][k][buy] = 0;
}
int maxProfit(vector<int> &prices)
{
    p = prices;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    return f(0, 0, 1);
    // buy =1, i.e first buy, buy =0 means already bought
}
int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(prices);
    return 0;
}