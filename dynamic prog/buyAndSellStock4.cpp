#include<bits/stdc++.h> 
using namespace std;
    vector<int> p;
    int dp[100001][103][2];
    int f(int idx, int k, bool buy, int l)
    {
        if (idx >= p.size())
            return 0;
        if (dp[idx][k][buy] != -1)
            return dp[idx][k][buy];
        if (buy and k <= l)
        {
            return dp[idx][k][buy] = max(-p[idx] + f(idx + 1, k + 1, !buy, l), f(idx + 1, k, buy, l));
        }
        if (!buy)
        {
            return dp[idx][k][buy] = max(p[idx] + f(idx + 1, k, !buy, l), f(idx + 1, k, buy, l));
        }
        else
            return dp[idx][k][buy] = 0;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        p = prices;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = 0; j <= k; j++)
            {
                for (int l = 0; l < 2; l++)
                {
                    dp[i][j][l] = -1;
                }
            }
        }
        return f(0, 0, 1, k);
        // buy =1, i.e first buy, buy =0 means already bought
    }
int main(){
    vector<int>prices={1,2,4,2,5,7,2,4,9,0};
    int k=2;
    cout<<maxProfit(k,prices);
    return 0;
}