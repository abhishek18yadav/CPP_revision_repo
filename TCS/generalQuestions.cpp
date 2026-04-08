#include<bits/stdc++.h>
using namespace std;

// anagram, fibonacci , armstrong , tribonacci
bool checkAnagram(string s1 , string s2){
    unordered_map<char, int> mp;
    for (int i = 0; i < s1.length(); i++)
        mp[s1[i]]++;
    for (int i = 0; i < s2.length(); i++){
        if(mp[s2[i]] == 0)
            return false;
        mp[s2[i]]--;
    }
    for(auto ele : mp){
        if(ele.second != 0)
            return false;
    }
    return true;
}
int fibo (int n){
    if(n == 0 or n == 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}
bool armstringNo(int n){
    int ori = n;
    int sum = 0;
    while(n >0){
        int rem = n % 10;
        sum += rem * rem * rem;
        n /= 10;
    }
    if(sum == ori)
        return true;
    return false;
}
int tribonacci(int n){
    if(n == 0 or n == 1 or n == 2)
        return n;
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}
int main(){
    string s1 = "listen", s2 = "silent";
    cout << checkAnagram(s1, s2) << endl;
    int n = 2;
    cout << fibo(n) << endl;
    n = 153;
    cout << armstringNo(n) << endl;
    n = 4;
    cout << tribonacci(n) << endl;
}