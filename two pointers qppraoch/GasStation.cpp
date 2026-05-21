#include<bits/stdc++.h>
using namespace std;
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        bool comple = false;
        int n = gas.size();
        vector<int>g(2*n);
        vector<int>c(2*n);
        for(int j=0; j< 2*n; j++){
            g[j] = gas[j % n];
            c[j] = cost[j % n];
        }
        
        while( i < n){
            int gs = 0;
            int cst = 0;

            for(int j=i ; j< i+n ; j++){
                gs += g[j];
                if(gs < c[j]){
                    i = j+1;
                    break;
                }
                if(gs >= cst and j == (i+n-1)){
                    return i;
                }
                gs = gs - c[j];
            }

        }
        return -1;
    }
int main(){
    vector<int>gas={1,2,3,4,5};
    vector<int>cost={3,4,5,1,2};
    cout<<canCompleteCircuit(gas,cost);
}