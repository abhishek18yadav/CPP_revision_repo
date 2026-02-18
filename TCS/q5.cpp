#include<bits/stdc++.h>
using namespace std;

void fun(vector<string>&arr){
    cout << "s1";
    unordered_map<char, int> mp;
    vector<char> idxes;
    string ele = arr[0];
    for (int i = 0; i < ele.length(); i++){
        mp[ele[i]]++;
        idxes.push_back(ele[i]);
    }
    ////
    for (int i = 0; i < idxes.size();i++)
        cout << idxes[i] << " ";
        for (auto ele : mp)
        {
            cout << ele.first << ":" << ele.second << endl;
        }
    /////
        for (int i = 1; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].length();j++){
                if(idxes[j] == arr[i][j])
                    mp[idxes[j]]++;
                else
                    break;
            }
        }
        for (int i = 0; i < idxes.size(); i++){
            if(mp[idxes[i]] % arr.size() == 0)
                cout << idxes[i] << " ";
        }
}
int  main(){
    string s;
    getline(cin, s);
    if(s.front() == '[' and s.back() == ']'){
       s= s.substr(1, s.length() - 2);
    }
    vector<string> arr;
    stringstream ss(s);
    string str = "";
    while(getline(ss , str,',')){
        arr.push_back(str);
    }
    fun(arr);
    
    return 0;
}