#include<bits/stdc++.h>
using namespace std;
int f(vector<vector<string>> &arr){
    int maxVal = INT_MIN;
    for (int i = 0; i< arr.size(); i++){
        string str1 = arr[i][0];
        string str2 = arr[i][1];
        int val = stoi(str1 , nullptr , 2) + stoi(str2 , nullptr , 2);
        maxVal = max(maxVal , val);
    }
    return maxVal;
}
int main(){
    int sz;
    cin >> sz;
    vector<vector<string>> arr;
    for (int i = 0; i < sz; i++){
        vector<string> temp;
        for (int j = 0; j < 2; j++){
            string str;
            cin >> str;
            temp.push_back(str);
        }
        arr.push_back(temp);
    }
    int res = f(arr);
    string ans = "";
    while(res>0){
        if(res%2 ==1){
            ans = '1' + ans;
        }else{
            ans = '0' + ans;
        }
        res = res >> 1;
    }
    cout << ans << endl;
    return 0;
}