#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

vector<float> f(vector<float> arr)
{
    unordered_set<float> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 41.225)
            continue;
        else
            st.insert(arr[i]);
    }
    // cout << "st.size(" << st.size();
    if (st.size() == 1)
    {
        return {*st.begin()};
    }
    if (st.size() == 2)
    {
        float ele1 = *st.begin();
        st.erase(ele1);
        return {ele1, *st.begin()};
    }
    float ans = 0.0;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        // cout << "*it" << *it;
        ans = max(ans, *it);
    }
    // cout << ans << "ans";
    return {ans};
}

int main()
{
    // your code goes here
    float distance;
    cin >> distance;
    int racers;
    cin >> racers;
    float ele;
    vector<float> ans;
    vector<float> arr;
    for (int i = 0; i < racers; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    ans = f(arr);
    cout << ans[0];
    return 0;
}