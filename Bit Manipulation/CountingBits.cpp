#include<bits/stdc++.h>
using namespace std;

string NoToBinary(int n, string ans)
{
    if(n == 0)
        return ans + '0';
    if (n == 1)
        return ans + '1';
    int rem = n % 2;
    int quo = n / 2;
    char ch = rem + '0';
    ans = ch + ans;
    return NoToBinary(quo, ans);
}
vector<int> countBits(int n)
{
    string ans = "";
    vector<int> res(n + 1);
    
    for (int i = 0; i <= n; i++){
        ans = NoToBinary(i, "");
        reverse(ans.begin(), ans.end());
        int noOfOnes = 0;
        for (int j = 0; j < ans.size(); j++){
            if (ans[j] == '1'){
                noOfOnes++;
            }
        }
        res[i]=(noOfOnes);
    }
    return res;
}

int main(){
    int n;
    cin>>n; 
    vector<int> result = countBits(n);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}