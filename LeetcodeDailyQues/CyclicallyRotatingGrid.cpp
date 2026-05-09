#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m / 2, n / 2);
        for (int l = 0; l < layers; l++)
        {
            int top = l;
            int bottom = m - 1 - l;
            int left = l;
            int right = n - 1 - l;

            vector<int> nums;
            // left
            for (int i = top; i < bottom; i++)
            {
                nums.push_back(grid[i][left]);
            }
            // bottom
            for (int j = left; j < right; j++)
            {
                nums.push_back(grid[bottom][j]);
            }
            // right
            for (int i = bottom; i > top; i--)
            {
                nums.push_back(grid[i][right]);
            }
            // top
            for (int i = right; i > left; i--)
            {
                nums.push_back(grid[top][i]);
            }
            int len = nums.size();
            int rot = k % len;
            rotate(nums.rbegin(), nums.rbegin() + rot, nums.rend());
            // now updatin time
            // left
            int numsIdx = 0;
            for (int i = top; i < bottom; i++)
            {
                grid[i][left] = nums[numsIdx++];
            }
            // bottom
            for (int j = left; j < right; j++)
            {
                grid[bottom][j] = nums[numsIdx++];
            }
            // right
            for (int i = bottom; i > top; i--)
            {
                grid[i][right] = nums[numsIdx++];
            }
            // top
            for (int i = right; i > left; i--)
            {
                grid[top][i] = nums[numsIdx];
                if (numsIdx < nums.size())
                    numsIdx++;
                else
                    break;
            }
        }
        return grid;
    }

int main(){
    vector<vector<int>>grid = {{2, 4, 8, 10}, {3, 6, 9, 16}, {5, 7, 11, 15}, {1, 12, 14, 20}};
    vector<vector<int>> res = rotateGrid(grid, 1);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}