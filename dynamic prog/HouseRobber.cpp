#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
int f(int idx, vector<int> &nums)
{
    if (idx == nums.size() - 1)
        return nums[idx];
    if (idx == nums.size() - 2)
        return max(nums[idx], nums[idx + 1]);
    if (idx >= nums.size())
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int robbed = 0, notRobbed = 0;
    if (idx + 1 <= nums.size() - 1)
    {
        notRobbed = f(idx + 1, nums);
    }
    if (idx + 2 <= nums.size() - 1)
    {
        robbed = nums[idx] + f(idx + 2, nums);
    }

    return dp[idx] = max(robbed, notRobbed);
}
int rob(vector<int> &nums)
{
    dp.resize(101, -1);

    return f(0, nums);
}
int main(){
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum amount that can be robbed: " << rob(nums) << endl;
    return 0;
}