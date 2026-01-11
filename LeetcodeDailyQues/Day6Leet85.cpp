#include <bits/stdc++.h>
using namespace std;

vector<int> LeftNextSmall(vector<int> &heights)
{
    int sz = heights.size();
    stack<int> idx;
    vector<int> lns(sz);
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
    vector<int> rns(sz);
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

    vector<int> r = RightNextSmall(heights);

    for (int i = 0; i < sz; i++)
    {
        vals[i] = (r[i] - l[i] - 1) * heights[i];
        maxVal = max(maxVal, vals[i]);
    }
    return maxVal;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> matrixInt(matrix.size(), vector<int>(matrix[0].size()));
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            matrixInt[i][j]=matrix[i][j]-'0';
        }
    }

    int res = INT_MIN;
    for (int i = 0; i < matrixInt.size(); i++)
    {
        vector<int> heights(matrixInt[i].size());
        for (int j = 0; j < matrixInt[i].size(); j++)
        {
            if (i == 0)
            {
                heights[j] = matrixInt[i][j];
            }
            else
            {
                if (matrixInt[i][j] == '0')
                    heights[j] = 0;
                else
                {

                    matrixInt[i][j] = (matrixInt[i][j]) + (matrixInt[i - 1][j]);
                    heights[j] = matrixInt[i][j];
                }
            }
        }
        int ans = largestRectangleArea(heights);
        res = max(res, ans);
    }
    return res;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix) << endl;
    
    
    return 0;
}