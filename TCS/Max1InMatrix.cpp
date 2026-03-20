#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    int resultantRow = 0 , resultZero = -1;
    for (int i = 0; i < n; i++){
        int ones = 0, ele ;
        for (int j = 0; j < m; j++){
            cin >> ele;
            if(ele == 1)
                ones++;
            arr[i][j] = ele;
        }
        if(ones > resultZero){
            resultZero = ones;
            resultantRow = i+1;
        }
    }
    cout << "row with max ones is\t"<< resultantRow;
    return 0;
}