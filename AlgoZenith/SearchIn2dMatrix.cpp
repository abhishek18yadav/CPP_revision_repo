#include <bits/stdc++.h>
using namespace std;

    bool isFound(vector<int> &arr, int tar)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == tar)
                return true;
            else if (arr[mid] < tar)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<int> arr;
        int r = matrix.size();
        int c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                arr.push_back(matrix[i][j]);
            }
        }
        return isFound(arr, target);
    }
    int main()
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 3;
        bool result = searchMatrix(matrix, target);
        if (result)
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
        return 0;
    }
