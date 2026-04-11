#include <bits/stdc++.h>
using namespace std;

    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
            if (mp[nums[i]].size() >= 3)
            {
                int thirdpos = mp[nums[i]][mp[nums[i]].size() - 1];
                int firstpos = mp[nums[i]][mp[nums[i]].size() - 3];
                ans = min(ans, 2 * (thirdpos - firstpos));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

    int main(){
        vector<int> nums = {1, 2, 1, 1, 3};
        cout<<minimumDistance(nums);
    }