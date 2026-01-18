#include <bits/stdc++.h>
using namespace std;

    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
    {
        long long maxSide = -11000;
        for (int i = 0; i < bottomLeft.size() - 1; i++)
        {
            // calculating top right and bottom left of intersection region
            for (int j = i + 1; j < bottomLeft.size(); j++)
            {
                int top_x = min(topRight[j][0], topRight[i][0]);
                int top_y = min(topRight[j][1], topRight[i][1]);
                int bottom_x = max(bottomLeft[j][0], bottomLeft[i][0]);
                int bottom_y = max(bottomLeft[j][1], bottomLeft[i][1]);
                // for side , min of height ans widht
                int wid = (top_x - bottom_x);
                int hei = (top_y - bottom_y);

                long long side = min(wid, hei);
                if (wid < 0 or hei < 0)
                    side = 0;
                maxSide = max(side, maxSide);
            }
        }
        return maxSide * maxSide;
    }


    int main(){
        vector<vector<int>> bottomLeft = {{1, 1}, {3,3}, {3,1}};
        vector<vector<int>> topRight = {{2,2},{4,4},{4,2}};
        cout << largestSquareArea(bottomLeft, topRight);

        return 0;
    }