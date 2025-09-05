#include<bits/stdc++.h> 
using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        unordered_set<int>st;
        for(auto ele : mp){
            if(!st.count(ele.second)){
                st.insert(ele.second);
            }
            else return false;
        }
        return true;
    }


    int main(){
        vector<int>arr = {1,2,2,1,1,3};
        cout<<uniqueOccurrences(arr);
    }