#include<bits/stdc++.h>
using namespace std;



int maxDistinct(string s)
{
   
    unordered_set<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.insert(s[i]);
    }
    return st.size();
}

int main(){
    cout<<maxDistinct("abc");
    return 0;
}