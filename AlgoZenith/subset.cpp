#include<bits/stdc++.h>
using namespace std;

void f(vector<int> &nums, int i, vector<int>&res , vector<vector<int>>&answer){
    if(i >= nums.size()){
        answer.push_back(res);
        return;
    }
    res.push_back(nums[i]);
    f(nums, i + 1, res, answer);
    res.pop_back();
    f(nums, i + 1, res, answer);
}
    vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> res;
    vector<vector<int>> answer;
    f(nums, 0, res, answer);
    return answer;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}