#include<bits/stdc++.h>
using namespace std;



vector<list<int>> gp;
void generateGraph(int src,int dest , bool bi_dir){
    cout<<src<<" "<<dest<<endl;
    gp[src].push_back(dest);
    if(bi_dir){
        gp[dest].push_back(src);
    }
}

int countRooms(int src,unordered_set<int> &visited){
    for(auto neigh : gp[src]){
        if(!visited.count(neigh)){
            visited.insert(neigh);
          
            countRooms(neigh, visited);
        }
    }
    return visited.size();
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    for(int i = 0; i < rooms.size(); i++){
        for (int j = 0; j< rooms[i].size(); j++){
            generateGraph(i, rooms[i][j], false);
        }
    }
    for (int i = 0; i < gp.size(); i++){
        cout << i << "->";
        for(auto ele : gp[i]){
            cout << ele << " ";
        }
        cout << endl;
    }

        unordered_set<int> visited;
    visited.insert(0);
    int ans = countRooms(0, visited);
    // cout << "Total rooms visited: " << ans << endl;
    // size of viited is
    return ans == rooms.size();
}

int main(){
    gp.resize(4,list<int>());
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    if(canVisitAllRooms(rooms)){
        cout << "Yes, all rooms can be visited." << endl;
    } else {
        cout << "No, not all rooms can be visited." << endl;
    }
    return 0;
}