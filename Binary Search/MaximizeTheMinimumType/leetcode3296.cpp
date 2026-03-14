
#include <bits/stdc++.h>
using namespace std;
#define ll long long
    bool check(ll mid, int mountainHeight, vector<int> &workerTimes)
    {
        ll totalHeight = 0.0;
        for (int t : workerTimes)
        {
            ll h = (ll)(sqrt(2.0 * (mid / t) + 0.5) - 0.5);
            totalHeight += h;
        }
        return totalHeight >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());
        ll left = 1;
        ll right = (ll)maxTime * mountainHeight * (mountainHeight + 1) / 2;
        ll res = 0;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            if (check(mid, mountainHeight, workerTimes))
            {
                right = mid - 1;
                res = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
int main(){
    int mountainHeight = 5;
    vector<int> workerTimes = {1, 2, 3, 4, 5};
    cout<<minNumberOfSeconds(mountainHeight, workerTimes)<<endl;
    return 0;
}