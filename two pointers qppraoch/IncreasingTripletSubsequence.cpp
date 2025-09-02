#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 1; i <= nums.size(); i++)
    {
        mp[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= nums.size() - 2; i++)
    {
        int j = i + 1, k = i + 2;
        if (mp[nums[i]] < mp[nums[j]])
        {
            if (mp[nums[j]] < mp[nums[k]])
            {
                return true;
            }
        }
    }
    return false;
}
int main(){
    
}