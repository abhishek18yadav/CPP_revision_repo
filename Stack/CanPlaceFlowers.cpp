#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{

    stack<int> st;
    int j = 0;
    while (n > 0 and j < flowerbed.size() - 1)
    {
        if (j == 0 and flowerbed[j] == 0)
        {
            if (flowerbed[j + 1] == 0)
            {
                flowerbed[j] = 1;
                n--;
            }
        }
        else if (!st.empty() and flowerbed[j] == 0)
        {
            if (st.top() == 0 and flowerbed[j + 1] == 0)
            {
                flowerbed[j] = 1;
                n--;
            }
        }
        st.push(flowerbed[j]);
        j++;
    }
    if (j == flowerbed.size() - 1 and flowerbed[j] == 0 and n > 0)
    {
        if (j - 1 > 0 and flowerbed[j - 1] == 0)
            n--;
        else
        {
            if (n > 0 and j - 1 < 0)
                n--;
        }
    }
    return n == 0;
}

int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    cout << canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}