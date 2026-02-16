#include <bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int> &arr ,int n)
{
    set<pair<int, int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            continue;
        st.insert({i,arr[i]});
    }
    vector<int> res;
    while(st.size()>0){
        auto temp = *st.begin();
        res.push_back(temp.second);
        st.erase(temp);
    }
    
    return res;
}
int main()
{
    int N;
    cin >> N;

    int ele;
    vector<int> arr = {3, 0, 2};
    vector<int> ans = fun(arr, N);
    vector<int> res(N, 0);
    for (int i = 0; i < N; i++){
        if(i < ans.size()){
            res[i] = ans[i];
        }
        else
            res[i] = 0;
    }
    for(auto ele : res)
        cout << ele << " ";
        return 0;
}