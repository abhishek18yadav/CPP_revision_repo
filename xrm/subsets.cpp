#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void f(vector<int> &temp, int idx, vector<int> &n)
{
    if (idx == n.size())
    {
        ans.push_back(temp);
        // temp.pop_back();
        return;
    }
    temp.push_back(n[idx]);
    f(temp, idx + 1, n);
    temp.pop_back();
    f(temp, idx + 1, n);

    return;
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        f(temp , 0 ,nums );
        return ans;
    }
    int main(){
        vector<int>nums = {1,2,3};
        vector<vector<int>> res = subsets(nums);
        for(auto i: res){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
