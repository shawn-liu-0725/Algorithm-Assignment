/* knapsack_topdown.hpp */
#ifndef KNAPSACK_TOPDOWN_HPP
#define KNAPSACK_TOPDOWN_HPP

#include <vector>
#include "knapsack_utils.hpp"

// 自上而下遞迴求解 0-1 背包問題，回傳最大價值
int knapsackTopDown(const std::vector<Item>& items, int capacity);

#endif // KNAPSACK_TOPDOWN_HPP
