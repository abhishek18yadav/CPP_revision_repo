#include<bits/stdc++.h>
using namespace std;


int PeakIdxSearch(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    int Peakidx = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        Peakidx = mid;
        if (mid + 1 < nums.size() and nums[mid] < nums[mid + 1])
            left = mid + 1;

        else if (mid - 1 >= 0 and nums[mid] < nums[mid - 1])
            right = mid - 1;

        else
            break;
    }
    return Peakidx;
}
int findPeakElement(vector<int> &nums)
{
    return PeakIdxSearch(nums);
}
int main(){

    vector<int> nums = {6, 5, 4, 3, 2, 3, 2};
    cout<<findPeakElement(nums);
    return 0;
}