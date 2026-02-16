#include<iostream>
using namespace std;
int reverseBits(int n)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans <<= 1;
        ans |= (n & 1);
        n >>= 1;
    }
    return ans;
}
    int main(){
        int n = 43261596;
        cout << reverseBits(n);
        return 0;
    }