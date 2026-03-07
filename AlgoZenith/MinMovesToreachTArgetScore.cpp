
#include<bits/stdc++.h>
using namespace std;
    int minMoves(int target, int maxDoubles)
    {
        if (maxDoubles == 0)
            return target - 1;
        int count = 0;
        while (maxDoubles > 0 && target > 1)
        {
            if (target % 2 != 0)
            {
                target--;
                // cout<<target;
            }
            else
            {
                target /= 2;
                maxDoubles--;
                // cout<<target;
            }
            count++;
        }
        // cout<<count;
        count += (target > 1) ? (target - 1) : 0;
        //  cout<<count;
        return count;
    }
    int main()
    {
        int target = 19, maxDoubles = 2;
        cout << minMoves(target, maxDoubles);
        return 0;
    }
