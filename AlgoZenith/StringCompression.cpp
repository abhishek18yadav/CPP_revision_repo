#include<bits/stdc++.h>
using namespace std;

int f(vector<char>&map){
    char ch = 'a';
    map[0] = ch;
    for (int i = 1; i < 26; i++){
        ch++;
        map[i] = ch;
    }
    ch = 'A';
    map[26] = ch;
    for (int i = 27; i < 52; i++)
    {
        ch++;
        map[i] = ch;
    }
    ch = '0';
    map[52] = ch;
    for (int i = 53; i < 62; i++)
    {
        ch++;
        map[i] = ch;
    }
}
string fun(int no){
    vector<char> map(62);
    f(map);
 
    string ans = "";
    while(no>=0){
        int rem = no % 62;
        char mappedChar = map[rem];
        ans += mappedChar;
        cout << mappedChar << " ";
        no  = no/62;
    }
    return ans;
}

int main(){
    // fun(54321);
    cout << 54321 % 62;
    return 0;
}