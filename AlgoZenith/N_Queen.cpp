#include <bits/stdc++.h>
using namespace std;
    vector<vector<string>> ans;

    bool valid(vector<string> &rw, int i, int j)
    {
        // col
        for (int z = i; z >= 0; z--)
        {
            if (rw[z][j] == 'Q')
                return false;
        }
        // left diag
        for (int x = i, y = j; x >= 0 && y >= 0; x--, y--)
        {
            if (rw[x][y] == 'Q')
                return false;
        }
        // right diag
        for (int x = i, y = j; x >= 0 && y < rw[0].size(); x--, y++)
        {
            if (rw[x][y] == 'Q')
                return false;
        }
        return true;
    }
    void f(vector<string> &rw, int i)
    {
        if (i == rw.size())
        {
            ans.push_back(rw);
            return;
        }
        for (int j = 0; j < rw[i].size(); j++)
        {
            if (valid(rw, i, j))
            {
                rw[i][j] = 'Q';
                f(rw, i + 1);
                rw[i][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> rw(n, string(n, '.'));
        f(rw, 0);
        return ans;
    }

    int main()
    {
        int n = 4;
        vector<vector<string>> res = solveNQueens(n);
        for (auto &board : res)
        {
            for (auto &row : board)
            {
                cout << row << endl;
            }
            cout << endl;
        }
        return 0;
    }