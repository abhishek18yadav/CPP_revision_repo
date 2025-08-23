#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp1, mp2;
    for (int i = 1; i <= 1000; i++)
    {
        mp1[i] = 1001;
        mp2[i] = 1001;
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        mp1[nums1[i]] = nums1[i];
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        mp2[nums2[i]] = nums2[i];
        if (mp1[nums2[i]] != 1001)
            mp1[nums2[i]] = 1001;
    }
    vector<vector<int>> res;
    vector<int> ans;
    for (auto it = mp1.begin(); it != mp1.end(); it++)
    {
        if (it->second != 1001)
            ans.push_back(it->second);
    }
    res.push_back(ans);
    ans.clear();
    for (int i = 0; i < nums1.size(); i++)
    {
        if (mp2[nums1[i]] != 1001)
            mp2[nums1[i]] = 1001;
    }
    for (auto it = mp2.begin(); it != mp2.end(); it++)
    {
        if (it->second != 1001)
            ans.push_back(it->second);
    }
    res.push_back(ans);

    return res;
}

int main(){
    vector<int> nums1 = {1, 2, 3}, nums2 = {2, 4, 6};
    vector<vector<int>> ans = findDifference(nums1, nums2);
    for(auto x : ans){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0; 
}