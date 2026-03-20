#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>&arr){
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid<= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for(int ele : arr){
        cout << ele << " ";
    }
    return;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    cin.ignore();
    string s;
    getline(cin, s);
    if(s.front() == '[' and s.back() == ']'){
        s = s.substr(1, s.length() - 2);
    }
    stringstream ss(s);
    string str = "";
    while(getline(ss , str , ',')){
        int no = stoi(str);
        arr.push_back(no);
    }
    fun(arr);
    return 0;
}