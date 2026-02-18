#include<bits/stdc++.h>
using namespace std;

void fun(string &str){
    unordered_map<char, int> mp;
    for (int i = 0; i < str.length(); i++){
        mp[str[i]]++;
    }
    for(char ele : str){
        if(mp[ele] %2 != 0){
            cout << ele << " ";
            return;
        }
    }
    cout << "all are even";
}
int main(){
    int n;
    cin >> n;
    cin.ignore();
    string str;
    cin >> str;
    fun(str);
    return 0;
}