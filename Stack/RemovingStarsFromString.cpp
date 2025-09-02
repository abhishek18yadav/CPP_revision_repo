#include<iostream>
#include<stack>
using namespace std;

string removeStars(string s) {
    stack<char>st,revSt;
    for(int i=0; i<s.length(); i++){

        if(s[i]=='*'){
            st.pop();
        }
        else st.push(s[i]);
    }
    string ans="";
    while(!st.empty()){
        char c1= st.top();
        revSt.push(c1);
        st.pop();
    }
    while(!revSt.empty()){
        char c2 = revSt.top();
        revSt.pop();
        ans+=c2;
    }
    return ans;
}


int main(){

    string result = removeStars("esrase*****");
    cout<<result<<endl;
    return 0;
}