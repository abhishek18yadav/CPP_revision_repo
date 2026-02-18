/**
 * 1st -> simple
 * 2nd space based separation
 * 3rd commma based separartion
 */

#include <bits/stdc++.h>
using namespace std;

void fun(vector<int> &arr)
{

    for (int ele : arr)
    {
        cout << ele << " ";
    }
}
int main()
{
    // int n;
    // cin >> n;
    // vector<int> arr;
    // int ele;
    // for (int i = 0; i < n; i++){
    //     cin >> ele;
    //     arr.push_back(ele);
    // }
    // fun(arr);
    int n;
    cin >> n;
    cin.ignore();
    vector<int> arr;
    string s;
    getline(cin, s);
    cout << 'n' << n << ' ' << s << endl;
    if (s.front() == '[' and s.back() == ']')
        s = s.substr(1, s.length() - 2);

    stringstream ss(s);

    string str = "";
    while (getline(ss, str, ' '))
    {
        int num = stoi(str);
        arr.push_back(num);
    }
    fun(arr);
    return 0;
}