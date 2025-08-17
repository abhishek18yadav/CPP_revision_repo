#include<bits/stdc++.h>
using namespace std;

void f(int idx, vector<int> &nums, vector<int> &dummy, vector<vector<int>> &res)
{
    if (idx == nums.size())
        return;

    for (int i = idx; i < nums.size(); i++)
    {
        dummy.push_back(nums[i]);
        res.push_back(dummy);
        f(i + 1, nums, dummy, res);
        dummy.pop_back();
    }
    return;
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> dummy;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end()); // Sort to handle duplicates

    res.push_back({});
    f(0, nums, dummy, res);
    sort(res.begin(), res.end()); // Sort the result to ensure order
    auto newend = unique(res.begin(), res.end()); // Remove duplicates
    res.erase(newend, res.end()); // Resize the vector to remove duplicates
    return res;
}
int main(){
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsetsWithDup(nums);  
    for(const auto &subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}