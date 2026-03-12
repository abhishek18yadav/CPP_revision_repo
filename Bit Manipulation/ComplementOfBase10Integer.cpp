
#include <bits/stdc++.h>
using namespace std;

    int integer(string n)
    {
        int count=0;
        int res = 0;
        for(int i=n.length()-1;i>=0;i--){
            int no = (n[i]-'0');
            res += (no * (1<<count));
            count++;
        }
            return res;
    }
    string binary(int n)
    {
        string ans = "";
        if(n==0)
            return "1";
        while (n)
        {
            if (n % 2 == 0)
                ans += '0';
            else
                ans += '1';
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        
        // flippinf the string
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='0')
                ans[i]='1';
            else
                ans[i]='0';
        }
        cout<<"binary is "<<ans<<endl;
        return ans;
    }
    int bitwiseComplement(int n)
    {
        string ans = binary(n);
        return integer(ans);
    }
    int main()
    {
        int n = 0;
        cout << bitwiseComplement(n) << endl;
        return 0;
    }