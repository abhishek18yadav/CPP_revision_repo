#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void f(int N , int r , int idx , int end , vector<int> &arr){

    if(idx == N-1){
        arr[idx] = end;
        for(int i = 0 ; i < N ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        ans.push_back(arr);
        return;
    }
    for (int i = 1; i <= r; i++){
        if(arr[idx-1] == i)
            continue;
        if(idx == N-2 and i == end)
            continue;
        arr[idx] = i;
        f(N , r , idx + 1 , end , arr);
    }
}



int main(){
    int N = 4; // no of soldiers
    int r = 4; // range of soldiers
    int  end= 3; // soldier ending with range r
    int strt = 1;
    vector<int> arr(N);
    arr[0] = 1;
    f(N , r , 1 , end , arr);

    cout << ans.size();
    return 0;
}