#include "quick_sort.h"
#include "insertion_sort.h"
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int left, int right){
    int pivot = arr[right];
    int i = left -1;
    for(int j = left; j < right; ++j){
        if(arr[j] < pivot){
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quick_sort(vector<int>& arr, int left, int right, int threshold){
    if(right - left + 1 <= threshold){
        insertion_sort(arr, left, right);
        return;
    }

    int pivot_index = partition(arr, left, right);
    quick_sort(arr, left, pivot_index - 1, threshold);
    quick_sort(arr, pivot_index + 1, right, threshold);
}
