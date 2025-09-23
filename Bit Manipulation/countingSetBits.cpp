#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){

    return __builtin_popcount(n);
}
int custom_builtinPopCount(int n ){
    int count = 0;
    while(n>0){
        count++;
        n = n & n - 1;
    }
    return count;
}
int main(){
    cout << countSetBits(45)<<'\n';
    cout << custom_builtinPopCount(45)<<'\n';
    return 0;
}