#include "merge_sort.h"
#include "insertion_sort.h"

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
    }
    while(i <= mid)temp[k++] = arr[i++];
    while(j <= right)temp[k++] = arr[j++];
    for(int m = 0; m < temp.size(); ++m)
        arr[left + m] = temp[m];
}

void merge_sort(vector<int>& arr, int left, int right, int threshold){
    if(right - left + 1 <= threshold){
        insertion_sort(arr, left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, threshold);
    merge_sort(arr, mid + 1, right, threshold);
    merge(arr, left, mid, right);
}