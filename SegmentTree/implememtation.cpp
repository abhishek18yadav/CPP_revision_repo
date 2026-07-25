#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<int> tree;
    int n;
    public:
    SegmentTree(vector<int>&arr){
        int n = arr.size();
        tree.resize(4 * n);
    }
    int  build(vector<int>&arr , int node , int strt, int end){
        if(strt == end){
            tree[node] = arr[strt];
            return tree[node];
        }
        int mid = strt + (end - strt) / 2;
        int leftChild = build(arr, 2 * node + 1, strt, mid);
        int rightchild = build(arr, 2 * node + 2, mid + 1, end);
        return  tree[node] = leftChild + rightchild;
    }
    void update(int idx, vector<int>&arr,int node , int val, int nL, int nR){
        if(nL == nR and nL == idx){
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        int mid = nL + (nR - nL) / 2;
        if(idx>mid){
            update(idx, arr, 2 * node + 2, val, mid + 1, nR);
        }else{
            update(idx, arr, 2 * node + 1, val, nL, mid);
        }
        tree[node] = tree[2*node+1] + tree[2*node+2];
        return;
    }
    int query(int qL, int qR, vector<int>&arr, int node, int l, int r){
        // no overlapping
        if(qL > r || qR < l)return 0;
        // complete overlapping
        if(l>= qL and r<= qR)
            return tree[node];
        int mid = l+ (r-l)/2;
        return query(qL,qR,arr,2*node+1,l,mid) + query(qL,qR,arr,2*node+2,mid+1,r);
    }
};
int main(){
    vector<int> arr = {1, 2, 3, 5, 6, 7};
    SegmentTree st(arr);
    st.build(arr, 0, 0, arr.size() - 1);
    cout << st.query(0, 4, arr, 0, 0, arr.size() - 1) << endl;
    st.update(2, arr, 0, 10, 0, arr.size() - 1);
    cout << st.query(0, 4, arr, 0, 0, arr.size() - 1) << endl;
    return 0;
}