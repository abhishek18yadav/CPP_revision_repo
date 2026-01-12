#include <bits/stdc++.h>
using namespace std;
int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int ans = 0;
    for (int i = 1; i < points.size(); i++)
    {
        ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    cout << minTimeToVisitAllPoints(points) << endl;
    return 0;
}