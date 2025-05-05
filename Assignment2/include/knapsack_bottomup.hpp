/* knapsack_bottomup.hpp */
#ifndef KNAPSACK_BOTTOMUP_HPP
#define KNAPSACK_BOTTOMUP_HPP

#include <vector>
#include "knapsack_utils.hpp"

// 自底向上 DP 求解 0-1 背包問題，回傳最大價值
int knapsackBottomUp(const std::vector<Item>& items, int capacity);

#endif // KNAPSACK_BOTTOMUP_HPP
