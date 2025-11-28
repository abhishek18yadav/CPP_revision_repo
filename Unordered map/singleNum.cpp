#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
            return it.first;
    }
    return -1; // In case there is no single number
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;
    return 0;
}