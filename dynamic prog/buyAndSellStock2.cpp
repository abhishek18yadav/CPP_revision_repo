#include<bits/stdc++.h>
using namespace std;
    vector<int>p;
    vector<vector<int>>dp;
    int f(int idx , bool buy ){
        if(idx == p.size())return 0;
        if(dp[idx][buy] != -1)return dp[idx][buy];
        if(buy){
            return dp[idx][buy]= max(-p[idx] + f(idx+1 , !buy), f(idx+1 , buy));

        }else{
            return dp[idx][buy]=max(p[idx] + f(idx+1, !buy), f(idx+1 , buy));
        }
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1 , vector<int>(2,-1));
        p=prices;
        return f(0,1);
    }
int main(){
    vector<int>prices={1,2,3,4,5};
    cout<<maxProfit(prices);
    return 0;
}