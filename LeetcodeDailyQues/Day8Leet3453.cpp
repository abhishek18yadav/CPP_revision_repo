#include <bits/stdc++.h>
using namespace std;

double range = 1e-5;
double TotalArea = 0.00;

bool check(vector<vector<int>>& squares, double mid, double TotalArea){
    double bottomArea = 0.0;
    for(auto ele : squares ){
        double y = ele[1];
        double len = ele[2];
         double top_y = y + len;
         if(mid >= top_y){
            bottomArea = bottomArea + len * len;
         }
         else if(mid > y && mid < top_y){
            double h = mid - y;
            bottomArea = bottomArea + h * len;
         }
    }
    return (bottomArea >= TotalArea/2.0);
}
    double separateSquares(vector<vector<int>>& squares){
        // find upper limit and lower limit  for biary search on anser(i.e on y);
        int max_y=INT_MIN,min_y = INT_MAX;
        for(auto ele : squares){
            max_y = max(max_y,(ele[1]+ele[2]));
            min_y = min(min_y,(ele[1]));
            TotalArea = TotalArea + ele[2]*ele[2];
        } 
        double ans = 0.0000;
    
        double upperlimit = max_y;
        double lowerlimit = min_y;
        //
        // binary search 
        while((upperlimit - lowerlimit) > range){
            double mid = lowerlimit + (upperlimit-lowerlimit)/2;
            ans = mid;
            if(check(squares,mid,TotalArea)){
                upperlimit = mid;
            }
            else{
                lowerlimit = mid;
            }
        }
        return ans;
    }

    int main(){
        vector<vector<int>> squares = {{0,0,2},{1,1,1}};
        cout<<separateSquares(squares)<<endl;
    }