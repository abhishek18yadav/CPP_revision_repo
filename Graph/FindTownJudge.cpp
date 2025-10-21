#include<bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int>indegree(n + 1, 0);
    for(int i=0; i<trust.size(); i++){
        indegree[trust[i][1]]++;
        indegree[trust[i][0]]--;
    }
    for(int i=1; i<=n; i++){
        cout<<indegree[i]<<" ";
        if(indegree[i] == n-1){
            return i;
        }
    }
    return -1;
}
int main(){
    int n = 3;
    vector<vector<int>>trust = {{1,3},{2,3},{3,1}};
    cout<<findJudge(n, trust)<<endl;
    return 0;
}