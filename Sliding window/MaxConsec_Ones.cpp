#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int left = 0, right = 0, maxLen = 0;
   // int len = 0;
    while (right < nums.size())
    { // {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

        if (nums[right])
        {
           // len++;
            right++;
        }
        else
        {
            if (k == 0)
            {
                int len= (right - left);
                maxLen = max(maxLen, len);
                if (nums[left] == 0)
                {
                    k++;
                }
                left++;
               // len = 0;
            }
            else
            {
                //len++;
                k--;
                right++;
            }
        }
    }
    int len = (right - left);
    maxLen = max(maxLen, len);
    return maxLen;
}
int main(){
    vector<int> nums = {0, 0, 0, 1};
    int k = 4;
    cout<<longestOnes(nums,k);
    return 0;
}