#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;
void f(int n, int idx, int k)
{
    if(idx > n)
    {
        if(temp.size() == k)
            ans.push_back(temp);
        return;
    }
    temp.push_back(idx);
    f(n, idx + 1, k);
    temp.pop_back();
    f(n, idx + 1, k);
    return;
}
vector<vector<int>> combine(int n, int k)
{
    int idx = 1;
    f(n, idx, k);
    return ans;
}
int main()
{
    int n = 4, k = 3;
    vector<vector<int>> ans = combine(n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}