/* knapsack_utils.hpp */
#ifndef KNAPSACK_UTILS_HPP
#define KNAPSACK_UTILS_HPP

#include <iostream>  // <-- 加入這一行修正 istream 未定義
#include <vector>

// 物品結構：表示每個物品的重量與價值
struct Item {
    int weight;   // 物品重量
    int value;    // 物品價值
};

// 背包輸入結構：包含物品數量 N、背包容量，以及物品列表
struct KnapsackInput {
    int N;                       // 物品數量
    int capacity;                // 背包容量
    std::vector<Item> items;     // 物品列表
};

// 讀取背包問題的輸入（從標準輸入讀取 N、capacity 及每個物品的重量和價值）
KnapsackInput read_knapsack_input();                    // 標準輸入版本
KnapsackInput read_knapsack_input(std::istream& in);    // 泛用輸入版本

#endif // KNAPSACK_UTILS_HPP
