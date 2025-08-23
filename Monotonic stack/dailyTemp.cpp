#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int sz = temperatures.size();
    vector<int> ans(sz, 0);
    stack<int> st;
    for (int i = 0; i < sz; i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);
    for(int days : result){
        cout << days << " ";
    }
    return 0;
}