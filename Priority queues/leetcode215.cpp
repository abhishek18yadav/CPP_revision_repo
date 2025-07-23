#include<bits/stdc++.h>
using namespace std;


int findKthLargest(vector<int>& nums, int k) {

    // priority_queue<int>pq;
    priority_queue<int>pq(nums.begin(),nums.end());

    while(k>1){
        pq.pop();
        k--;
    }
    return pq.top();
 }
int main(){
    vector<int>nums{3,2,3,1,2,4,5,5,6};
    int ans = findKthLargest(nums,4);
    cout<<ans<<endl;
    return 0;
}