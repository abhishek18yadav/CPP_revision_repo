#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>&arr){
    int maxele = -1;
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        if(arr[i]>maxele){
            count++;
            maxele = arr[i];
        }
    }
    cout << count << " ";
}
int main(){
    // string s;
    // getline(cin, s);
    // vector<int> arr;
    // stringstream ss(s);
    // string str = "";
    // while(getline(ss,str,' ')){
    //     int ele = stoi(str);
    //     arr.push_back(ele);
    // }
    int n;
    cin >> n;

    int ele;
    vector<int> arr;
    for (int i = 0; i < n; i++){
        cin >> ele;
        arr.push_back(ele);
    }
        fun(arr);
    return 0;
}