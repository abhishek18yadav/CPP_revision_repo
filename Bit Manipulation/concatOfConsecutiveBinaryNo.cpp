#include <bits/stdc++.h>
using namespace std;

    int concatenatedBinary(int n)
    {
        long digit = 0;
        long res = 0, mod = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            if ((i & (i - 1)) == 0)
                digit++;
            res = ((res << digit) % mod + i) % mod;
        }
        return res;
    }

    int main()
    {
        int n = 3;
        cout << concatenatedBinary(n) << endl;
        return 0;
    }