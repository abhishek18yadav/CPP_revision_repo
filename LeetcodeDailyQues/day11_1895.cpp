
#include<bits/stdc++.h>
using namespace std;

    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> pref_row(r, vector<int>(c));
        vector<vector<int>> pref_col(r, vector<int>(c));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                pref_row[i][j] = grid[i][j] + (j - 1 >= 0 ? pref_row[i][j - 1] : 0);
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                pref_col[i][j] = grid[i][j] + (i - 1 >= 0 ? pref_col[i - 1][j] : 0);
            }
        }
        for (int side = min(r, c); side >= 2; side--)
        {
            for (int i = 0; i < (r - side + 1); i++)
            {
                for (int j = 0; j < (c - side + 1); j++)
                {
                    int targetSum = pref_row[i][j + side - 1] - (j > 0 ? pref_row[i][j - 1] : 0);
                    bool allsame = true;
                    // for reast of rows
                    for (int rs = i + 1; rs <= (i + side - 1); rs++)
                    {
                        int sum = pref_row[rs][j + side - 1] - (j > 0 ? pref_row[rs][j - 1] : 0);
                        if (sum != targetSum)
                        {
                            allsame = false;
                            break;
                        }
                    }
                    if (!allsame)
                        continue;
                    // for column
                    for (int cls = j; cls <= (j + side - 1); cls++)
                    {
                        int sum = pref_col[i + side - 1][cls] - (i - 1 >= 0 ? pref_col[i - 1][cls] : 0);
                        if (sum != targetSum)
                        {
                            allsame = false;
                            break;
                        }
                    }
                    if (!allsame)
                        continue;

                    // for diagonals
                    int diaSum = 0;
                    int antidia = 0;
                    for (int d = 0; d < side; d++)
                    {
                        diaSum += grid[i + d][j + d];
                        antidia += grid[i + side - 1 - d][j + d];
                    }
                    if (diaSum != targetSum or antidia != targetSum)
                        continue;
                    return side;
                }
            }
        }
    }

    int main()
    {
        vector<vector<int>> grid = {
            {5, 1, 3, 1},
            {9, 3, 3, 1},
            {1, 3, 3, 8}};
        cout << largestMagicSquare(grid) << endl;
        return 0;
    }
