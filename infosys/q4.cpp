#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int xp;
    cin >> xp;
    cin.ignore();
    vector<int> power(n);
    for (int i = 0; i < n;i++){
        cin >> power[i];
    }
    cin.ignore();
    vector<int> bonus(n);
    for (int i = 0; i < n; i++){
        cin>> bonus[i];
    }
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[power[i]] = bonus[i];
    }
    sort(power.begin(), power.end());
    int count = 0;
    for(int i = 0; i < n; i++){
        if(xp >= power[i]){
            xp+=mp[power[i]];
            count++;
        }else{
            continue;
        }
    }
    cout << count << endl;  
    return 0;
}