#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
int f(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 or n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1) + f(n - 2) + f(n - 3);
}
int tribonacci(int n)
{
    dp.resize(38, -1);
    return f(n);
}
int main(){

    int n;
    cout << "Enter the value of n: ";   
    cin >> n;
    cout << "The " << n << "th Tribonacci number is: " << tribonacci(n) << endl;
    return 0;
}