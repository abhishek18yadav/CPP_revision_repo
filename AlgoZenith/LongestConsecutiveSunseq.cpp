
#include <bits/stdc++.h>
using namespace std;
    int longestConsecutive(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int ele : nums)
            pq.push(ele);
        vector<int> res;
        unordered_set<int> st;
        while (!pq.empty())
        {
            res.push_back(pq.top());
            st.insert(pq.top());
            pq.pop();
        }
        unordered_map<int, int> mp;

        for (int i = 0; i < res.size(); i++)
        {
            mp[res[i]] = i;
        }
        int strt = 0, count = 1, ans = 0;
        while (strt < res.size())
        {
            int ele = res[strt];
            if (st.count(ele + 1))
            {
                count++;
                strt = mp[ele + 1];
            }
            else
            {
                ans = max(ans, count);
                count = 1;
                strt++;
            }
        }
        return ans;
    }
    int main()
    {
        vector<int> nums = {100, 4, 200, 1, 3, 2};
        cout << longestConsecutive(nums) << endl;
        return 0;
    }
