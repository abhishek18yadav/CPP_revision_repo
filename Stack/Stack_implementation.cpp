#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    vector<int>st;
    Stack(){
        vector<int>st[0];
    }
    void push(int ele){
        st.push_back(ele);

        return;
    }
    void pop(){
      cout<<st.back();
      st.pop_back();
      return;
    }
    int size(){
        return st.size();
    }
     int top(){
        cout<< st.back();
     }
     bool is_empty(){
        return st.size()>0;
     }
};



int main(){
    Stack stck;
    stck.push(1);
    stck.push(2);
    stck.push(3);
    cout<<stck.is_empty();
    stck.pop();
    stck.top();
    return 0;
}
