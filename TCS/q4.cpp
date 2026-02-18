#include<bits/stdc++.h>
using namespace std;
int pivot(vector<int>&arr, int low, int high){
    
    int ele = arr[low];
    int count = 0;
    for (int i = low+1; i <= high; i++){
        if(arr[i] <= ele)
            count++;
    }
    int pivotIdx = low + count;
    swap(arr[low], arr[pivotIdx]);
    int i = low, j = high ;
    // while(i<pivotIdx and j>pivotIdx){
    //     while(arr[i] <= arr[pivotIdx] and i<pivotIdx)
    //         i++;
    //     while(arr[j] > arr[pivotIdx] and j>pivotIdx)
    //         j--;
    //     if(arr[i]> arr[pivotIdx] and arr[j]<arr[pivotIdx]){
    //         swap(arr[i], arr[j]);
    //         i++;
    //         j--;
    //     }
    // }
    while (i < pivotIdx && j > pivotIdx)
    {
        // Use < and > rather than <= and >= to ensure pointers
        // move past elements equal to the pivot
        while (arr[i] <= arr[pivotIdx] && i < pivotIdx)
            i++;
        while (arr[j] > arr[pivotIdx] && j > pivotIdx)
            j--;

        if (i < pivotIdx && j > pivotIdx)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}
void QuickSort(vector<int>&arr, int low, int high){
    if(low >= high)
        return ;
    int idx = pivot(arr, low, high);
    QuickSort(arr, low, idx - 1);
    QuickSort(arr,idx + 1,high );
}
int main(){
    vector<int> arr = {0,1,0};
    // cout << "s1";
    QuickSort(arr, 0, arr.size()-1);
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}