#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&arr){
    if(arr[0] == arr[1] and arr[0] == arr[1])
        return 0;
    sort(arr.begin(), arr.end());
    int steps = 0;
    while(true){
        arr[0]++;
        arr[1]++;
        arr[2]--;
        steps++;
        sort(arr.begin(), arr.end());
        if((arr[0]+1 == arr[1] and arr[1]==arr[2]) or (arr[1]+1 == arr[2] and arr[0] == arr[1]))
            return -1;
        if(arr[0]== arr[1] and arr[0] == arr[2])
            return steps;
        
    }
    return -23;
}
int main(){
    int n = 3;
    vector<int> arr;
    string s;
    getline(cin, s);
    if(s.front() == '[' and s.back() == ']'){
        s = s.substr(1, s.length() - 2);
    }
    stringstream ss(s);
    string str = "";
    while(getline(ss , str , ' ')){
        int ele = stoi(str);
        arr.push_back(ele);
    }
    cout << f(arr);
    return 0;
}