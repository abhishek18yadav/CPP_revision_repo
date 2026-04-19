
#include<bits/stdc++.h>
using namespace std;
int distance(int val, int idx, vector<int> &nums2)
{
    int low = idx, high = nums2.size() - 1;
    int maxDis = INT_MIN;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums2[mid] >= val)
        {
            int lefty = mid - idx;
            maxDis = max(lefty, maxDis);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return maxDis;
}
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int res = INT_MIN;
        for (int i = 0; i < nums1.size(); i++)
        {
            int temp = distance(nums1[i], i, nums2);
            res = max(res, temp);
        }
        return res == INT_MIN ? 0 : res;
    }

    int main(){
        vector<int> nums1{55,30,5,5,2,1};
        vector<int> nums2{100,20,10,10,5};
        cout << maxDistance(nums1, nums2) << endl;
        return 0;
    }