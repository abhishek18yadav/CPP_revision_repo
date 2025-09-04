#include <bits/stdc++.h>
using namespace std;

bool IsGreatest(int currentcandy, int maxCandy)
{
    // cout<<"currentcandy"<<currentcandy<<"maxCandy"<<maxCandy<<endl;
    return currentcandy >= maxCandy;
}
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int size = candies.size();
    int maxCandy = 0;
    for (int i = 0; i < size; i++)
    {
        maxCandy = max(maxCandy, candies[i]);
    }
    vector<bool> res(size);
    for (int i = 0; i < size; i++)
    {
        int currentcandy = candies[i] + extraCandies;
        if (IsGreatest(currentcandy, maxCandy))
        {
            // cout<<"i"<<i<<"true"<<endl;
            res[i] = true;
        }
        else
            res[i] = false;
    }
    return res;
}

int main()
{
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = kidsWithCandies(candies, extraCandies);
    for (bool val : result)
    {
        cout << (val ? "true" : "false") << " ";
    }
    return 0;
}