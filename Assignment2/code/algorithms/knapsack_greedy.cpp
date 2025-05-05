// greedy_solver.cpp
#include "knapsack_greedy.hpp"
#include <algorithm>
using namespace std;

int knapsackGreedy(const std::vector<Item> &items, int capacity) {
    //計算每個 item 的性價比 (value/weight)，並排序
    vector<Item> sorted_items = items;
    sort(sorted_items.begin(), sorted_items.end(), [](const Item &a, const Item &b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    int total_value = 0;
    int remaining_capacity = capacity;
    for (const Item &item : sorted_items) {
        if (item.weight <= remaining_capacity) {
            remaining_capacity -= item.weight;
            total_value += item.value;
        }
    }
    return total_value;
}
