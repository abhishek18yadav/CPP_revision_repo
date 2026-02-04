#include <bits/stdc++.h>
using namespace std;



const long long inf = 1e15;
vector<int> n;
long long f(int idx, int trend)
{
    if (idx == n.size())
        return (trend == 3) ? 0 : -inf;
    long long sum = -inf;
    if (trend == 0)
    {
        long long notPick = f(idx + 1, 0);
        long long pick = n[idx] + f(idx + 1, 1);
        sum = max(sum, max(notPick, (idx + 1 < n.size() and n[idx + 1] > n[idx]) ? pick : sum));
    }
    if (trend == 1 and idx + 1 < n.size())
    {
        if (n[idx + 1] > n[idx])
            return sum = max(sum, n[idx] + f(idx + 1, trend));
        else if(n[idx + 1] < n[idx])
            return sum = max(sum, n[idx] + f(idx + 1, trend + 1));
    }
    if (trend == 2 and idx + 1 < n.size())
    {
        if (n[idx + 1] < n[idx])
            return sum = max(sum, n[idx] + f(idx + 1, trend));
        else if(n[idx + 1] > n[idx])
            return sum = max(sum, n[idx] + f(idx + 1, trend + 1));
    }
    if (trend == 3)
    {
        sum = n[idx]; // thinking of starting for next phase
        if (idx + 1 < n.size() and n[idx + 1] > n[idx])
            return sum = max(sum, n[idx] + f(idx + 1, 3));
    }
    return sum;
}
long long maxSumTrionic(vector<int> &nums)
{
    n = nums;
    return f(0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1,4,2,2,3,1,2};
    cout << "Max Sum Trionic: " << maxSumTrionic(nums) << endl;

    return 0;
}
