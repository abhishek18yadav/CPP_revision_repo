#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> ch;
    unordered_map<char, char> mp = {
        {')', '('},
        {'}', '{'},
        {']', '['}};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
            ch.push(s[i]);
        else
        {
            if (ch.top() == (mp[s[i]]))
                ch.pop();
            else
                return false;
        }
    }
    return ch.empty();
}
int main()
{
    string s = "({[]})";
    cout << isValid(s);
    return 0;
}