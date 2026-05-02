#include<bits/stdc++.h>
using namespace std;
int rotatedDigits(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int digi = i;
        bool isValid = true;
        bool good = false;
        while (digi > 0)
        {
            int no = digi % 10;
            digi /= 10;
            if (no == 2 or no == 5 or no == 6 or no == 9)
            {
                good = true;
            }
            if (no == 3 or no == 4 or no == 7)
            {
                isValid = false;
                break;
            }
        }
        if (isValid and good)
        {
            count++;
        }
    }
    return count;
}
    int main(){
        int n = 10; 
        cout<<rotatedDigits(n);
        return 0;
    }