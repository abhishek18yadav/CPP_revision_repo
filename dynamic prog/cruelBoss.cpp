// its an algo zenith
#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    int path1 = f(n - 1);
    int path2 = f(n - 3);
    return path1 + path2;
}
int PossibleBundle(int noOfFiles){
    return f(noOfFiles);
}
int main(){
    cout << PossibleBundle(20);
    return 0;
}