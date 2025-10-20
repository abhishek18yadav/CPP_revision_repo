// Write your code here
#include <bits/stdc++.h>
using namespace std;
long long countDiv(vector<long long> &res)
{
    for (long long i = 2; i < res.size(); i++)
    {
        for (long long j = 1; j < i; j++)
        {
            if (res[i] % res[j] == 0)
            {
                res.erase(res.begin() + i);
                break;
            }
        }
    }
    return res.size();
}
long long FindDiv(long long no1, long long no2)
{
    vector<long long> res;
    for (long long i = 1; i <= no1; i++)
    {
        if (no1 % i == 0 and no2 % i == 0)
            res.push_back(i);
    }
    for(int ele : res){
        cout << ele << " ";
    }
    return countDiv(res);
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
        // long long no1, no2;
        // cin >> no1 >> no2;
        long long res = FindDiv(12, 18);
        cout << res << endl;
    // }

    return 0;
}