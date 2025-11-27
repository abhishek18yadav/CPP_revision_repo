#include<bits/stdc++.h>
using namespace std;

// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int r_strt, r_end, c_strt, c_end;
//     int r = matrix.size();
//     int c = matrix[0].size();
//     for (int i = 0; i < r; i++)
//     {
//         if (matrix[i][0] <= target and matrix[i][c - 1] >= target)
//         {
//             for (int j = 0; j < c; j++)
//             {
//                 if (matrix[i][j] <= target and matrix[r - 1][j] >= target)
//                 {
//                     for (int z = i; z <= r - 1; z++)
//                     {
//                         if (matrix[z][j] == target)
//                             return true;
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }

    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //   if(target == 10721)
    //     int r = matrix.size();
    //     int c = matrix[0].size();
    //     for(int i=0; i<r;i++ ){
    //         int mid1 = r/2;
    //         if(matrix[i][0] <= target  and  matrix[i][c-1] >= target){
    //             int mid =
    //             for(int j=0; j<c; j++){
    //                  if(matrix[i][j] <= target  and matrix[r-1][j] >= target){
    //                     for(int z=i; z<=r-1 ;z++){
    //                         if(matrix[z][j] == target)return true;
    //                     }
    //                  }
    //             }

    //         }
    //     }
    //     return false;
    // }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int i = 0, j = c - 1;

        while (i < r and j >= 0)
        {
            int curr_ele = matrix[i][j];
            if (curr_ele == target)
                return true;
            if (curr_ele < target)
            {
                i++;
                continue;
            }
            if (curr_ele > target)
            {
                j--;
            }
        }
        return false;
    }

int main(){
    vector<vector<int>> matrix = {
        {1}
        
    };
    int target = 1;
    bool found = searchMatrix(matrix, target);
    cout << (found ? "Found" : "Not Found") << endl;
    return 0;
}