#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    vector<int> res;
    int i = 0;
    while (i < asteroids.size())
    {
        if (!st.empty() and asteroids[i] < 0 and st.top() > 0 and abs(asteroids[i]) == abs(st.top()))
        {
            st.pop();
            res.pop_back();
            i++;
            
        }
        else if (i < asteroids.size() and !st.empty() and asteroids[i] < 0 and st.top() > 0)
        {
            if (abs(asteroids[i]) > st.top())
            {
                st.pop();
                res.pop_back();
            }
            else
                i++;
        }
        else
        {
            if (i < asteroids.size())
            {
                st.push(asteroids[i]);
                res.push_back(asteroids[i]);
                i++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> asteroids = {1, 1, -1, -1};
    vector<int> res = asteroidCollision(asteroids);
    for (auto ele : res)
        cout << ele << " ";
    return 0;
}