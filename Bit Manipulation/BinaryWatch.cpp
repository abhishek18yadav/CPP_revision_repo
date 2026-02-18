#include<bits/stdc++.h>
using namespace std;
vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> ans;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            int hr = i;
            int min = j;
            if (__builtin_popcount(hr) + __builtin_popcount(min) == turnedOn)
            {
                string temp = to_string(hr);
                temp += ':';
                temp += (min < 10) ? "0" : "";
                temp += to_string(min);
                ans.push_back(temp);
            }
        }
    }
    return ans;
}
int main(){
    int turnedOn = 3;
    vector<string> res = readBinaryWatch(turnedOn);
    for(auto ele: res)
        cout << ele << " ";
    return 0;
}
