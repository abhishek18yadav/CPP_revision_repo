#include<bits/stdc++.h>
using namespace std;

int f(int idx, string &inp){
    int n = 0;
    for (int i = 0; i < inp.length(); i++){
        if(i == idx)
            continue;
        n *= 10;
        n+= inp[i] - '0';
    }
    return n;
}
int main(){
    string inp;
    cin >> inp;
    cin.ignore();
    string dizi;
    cin >> dizi;

    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < inp.length();i++){
        int no = inp[i] - '0';
        mp[no].push_back(i);
    }
    int inpDizi = dizi[0] - '0';
    int ans = INT_MIN;
    for (int i = 0; i< mp[inpDizi].size(); i++){
        ans = max(ans, f(i , inp));
    }
    cout << ans << endl;
}