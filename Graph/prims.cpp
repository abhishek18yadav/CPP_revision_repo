#include<bits/stdc++.h>
using namespace std;

#define pp pair<int,int>

vector<list<pp>>gp;
int v;// vertices

void add_edge(int src, int dest, int wt, bool bi_dir=true){
    gp[src].push_back({dest,wt});
    if(bi_dir){
        gp[dest].push_back({src,wt});
    }
}
void display(){
    for(int i=0; i<gp.size(); i++){
        cout<<i<<"->";
        for(auto ele : gp[i]){
            cout<<"("<<ele.first<<","<<ele.second<<")";
        }
        cout<<endl;
    }
}
int prims(int src, int e){
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    pq.push({0,src});
    unordered_map<int,int>mp;

    for(int i=0; i<v; i++){
        mp[i]= INT_MAX;
    }
    mp[src]=0;
    unordered_set<int>visited;
    int total_edges=0,sum=0;
    while(!pq.empty() && total_edges<e){
        pp temp = pq.top();
        // cout<<temp.second;
        if(visited.count(temp.second)){
            pq.pop();
            continue;
        }
        visited.count(temp.second);
        pq.pop();
        total_edges++;
        sum+=temp.first;
        // cout<<"sum:"<<sum;
        for(auto neigh : gp[temp.second]){
            if(!visited.count(neigh.first) and mp[neigh.first]> neigh.second){
                mp[neigh.first]=neigh.second;
                pq.push({neigh.second,neigh.first});
            }
        }
    }
    return sum;
}
int main(){
    int e;//edges
    cout<<"edges:"<<endl;
    cin>>e;
    cout<<"vert :"<<endl;
    cin>>v;
    gp.resize(v,list<pp>());
    cout<<"enter data src,dest,wt"<<endl;

    for(int i=0; i<e; i++){
        int src, dest,wt;
        cin>>src;
        cin>>dest;
        cin>>wt;
        add_edge(src,dest,wt,true);
    }
    // display();
    int src;
    cout<<"enter src"<<endl;
    cin>>src;
    cout<<prims(src,e);
    return 0;
}