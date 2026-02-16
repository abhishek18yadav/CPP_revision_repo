#include<bits/stdc++.h>
using namespace std;

int main(){
    string week;
    cin >> week;
    int day;
    cin >> day;
    unordered_map<string, int> mp = {
        {"mon", 1},
        {"tue", 2},
        {"wed", 3},
        {"thurs", 4},
        {"fri", 5},
        {"sat", 6},
        {"sun", 0}};
    int diff = 7 - mp[week];
    int ans=  diff == 7 ? 1 + (day / diff) : day / diff;
    cout << ans << " ";
    return 0;
}