
#include<bits/stdc++.h>
using namespace std;
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> res(n, vector<char>(m));
        // transpose
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[j][i] = boxGrid[i][j];
            }
        }
        // reverse for transpose
        for (int i = 0; i < n; i++)
        {
            reverse(res[i].begin(), res[i].end());
        }
        // now applying gravity
        for (int c = 0; c < m; c++)
        {
            int gapIdx = -1;
            for (int r = n - 1; r >= 0; r--)
            {
                if (gapIdx == -1 and res[r][c] == '.')
                {
                    gapIdx = r;
                }
                else if (res[r][c] == '#' and gapIdx != -1)
                {
                    res[r][c] = '.';
                    res[gapIdx][c] = '#';
                    gapIdx--;
                }
                else if (res[r][c] == '*')
                    gapIdx = -1;
            }
        }
        return res;
    }
    int main(){
        vector<vector<char>>boxGrid={{'#','.','#'}};
        vector<vector<char>>ans = rotateTheBox(boxGrid);
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[0].size(); j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

        return 0;
    }