#include<bits/stdc++.h>
using namespace std;

int search(long no, vector<int> &potions,int spell, int init, int end)
{
    // when we find a potion[i] greater than no, we return it;
    int ans;
    if (init > end){
        cout<<"no: "<<no<<" potions[init]: "<<potions[init]<<endl;
        return init;
    }
    if (init <= end)
    {
        
        int mid = init + (end - init) / 2;
        if ((potions[mid]*spell) >= no)
        {
             ans =search(no, potions,spell, init, mid - 1);
        }
        else
            ans= search(no, potions,spell, mid + 1, end);
    }
    return ans;
}
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> res;
    for (int i = 0; i < spells.size(); i++)
    {
        
     
        int spell = spells[i];
        int idx = search(success, potions, spell,0, potions.size() - 1);
        cout<<"idx: "<<idx<<endl;
        res.push_back(potions.size() - idx);
    }
    return res;
}
int main(){
    // vector<int> spells={5,1,3};
    // vector<int> potions={1,2,3,4,5};
    vector<int> spells={3,1,2};
    vector<int> potions={8,5,8};
    long long success=16;
    //long long success=7;
    vector<int> ans=successfulPairs(spells,potions,success);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}