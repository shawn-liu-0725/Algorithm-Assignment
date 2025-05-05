/* knapsack_greedy.hpp */
#ifndef KNAPSACK_GREEDY_HPP
#define KNAPSACK_GREEDY_HPP

#include <vector>
#include "knapsack_utils.hpp"

// 貪婪法（按照價值/重量比排序後選擇），回傳總價值
int knapsackGreedy(const std::vector<Item>& items, int capacity);

#endif // KNAPSACK_GREEDY_HPP
