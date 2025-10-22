#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<vector<int>> answer;
void f(vector<int> &nums, unordered_set<int>&st){
    if(ans.size() == nums.size()){
        answer.push_back(ans);
        return;
    }
    for (int i = 0; i < nums.size(); i++){
        if(st.count(nums[i]))
            continue;
        ans.push_back(nums[i]);
        st.insert(nums[i]);
        f(nums, st);
        st.erase(nums[i]);
        ans.pop_back();
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    unordered_set<int> st;
    f(nums, st);
    return answer;
}
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(auto vec : ans){
        for(int ele : vec){
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}