 #include <bits/stdc++.h>
using namespace std;

// Memoization      
int f(int r, int c, vector<vector<int>>& grid){
   if(r == grid.size()-1 and c == grid[0].size()-1){
    return grid[r][c];
   }
   if(r>= grid.size() or c>= grid[r].size() or c<0)return INT_MAX;
    
    int right = f(r , c+1 , grid);
    int down =  f(r+1 , c, grid);
    int ans =  min(right , down);
    return grid[r][c] + ans;
}
int minPathSum(vector<vector<int>>& grid) {
    
    return f(0,0,grid);
}
int main() {
    vector<vector<int>> grid = {{1,2,3}};
    cout << minPathSum(grid) << endl; // Output: 7
    return 0;
}