#include<bits/stdc++.h>
using namespace std;

int f(int m, int base){
    vector<int> v;
    while(m >= base){
        v.push_back(m % base);
        m /= base;
    }
    v.push_back(m);
    reverse(v.begin(), v.end());
    int num = v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i] != v[i-1])
            return -1;
        num = num * 10 + v[i];
    }
    return num;
}


int main(){
    int m;
    cin>>m;
    for(int i=2; i<m; i++){
        int num = f(m, i);
        if(num != -1){
            cout<<num<<endl;
            return 0;
        }
    }
    return 0;
}