#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<int>tree;
    public:
    SegmentTree(vector<int>&arr){
        n = arr.size();
        tree.resize(4*n);
    }
    void build(vector<int>&arr, int node, int l, int r){
        if(l == r){
            tree[node] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(arr, 2 * node + 1, l, mid);
        build(arr, 2 * node + 2, mid + 1, r);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        return;
    }
    void update(vector<int>&arr, int idx,int node , int val, int l, int r){
        if(l == r and l == idx){
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx > mid){
            update(arr, idx, 2 * node + 2, val, mid + 1, r);
        }else{
            update(arr, idx, 2 * node + 1, val, l, mid);
        }
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        return;
    }
    int query(int qL , int qR, int l, int r, int node){
        if(qL > r || qR < l)return INT_MAX;
        if(l >= qL && r <= qR)return tree[node];
        int mid = l + (r - l) / 2;
        return min(query(qL, qR, l, mid, 2 * node + 1), query(qL, qR, mid + 1, r, 2 * node + 2));
    }
};
int main(){
    vector<int> arr = {2, 5, 67, 34, 12, 87, 3, 4};
    SegmentTree st(arr);
    st.build(arr, 0, 0, arr.size() - 1);
    cout << st.query(0, 4, 0, arr.size() - 1, 0) << endl;
    st.update(arr, 2, 0, 1, 0, arr.size() - 1);
    cout << st.query(0, 4, 0, arr.size() - 1, 0) << endl;
    return 0;
}