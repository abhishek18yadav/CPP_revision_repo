#include <bits/stdc++.h>
using namespace std;


    vector<string> ans;
    void f(int idx, vector<char> &arr, string &str, int n)
    {
        if (idx == n)
        {
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            if (idx - 1 >= 0 and str[idx - 1] == arr[i])
                continue;
            str += arr[i];
            f(idx + 1, arr, str, n);
            str.pop_back();
        }
        return;
    }
    string getHappyString(int n, int k)
    {
        vector<char> arr = {'a', 'b', 'c'};
        string str = "";
        f(0, arr, str, n);
        if(k<=ans.size())
            return ans[k-1];
        return " ";
    }
    int main(){
        int n = 3, k = 9;
        cout<<getHappyString(n, k);
    }