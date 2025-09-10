#include<bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate)
{
    int size = senate.length() - 1;
    queue<int> rad, dire;
    for (int i = 0; i <=size; i++)
    {
        if (senate[i] == 'R'){
            rad.push(i);
            cout<<"r"<<i<<" ";
        }
        else{
            dire.push(i);
            cout<<"d"<<i<<" ";
        }
            
    }
    int n = 1;
    while (!rad.empty() and !dire.empty())
    {
        if (rad.front() < dire.front())
        {
            rad.push(size + n);
            n++;
        }
        else
        {
            dire.push(size + n);
            n++;
        }
        rad.pop();
        dire.pop();
    }
    if (rad.empty())
        return "Dire";
    else
        return "Radiant";
}

int main(){
    string senate = "RDD";
    cout<<predictPartyVictory(senate);
    return 0;
}