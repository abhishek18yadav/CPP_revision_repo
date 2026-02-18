#include<bits/stdc++.h>
using namespace std;

int main(){
    string day;
    cin >> day;
    int ds;
    cin >> ds;
    unordered_map<string, char> mp = {
        {"mon", 6},
        {"tue", 5},
        {"wed", 4},
        {"thu", 3},
        {"fri", 2},
        {"sat", 1},
        {"sun", 0},
    };
    int noSun = 0;
    if(ds-mp[day] >=0)
        noSun++;
    ds -= mp[day];
    noSun += (ds / 7);
    cout << noSun;
    return 0;
}