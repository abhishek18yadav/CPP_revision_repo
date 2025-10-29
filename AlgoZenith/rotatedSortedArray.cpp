#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size()-1;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target){
            ans = mid;
            break;
        }
        else if (nums[left] <= nums[mid])
        {
            //  left is sorted
            // aplying binary serch
            if (nums[mid] > target and target >= nums[left])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            // that means right region region is sorted now
            if (nums[mid] < target and nums[right] >= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums, target) << endl;
    return 0;
}