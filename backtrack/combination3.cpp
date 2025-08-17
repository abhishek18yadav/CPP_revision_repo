#include <bits/stdc++.h>
using namespace std;


void f(int strt, int n, int k, vector<int> &com, vector<vector<int>> &res)
{
    if (n == 0 and com.size() == k)
    {
        res.push_back(com);
        return;
    }
    if (n < 0 or com.size()> k)
        return;

    for (int j = strt; j <= 9; j++)
    {
        com.push_back(j);
        f(j + 1, n - j, k, com, res);
        com.pop_back();
        
    }
    return;
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> com;
    vector<vector<int>> res;
    f(1, n, k, com, res);
    return res;
}

int main()
{
    int k = 3, n = 7;
    vector<vector<int>> result = combinationSum3(k, n);
    for (auto elem : result)
    {
        for (int num : elem)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}