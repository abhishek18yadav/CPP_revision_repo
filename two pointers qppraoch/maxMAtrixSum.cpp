#include<bits/stdc++.h>
using namespace std;


    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long sum = 0;
        int negative_val = 0;
        int min_val = INT_MAX;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                int val = (matrix[i][j]);
                if (val < 0)
                {
                    negative_val++;
                    val = abs(val);
                }
                min_val = min(min_val, val);
                sum += val;
            }
        }
        if (negative_val % 2 == 0)
            return sum;
        return sum - 2 * min_val;
    }

    int main()
    {
        vector<vector<int>> matrix = {{-1, -2, -3}, {-4, 5, 6}, {7, 8, 9}};
        cout << maxMatrixSum(matrix) << endl;
        return 0;
    }