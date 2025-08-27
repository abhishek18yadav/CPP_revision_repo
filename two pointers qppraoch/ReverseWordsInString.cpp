#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string word = "";
    vector<string> st;
    for (int i = 0; i <s.length(); i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            if (word != "" )
            {
                
               // cout<<"word: "<<word<<endl;
                st.push_back(word);
                word = "";
            }
            // cout<<"i: "<<i<<endl;
        }
    }
    st.push_back(word); // for last word
    string ans = "";
    reverse(st.begin(), st.end());

    for (int i = 0; i < st.size(); i++)
    {
        // cout <<st[i];
        
        ans += st[i];
        ans += ' ';
        // cout<<st[i].length()<<endl;
    }
    int left =0,right=ans.length()-1;
    while(ans[left]==' '){
        left++;
    }while(ans[right]==' '){
        right--;
    }
    ans = ans.substr(left,right-left+1);
    //cout<<"ans: "<<ans<<endl;

    return ans;
}
int main(){
    string s = "  hello world  ";
    cout<<reverseWords(s);
    return 0;

}