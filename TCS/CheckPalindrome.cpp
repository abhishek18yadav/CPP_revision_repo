#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s){
    if(s.length() == 1)
        return true;
    int strt = 0, end= s.length() - 1;
    while(strt<end){
        if(s[strt] != s[end])
            return false;
        strt++;
        end--;

    }
    return true;
}
int main(){
    string s = "niti";
    cout << checkPalindrome(s);
    return 0;
}