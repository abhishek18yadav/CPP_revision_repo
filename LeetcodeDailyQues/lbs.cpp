#include <bits/stdc++.h>
using namespace std;


    int f(vector<int> &nums)
    {
        int len = 0;
        int l = nums.size();
        for (int i = 0; i < l; i++)
        {
            unordered_map<int, int> ev;
            unordered_map<int, int> od;
            for (int j = i; j < l; j++)
            {
                if (nums[j] % 2 == 0)
                    ev[nums[j]]++;
                else
                    od[nums[j]]++;

                // check at each extension of the window
                if (ev.size() == od.size())
                {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }
    int longestBalanced(vector<int> &nums)
    {
        return f(nums);
    }

    int main()
    {
        vector<int> nums = {32, 85, 184, 92, 83, 54, 49, 195, 175, 101, 142, 115, 159, 77};
        cout << longestBalanced(nums) << endl;
        return 0;
    }
