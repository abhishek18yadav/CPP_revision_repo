#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
        int strt = 0;
        int end = height.size()-1;
        int vol =-1;
        while(strt<end){
            int width = end-strt;
            int hyt = min(height[strt],height[end]);
            int newVol = width * hyt;
            if(newVol >vol)vol=newVol;
            if(height[strt]>height[end])end--;
            else strt++;
        }
        return vol;
    }

int main(){
    vector<int>height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    return 0;
}