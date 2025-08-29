#include <bits/stdc++.h>
using namespace std;

bool CanEat(vector<int> &piles, int h, int k)
{
    int hour = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        hour += (piles[i] / k);
        if (piles[i] % k != 0)
            hour++;
        if (hour > h)
            return false;
    }
    return hour <= h;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (CanEat(piles, h, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}