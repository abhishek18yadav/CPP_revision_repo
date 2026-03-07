#include <bits/stdc++.h>
using namespace std;

    int f(int el1, int el2, int el3)
    {
        int digitSize = log2(el1) + 1;
        long res = 0;
        res = (res << digitSize) + el1;
        digitSize = log2(el2) + 1;
        res = (res << digitSize) + el2;
        digitSize = log2(el3) + 1;
        res = (res << digitSize) + el3;
        return res;
    }
    int maxGoodNumber(vector<int> &nums)
    {
        int ele = nums[0];
        int ele2 = nums[1];
        int ele3 = nums[2];
        int ans1 = f(ele, ele2, ele3);
        int ans2 = f(ele2, ele3, ele);
        int ans3 = f(ele3, ele, ele2);
        int ans4 = f(ele, ele3, ele2);
        int ans5 = f(ele3, ele2, ele);
        int ans6 = f(ele2, ele, ele3);
        return max({ans1, ans2, ans3, ans4, ans5, ans6});
    }
    int main()
    {
        vector<int> nums = {1, 2, 3};
        cout << maxGoodNumber(nums) << endl;
        return 0;
    }