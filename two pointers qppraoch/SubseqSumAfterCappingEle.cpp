#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int f(int i , vector<int> &temp, int k){
    if(k == 0)
        return 1;
    if(i >= temp.size() || k < 0)
        return 0;
   
    if(dp[i][k] != -1)return dp[i][k];
    int pick=-1 , notpick=-1;
    if(k-temp[i]>=0){
        pick = f(i + 1, temp, k - temp[i]);
    }
    notpick = f(i + 1, temp, k);
    return dp[i][k]= pick or notpick;
}
bool solve(vector<int> &temp, int k)
{
    dp.clear();
    dp.resize(temp.size()+1, vector<int>(k+1, -1));
    return f(0, temp, k);
}
vector<bool> subsequenceSumAfterCapping(vector<int> &nums, int k)
{
    int n = nums.size();
    
    int x = 1;
    vector<bool> res;
    while (x <= n)
    {
        vector<int> temp(n);
        for (int i = 0; i <n; i++)
        {
            temp[i] = min(x, nums[i]);
        }
        int ans = solve(temp, k);
        res.push_back(ans);
        // cout<<"For capping value "<<x<<" the result is "<<res[x-1]<<endl;
        x++;
    }
    for(int i=0; i<res.size(); i++){
        cout<<"Capping at "<<i+1<<" : "<<res[i]<<endl;
    }
    return res;
}

int main(){
    vector<int> nums = {4, 3, 2, 4};
    int k = 5;
    vector<bool> ans = subsequenceSumAfterCapping(nums, k);
    // for(int i=1; i<ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }
    return 0;
}
  

