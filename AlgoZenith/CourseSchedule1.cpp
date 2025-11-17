#include<bits/stdc++.h>
using namespace std;

vector<list<int>> gp;
void add_edge(int src, int dst){
    gp[src].push_back(dst);
}
void display(){
    for (int i = 0; i < gp.size(); i++){
        cout << i << "-->";
        for(auto ele : gp[i]){
            cout << ele << " ";
        }
        cout << endl;
    }
}
 int dfs(int src, int numCourse , unordered_set<int>&vis){
     for (auto nei : gp[src])
     {
         if (!vis.count(nei))
         {
             vis.insert(nei);
             return 1+ dfs(nei, numCourse, vis);
             
         }
         else{
             return -3000;
         }
        
    }
    return 0 ;
 }
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    gp.resize(numCourses, list<int>());
    for (auto ele : prerequisites){
        int src = ele[1];
        int dst = ele[0];
        add_edge(src, dst);
    }
    display();
    return 0;
}

int main(){
    int numCourses = 5;
    //[[1,4],[2,4],[3,1],[3,2]]
    vector<vector<int>> prerequisites {{1,4},{2,4},{3,1},{3,2}};
    cout<<canFinish(numCourses, prerequisites);
    return 0;
}