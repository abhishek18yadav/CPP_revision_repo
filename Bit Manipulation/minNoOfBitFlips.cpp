#include<bits/stdc++.h>
using namespace std;

int NoOfFlipsToConvertIntoAnotherNumber(int n1 , int n2){
    // first we takeout xor for diiferent dizits in both and then we count no of 1s using brian karnigans way or __builtin_popcount()
    int intermiaryNo = n1 ^ n2;
    int count = 0;
    while(intermiaryNo > 0){
        count++;
        intermiaryNo = (intermiaryNo & (intermiaryNo - 1));
    }
    return count;
}

int main(){
    cout << NoOfFlipsToConvertIntoAnotherNumber(1, 2);
    return 0;
}