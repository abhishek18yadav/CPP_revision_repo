#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> dp;
    int f(int i, int j, vector<int> &nums1, vector<int> &nums2)
    {
        if (i == nums1.size() or j == nums2.size())
            return -100000001;

        if (dp[i][j] != -1)
            return dp[i][j];
        int product = nums1[i] * nums2[j];

        int maxPro = max({product + f(i + 1, j + 1, nums1, nums2),
                          product,
                          f(i + 1, j, nums1, nums2),
                          f(i, j + 1, nums1, nums2)});
        return dp[i][j] = maxPro;
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        dp.resize(501, vector<int>(501, -1));
        return f(0, 0, nums1, nums2);
    }
    int main(){
        vector<int> nums1={2,1,-2,5};
        vector<int> nums2={3,0,-6};
        cout<<maxDotProduct(nums1,nums2);
        return 0;
    }
