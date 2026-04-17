#include<bits/stdc++.h>
using namespace std;


    int revFun(int no)
    {
        int rev = 0;
        while (no)
        {
            int temp = no % 10;
            rev = rev * 10 + temp;
            no /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {

            int revNo = revFun(nums[i]);
            if (mp.find(nums[i]) != mp.end())
            {
                // cout<<mp[revNo]<<" ";
                int diff = abs(i - mp[nums[i]]);
                ans = min(ans, diff);
            }
            mp[revNo] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
    int main(){
        vector<int> nums{12,34,45,21,12};
        cout<<minMirrorPairDistance(nums);
        return 0;
    }