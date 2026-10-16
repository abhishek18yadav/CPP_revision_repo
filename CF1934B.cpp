#include<bits/stdc++.h>
using namespace std;
vector<int>c;
vector<int>dp;
int f(int amt){
    dp[0] = 0;
    for(int i=1;i<=amt;i++){
        for(int j=0;j<c.size();j++){
            if(i-c[j]>=0){
                dp[i] = min(dp[i],1+dp[i-c[j]]);
            }
        }
    }
    return dp[amt];
}


int MinNoOfCoins(int amt){
    c = {1,3,6,10,15};
    // dp.assign(amt+1,amt+1);
    if (amt > 60)
    {
        int coins_of_15 = (amt - 45) / 15;
        amt -= coins_of_15 * 15;
        dp.assign(amt + 1, amt + 1);
        return coins_of_15 + f(amt);
    }
    dp.assign(amt + 1, amt + 1);
    int res =  f(amt);
    return res == INT_MAX ? -1 : res;
}

int main(){
    int n;
    if(cin>>n){
        while(n){
            int amt;
            if(cin>>amt){
                cout<<MinNoOfCoins(amt)<<endl;
            }
            n--;
        }
    }
    return 0;
}
