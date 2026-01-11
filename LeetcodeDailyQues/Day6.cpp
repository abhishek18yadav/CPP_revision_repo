#include<bits/stdc++.h>
using namespace std;
vector<int> LeftNextSmall(vector<int> &heights)
{
    int sz = heights.size();
    stack<int> idx;
    vector<int> lns(sz );
    for (int i = 0; i < sz; i++)
    {
        if (i == 0)
        {
            lns[i] = -1;
            idx.push(i);
        }
        else
        {
            while (!idx.empty() and heights[i] <= heights[idx.top()])
                idx.pop();
            if (idx.empty())
                lns[i] = -1;
            else
                lns[i] = idx.top();
            idx.push(i);
        }
    }
    return lns;
}
vector<int> RightNextSmall(vector<int> &heights)
{
    int sz = heights.size();
    stack<int> idx;
    vector<int> rns(sz );
    for (int i = sz - 1; i >= 0; i--)
    {
        if (i == sz - 1)
        {
            rns[i] = sz;
            idx.push(i);
        }
        else
        {
            while (!idx.empty() and heights[i] <= heights[idx.top()])
                idx.pop();
            if (idx.empty())
                rns[i] = sz;
            else
                rns[i] = idx.top();
            idx.push(i);
        }
    }
    return rns;
}
int largestRectangleArea(vector<int> &heights)
{
    int sz = heights.size();
    int maxVal = INT_MIN;
    vector<int> vals(sz);
    vector<int> l = LeftNextSmall(heights);
    for(int i=0;i<sz;i++)
    {
        cout<<l[i]<<" ";
    }
    vector<int> r = RightNextSmall(heights);
    for(int i=0;i<sz;i++)
    {
        cout<<r[i]<<" ";
    }
    for (int i = 0; i < sz ; i++)
    {
        vals[i] = (r[i] - l[i] - 1) * heights[i];
        maxVal = max(maxVal, vals[i]);
    }
    return maxVal;
}

int main()
{
    vector<int> heights = {2,4};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}