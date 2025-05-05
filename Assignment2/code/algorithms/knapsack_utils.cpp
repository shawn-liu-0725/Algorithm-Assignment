/* knapsack_utils.cpp */
#include "knapsack_utils.hpp"
#include <iostream>
using namespace std;

// 使用 cin 從標準輸入讀取背包問題的資料，並回傳包含所有輸入的 KnapsackInput 結構
KnapsackInput read_knapsack_input() {
    KnapsackInput input;
    cout << "Enter number of items and capacity: ";
    cin >> input.N >> input.capacity;
    input.items.resize(input.N);
    cout << "Enter weight and value for each item:" << endl;
    for (int i = 0; i < input.N; i++) {
        cout << "Item " << i+1 << ": ";
        cin >> input.items[i].weight >> input.items[i].value;
    }
    return input;
}

KnapsackInput read_knapsack_input(istream& in) {
    KnapsackInput input;
    in >> input.N >> input.capacity;
    input.items.resize(input.N);
    for (int i = 0; i < input.N; ++i) {
        in >> input.items[i].weight >> input.items[i].value;
    }
    return input;
}
