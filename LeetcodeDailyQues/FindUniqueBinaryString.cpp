#include <bits/stdc++.h>
using namespace std;

    vector<string> ans;
    void f(int len, string &str)
    {
        if (str.length() == len)
        {
            ans.push_back(str);
            return;
        }
        str += '1';
        f(len, str);
        str.pop_back();
        str += '0';
        f(len, str);
        str.pop_back();
        return;
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        string str = "";
        unordered_set<string> st;
        int len = nums[0].length();
        f(len, str);
        ////////
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        /////////
        for (int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        for (string ele : ans)
        {
            if (!st.count(ele))
                return ele;
        }
        return "";
    }
    int main()
    {
        vector<string> nums = {"01", "10"};
        cout << findDifferentBinaryString(nums) << endl;
        return 0;
    }
