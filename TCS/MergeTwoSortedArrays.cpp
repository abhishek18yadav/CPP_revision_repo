#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> ans(m+n);
    int i = 0, j = 0, k = 0;
    while(i<m and j<n){
        if(nums1[i]<nums2[j]){
            ans[k++] = nums1[i++];
        }else{
            ans[k++] = nums2[j++];
        }
    }
    while(i<m){
        ans[k++] = nums1[i++];
    }
    while(j<n){
        ans[k++] = nums2[j++];
    }
    for(int ele : ans){
        cout << ele << " ";
    }
}
int main(){

    vector<int> nums1 = {0,2,3,4,5,6}, nums2 = {2,5,6};
    merge(nums1, 6, nums2, 3);
    return 0;

}