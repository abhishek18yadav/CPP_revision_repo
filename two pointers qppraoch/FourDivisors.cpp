#include <bits/stdc++.h>
using namespace std;


    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0;
        for (auto ele : nums)
        {
            int sum = 0;
            int countDiv = 0;
            for (int i = 2; i * i < ele; i++)
            {

                if (ele % i == 0)
                {
                    countDiv++;
                    if (countDiv > 2)
                        break;
                    sum += i;
                    int secondDiv = ele / i;
                    if (secondDiv != i)
                    {
                        countDiv++;
                        if (countDiv > 2)
                            break;
                        sum += secondDiv;
                    }
                }
            }
            if (countDiv == 2)
                ans = ans + 1 + ele + sum;
        }
        return ans;
    }
    int main()
    {
        vector<int> nums = {21,21};
        cout<<sumFourDivisors(nums);
        return 0;
    }
