#include<bits/stdc++.h>
using namespace std;


// to remember: 1<<x is equal to 2^x
// left shift operator is equivalent to multiplying by 2
// right shift operator is equivalent to dividing by 2
// so, n>>1 is equivalent to n/2
int binaryToDecimal(string n){
    int size = n.length();
    int res = 0;
    for (int i = n.length() - 1; i >= 0; i--){
        int no = (n[i] - '0');
        res += (no * (1 << (size - i - 1)));
    }
    return res;
}

string decimalToBinary(int n){
    string res = "";
    while(n>0){
        if(n%2==0){
            // res += '0'; 
            res= '0'+ res; // to avoid reversing at the end     
        }
        else
            // res += '1';
            res= '1'+ res; // to avoid reversing at the end
        n = n >> 1;
    }
    return res;
}

int main(){
    string n = "111";

    int no = 7;
    cout<<"decimal to binary "<<decimalToBinary(no)<<endl;
    cout<<"binary to decimal "<<binaryToDecimal(n)<<'\n';
    return 0;
}