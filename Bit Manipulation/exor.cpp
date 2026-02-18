#include<bits/stdc++.h>
using namespace std;

/**
 * 1 0 ->1
 * 1 1-> 0
 * 0 1 ->1
 * 0 0 ->0
 */
int main(){
    // int n;
    // cin >> n;
    // char ch;
    // vector<char> arr;
    // for (int i = 0; i < n; i++){
    //     cin >> ch;
    //     arr.push_back(ch);
    // }
    vector<char> arr = {'a', 'a', 'b', 'c', 'c'};
    char ans = arr[0];
    cout << endl;
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans;
    return 0;
}