
#include <bits/stdc++.h>
using namespace std;
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int strike = 1;
        int resh = 1, resv = 1;
        for (int i=1; i<hBars.size(); i++)
        {
            if(hBars[i] - hBars[i-1] ==1){
                strike++;
            }else{
                resh = max(resh, strike);
                strike = 1;
                
            }
        }
        resh = max(resh, strike);
        strike = 1;
        cout<<resh<<endl;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] - vBars[i - 1] == 1)
            {
                strike++;
            }
            else
            {
                resv = max(resv, strike);
                strike = 1;
                
            }
        }
        resv = max(resv, strike);
        cout<<resv<<endl;
        int spaceh = resh + 1;
        int spacev = resv + 1;
        int res = min(spaceh, spacev);
        return res * res;
    }

    int main(){
        int n = 3, m = 2;
        vector<int> hBars = {3, 2, 4,5};
        vector<int> vBars = {36,41,6,34,33};
        cout<<maximizeSquareHoleArea(n, m, hBars, vBars);

        return 0;
    }
