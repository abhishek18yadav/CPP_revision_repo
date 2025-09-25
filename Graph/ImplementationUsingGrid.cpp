#include<bits/stdc++.h>
using namespace std;


vector<list<int>> gp;
void add_edge(int src, int dest, bool bi_dir =false){
    gp[src].push_back(dest);
    if(bi_dir){
        gp[dest].push_back(src);
    }
}
void display(){
    for (int i = 1; i <= gp.size(); i++){
        cout << i << "--> ";
        for(auto ele : gp[i]){
            cout << ele << " ";
        }
        cout << endl;
    }
}
void dfs(int node, unordered_set<int>&st){
    for( auto ele : gp[node]){
        if(!st.count(ele)){
            st.insert(ele);
            dfs(ele, st);
        }
    }
    return ;
}
int main(){
    vector<vector<int>> arr{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    gp.resize(20,list<int>());
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[i].size();j++){
            if(arr[i][j]==1){
                // cout << i << j << endl;
                add_edge(i+1, j+1);
            }
        }
    }
    // display();
    unordered_set<int> st;
    int count = 0;
    for (int i = 1; i <=arr.size(); i++){
        if(!st.count(i)){
            count++;
            st.insert(i);
            dfs(i, st);
        }
    }
    cout << "count" << count;
    return 0;
}