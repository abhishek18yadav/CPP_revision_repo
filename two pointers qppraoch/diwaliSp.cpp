#include<bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int val = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "X++" or operations[i] == "++X")
            val++;
        else
            val--;
    }
    return val;
}

int main()
{
    vector<string> operations = {"X++", "++X", "--X", "X--"};
    cout << finalValueAfterOperations(operations) << endl;
    return 0;
}