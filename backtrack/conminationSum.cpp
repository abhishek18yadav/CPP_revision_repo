#include<bits/stdc++.h>
using namespace std;

vector<int>c;
    vector<vector<int>>ans;
    void f(int idx , int tar , vector<int>&res){
        if(tar == 0){
            ans.push_back(res);
            return;
        }
        if(tar < 0 or idx >= c.size())return;
        for(int i=idx; i<c.size(); i++){
            if(tar - c[i] >=0){
                res.push_back(c[i]);
                f(i , tar - c[i], res);
                res.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        c = candidates;
        // for(int i=0; i<c.size(); i++){
            vector<int>res;
            f(0,target , res);
        // }
        return ans;
    }
    int main(){
        vector<int>candidates = {2,3,6,7};
        int target = 7;
        vector<vector<int>>res = combinationSum(candidates , target);
        for(auto v : res){
            for(auto x : v){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }   