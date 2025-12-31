#include <bits/stdc++.h>
using namespace std;
bool f(int si , int pi , string &s , string &p){
    if(pi == p.length()){
        return si == s.length();
    }
    bool sameChar = false;
    if(si< s.length() and (s[si] == p[pi]  or p[pi] == '.'))sameChar = true;
        // if(p[pi]== '.')return f(si + 1, pi+1, s,p);
    if(p[pi+1] == '*'){
        int nottake = f(si , pi+2 , s,p);
        int take = (sameChar  and  f(si+1 , pi , s,p));
        return take or nottake;
        }
    else if(p[pi]== '.')return f(si + 1, pi+1, s,p);
    else {
        return ( si < s.length() and pi < p.length() and s[si] == p[pi]  and f(si+1 , pi+1 , s , p));
    }
    return false;
}
bool isMatch(string s, string p) {
    return f(0,0,s,p);
}

int main(){
string s = "aab";
string p = "c*a*b";
cout<<isMatch(s,p);
    return 0;
}