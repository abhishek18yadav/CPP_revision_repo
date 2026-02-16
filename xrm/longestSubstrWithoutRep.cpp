#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int ans = 0;
        unordered_set<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            st.clear();
            for (int j = i; j < s.length(); j++)
            {
                if (st.count(s[j]))
                {
                    ans = max(ans, j - i);
                    break;
                }
                if (j == s.length() - 1)
                    ans = max(ans, j - i + 1);
                st.insert(s[j]);
            }
        }
        int len = st.size();
        ans = max(ans, len);
        return ans;
    }
};
int main()
{
    string s = " ";
    cout << lengthOfLongestSubstring(s);
    return 0;
}