#include<bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{

    public:
        unordered_map<int, int> mp;

        SmallestInfiniteSet()
        {

            for (int i = 1; i <= 1000; i++)
            {
                mp[i] = i;
            }
        }
        int popSmallest()
        {
            int req = INT_MAX;
            for (int i = 1; i <= mp.size(); i++)
            {
                if (req > mp[i])
                {
                    req = mp[i];
                }
            }
            mp[req] = INT_MAX;
            return req;
        }

        void addBack(int num)
        {
            mp[num] = num;
            return;
        }
};

int main() {
    // Your code here
    SmallestInfiniteSet s1;
    cout << s1.popSmallest() << endl; // Should return 1
    cout << s1.popSmallest() << endl; // Should return 2    
    s1.addBack(1); // Add 1 back to the set
    cout << s1.popSmallest() << endl; // Should return 1 again
    cout << s1.popSmallest() << endl; // Should return 3
    s1.addBack(2); // Add 2 back to the set
    cout << s1.popSmallest() << endl; // Should return 2 again
    // answer: 1 2 1 3 2
    return 0;
}