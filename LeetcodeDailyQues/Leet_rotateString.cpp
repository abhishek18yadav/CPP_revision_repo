#include<bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
        return false;

    string dbl = s + s;
    bool isFound = false;
    for (int i = 0; i < dbl.size(); i++)
    {
        int gitr = 0;
        while (gitr < goal.length())
        {
            if (gitr == goal.length() - 1 and dbl[gitr + i] == goal[gitr])
                return true;
            if (goal[gitr] != dbl[i + gitr])
                break;
            gitr++;
        }
    }
    return isFound;
}

int main(){
    string s = "abcde", goal = "cdeab";
    cout << rotateString(s, goal);
    return 0;
}