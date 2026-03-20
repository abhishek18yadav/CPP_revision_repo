
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, b, p, j, k;
    /**
     * n->no no of monkeys,
     * b->no of bananas total
     * p-> no of peanuts total
     * j-> no of banans can be eat by 1 monkey for full stomach
     * k-> no of peanuts can be eat by 1 monkey for full stomach
     */
    cin >> n >> b >> p >> j >> k;
    int countMon_Bananas = b / j;
    int leftBananas = b % j;
    int countMon_Peanuts = p / k;
    int leftPeanuts = p % k;
    int countMon = countMon_Bananas + countMon_Peanuts;
    if(leftBananas > 0 or leftPeanuts > 0){
        countMon++;
    }
    int leftMon = n - countMon;
    cout<<"monkeys left on the tree: "<<leftMon;
    return 0;
}
