#include<bits/stdc++.h>
using namespace std;


    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {

        int sz = queries[0].size();
        vector<string> ans;
        for (int i = 0; i < queries.size(); i++)
        {

            for (int j = 0; j < dictionary.size(); j++)
            {
                int count = 0;
                unordered_set<string> st;
                for (int idx = 0; idx < sz; idx++)
                {
                    if (queries[i][idx] != dictionary[j][idx])
                        count++;
                }
                if (count <= 2 and !st.count(queries[i]))
                {
                    ans.push_back(queries[i]);
                    st.insert(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }

int main(){
    vector<string> queries = {"word", "note", "ants", "wood"};
    vector<string> dictionary = {"word", "note", "wood"};
    vector<string> ans = twoEditWords(queries, dictionary);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
