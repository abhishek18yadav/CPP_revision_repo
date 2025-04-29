#include<bits/stdc++.h>
using namespace std;


class Queue{
    public:
    vector<int>qu;
    Queue(){
        vector<int>qu[0];
    }
    void push(int ele){
        qu.push_back(ele);
        return;
    }

    void pop(){
        cout<<qu.front();
        qu.erase(qu.begin());
        return;
    }
    int size(){
        return qu.size();
    }
    bool is_empty(){
        return !qu.size()>0;
    }

    int front(){
        return qu[0];
    }

    int back(){
        return qu[qu.size()-1];
    }
};

int main(){
    Queue que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    cout<<que.is_empty();
    cout<<que.front();
    cout<<que.back();
    return 0;
}