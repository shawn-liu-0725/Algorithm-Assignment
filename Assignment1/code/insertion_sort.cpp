#include "insertion_sort.h"

using namespace std;

void insertion_sort(vector<int>& arr, int left, int right){
    for(int i = left +1; i <= right; ++i){
        int key = arr[i];
        int j = i-1;
        while(j >= left && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
