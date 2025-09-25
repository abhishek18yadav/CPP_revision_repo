
// Write your code here
// Write your code here
#include <bits/stdc++.h>
using namespace std;

int last(vector<int> &arr)
{
    int val = 1;
    int dizit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            return -1;
        val *= arr[i];
    }
    // cout << val << " ";
    string v = to_string(val);
    int len = v.length();
    for (int i = 0; i < len; i++)
    {
        int num = v[len - 1 - i] - '0';
        if (num != 0){
            dizit = num;
            break;
        }
        else continue;
    }
    return dizit;
}
int main()
{

    vector<int> arr{3 ,23 ,30, 45};
    // int diz;
    // cin >> diz;
    
    cout << last(arr) << endl;
    return 0;
}