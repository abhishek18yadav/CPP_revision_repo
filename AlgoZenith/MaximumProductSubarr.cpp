#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxProd = INT_MIN;
    int prefxProd = 1, suffxProd = 1;
    for (int i = 0; i < n; i++){
        prefxProd = prefxProd * nums[i];
        suffxProd = suffxProd * nums[n - i - 1];
        maxProd = max(maxProd, max(prefxProd, suffxProd));
        if(prefxProd == 0 )
            prefxProd = 1;
        if(suffxProd == 0)
            suffxProd = 1;
    }
    return maxProd;
}

int main(){
    vector<int> nums = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, -10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0};
    cout<<maxProduct(nums);
    return 0;
}