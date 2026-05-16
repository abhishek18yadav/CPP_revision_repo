
/**
 * Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of
N days. For each
i (
1≤i≤N), Taro will choose one of the following activities and do it on the
i-th day:

 A: Swim in the sea. Gain
a
i
​
  points of happiness.
B: Catch bugs in the mountains. Gain
b
i
​
  points of happiness.
C: Do homework at home. Gain
c
i
​
  points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.
Output
Print the maximum possible total points of happiness that Taro gains.

Sample Input 1
Copy
3
10 40 70
20 50 80
30 60 90
Sample Output 1
Copy
210
If Taro does activities in the order C, B, C, he will gain
70+50+90=210 points of happiness.
 */

 #include<bits/stdc++.h>
using namespace std;

int f(int r, int c, vector<vector<int>>&arr){
    if(r>= arr.size())
        return 0;
    int ans = INT_MIN;
    for (int i = 0; i < 3; i++){
        if(i == c)
            continue;
        ans = max(ans, arr[r][c] + f(r + 1, i, arr));
    }
    return ans;
}
int main(){
    // int n;
    // cin >> n;
    // vector<vector<int>> arr;
    // while(n--){
    //     int a,b,c;
    //     cin >> a >> b >> c;
    //     arr.push_back({a,b,c});
    // }
    int n = 7;
    vector<vector<int>> arr = {
        {6, 7, 8},
        {8 ,8 ,3},
        {2,5,2},
    {7,8,6},{4,6,8},{2,3,4},{7,5,1}};
    int ans = INT_MIN;
    for (int i = 0; i < 3; i++){
        ans = max(ans, f(0, i, arr));
    }
    cout << ans << endl;
    return 0;
}