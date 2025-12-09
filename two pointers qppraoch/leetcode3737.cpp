#include<bits/stdc++.h>
using namespace std;

// 3737. Count Subarrays With Majority Element I
int countMajoritySubarrays(vector<int> &nums, int target)
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int count2 = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] == target)
                count2 += 1;
            else
                count2 -= 1;
            if (count2 > 0)
                res++;
        }
    }
    return res;
}
int main(){
    vector<int> nums = {1,1,1};
    int target = 1;
    cout<<countMajoritySubarrays(nums,target);
    return 0;
}