#include<bits/stdc++.h>
using namespace std;

int  method1(int no){
    // firstly exactly next pow of 2
    int originalNo = no;
    int temp = 0;
    while(no>0){
        temp = no;
        no = no & (no - 1);
    }
    int nextPow = temp * 2;
    int res =  originalNo ^ (nextPow - 1);
    return res;
    // minus one to get all dizit 1 of same size as of size of no , ofcourse in binary form
    // then we take xor to find the flipped no in decimal
    
}

int main(){
    cout << method1(7); // 111 --> 000
    
    return 0;
}