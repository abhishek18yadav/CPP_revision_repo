#include<bits/stdc++.h>
using namespace std;

string repeatedString(string &str , int k){
    string res = "";
    for (int i = 0; i < k; i++){
        res += str;
    }
    return res;
}
string reverseStack(stack<char>&st){
    stack<char> temp;
    string ans = "";
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }

    while(!temp.empty()){
        ans += temp.top();
        temp.pop();
    }
    return ans;
}
string decodeString(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++){
        if(s[i]==']'){
            string str = "";
            while(st.top() != '['){
                str += st.top();
                st.pop();
            }
            st.pop();// removes [
            string digi = "";
            while(!st.empty() && isdigit(st.top()) ){
                // cout<<st.top()<<endl;
                // num = num*10 + (st.top() - '0');
                digi += st.top();
                st.pop();
            }
            reverse(digi.begin(), digi.end());
            int k = stoi(digi);
            cout<<k<<endl;
            string ans = repeatedString(str, k);
            cout<<ans<<endl;
            reverse(ans.begin(), ans.end());
            for (int j = 0; j < ans.length(); j++){
                st.push(ans[j]);
            }
            continue;
        }
        st.push(s[i]);
    }
    // now reverse stack;

    string res = reverseStack(st);
    // reverse(res.begin(), res.end());
    return res;
}

int main(){
    string s = "30[a]";
    cout<<decodeString(s);

    return 0;
}