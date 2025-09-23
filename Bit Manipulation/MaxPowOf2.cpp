#include<bits/stdc++.h>
using namespace std;

int maxPowerOf2ThatIsLessThanX(int x){
    //using logic of set bit
    int temp;
    while(x>0){
        temp = x;
        x = x & (x - 1);
    }
    return temp;
}
// just find next power then divide it , for prevois power
int secondMethod(int x){
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 3);
    x = x | (x >> 4);
    return (x + 1) >> 1;// (x+1) /2
}
int main(){

    cout << maxPowerOf2ThatIsLessThanX(56)<<'\t';
    cout << secondMethod(56);
    return 0;
}