#include <bits/stdc++.h>
using namespace std;
    int minFlips(string s)
    {
        string q = s + s;
        cout<<q << endl;
        string z = "0";
        string o = "1";
        for (int i = 1; i < q.length(); i++)
        {
            if (z[i - 1] == '0')
                z += '1';
            else
                z += '0';
            if (o[i - 1] == '0')
                o += '1';
            else
                o += '0';
        }
        cout<<z << endl;
        cout<<o << endl;
        int outputZ = 0, outputO = 0, result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (q[i] != z[i])
                outputZ++;
            if (q[i] != o[i])
                outputO++;
        }
        result = min(outputZ, outputO);
        cout<<"first result: "<<result << endl;
        int strt = 0, end = s.length();
        while (strt < s.length() and end < q.length())
        {
            if (q[strt] != z[strt])
                outputZ--;
            if (q[strt] != o[strt])
                outputO--;
            if (q[end] != z[end])
                outputZ++;
            if (q[end] != o[end])
                outputO++;
            result = min({result, outputZ, outputO});
            strt++;
            end++;
        }
        return result;
    }
    int main()
    {
        string s = "010";
        cout << minFlips(s) << endl;
        return 0;
    }
