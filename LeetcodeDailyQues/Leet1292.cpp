#include<bits/stdc++.h>
using namespace std;
//  |(i,j)-                         |
    //  |      -                        |
    //  |       -                       |
    //  |         - ( btmRT_r,btmrt_col)|


    int findSum(int r, int c , int btmRt_ro , int btmRt_col , vector<vector<int>>&pref){
        // int r = pref.size();
        // int c = pref[0].size();
        // we have to find submatrix sum from r,c to btmr , btmco
        int sum = pref[btmRt_ro][btmRt_col] - 
                  (r-1 >=0 ? pref[r-1][btmRt_col] : 0) - 
                 (c-1 >=0 ?  pref[btmRt_ro][c-1]  : 0) + 
                 ((r-1>=0 and c-1>=0) ? pref[r-1][c-1] : 0); // <--- this was subs twicw in performing upper two operations

        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // 1. prefix sum of whole matrix
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>>pref(r,vector<int>(c)); 
        for(int i=0; i<r; i++){
            for(int j = 0; j<c; j++){
                pref[i][j] = (i-1>=0 ? pref[i-1][j] : 0)  + 
                            ( j-1>=0 ? pref[i][j-1]  : 0)  - 
                            ((i-1>=0 and j-1 >=0) ? pref[i-1][j-1] : 0) +
                            mat[i][j];
            }
        }
        //2. now visiting each grid and finding max side
        int maxSide=0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                // offset here to help in traversing diagonally
                // and if offset = 0 then  -> 1 unit grid , i.e. side = 1(offset+1)
                // if offset = 1 then -> side of sq = 2(offset+1)
                for(int offset = 0 ; offset < min(r-i,c-j); offset++){
                    int sum = findSum(i,j, i+offset , j+offset, pref);
                    if(sum <= threshold){
                        maxSide = max(maxSide , offset+1);
                    }else break;
                }
            }
        }
        return maxSide;
    }
    int main(){
        vector<vector<int>>mat = {
            {2,2,2,2,2},
            {2,2,2,2,2},
            {2,2,2,2,2},
            {2,2,2,2,2},
            {2,2,2,2,2}
        };
        int threshold = 1;
        cout<<maxSideLength(mat,threshold);
        return 0;
    }