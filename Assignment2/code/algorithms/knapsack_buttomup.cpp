/* knapsack_bottomup.cpp */
#include "knapsack_bottomup.hpp"
#include <vector>
#include <algorithm>  // for std::max
using namespace std;

// 主函式：使用二維 DP 表自底向上計算最大價值
int knapsackBottomUp(const vector<Item>& items, int capacity) {
    int n = items.size();
    // DP 表 dp[i][w] 表示考慮前 i 件物品、背包容量為 w 時的最大價值
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    // 初始化：當 i=0（沒有物品）或 w=0（沒有容量）時，dp 值為 0（已由初始化完成）
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i-1].weight > w) {
                // 第 i 件物品無法放入容量 w，只能沿用前 i-1 件物品的結果
                dp[i][w] = dp[i-1][w];
            } else {
                // 比較放入與不放入的結果，取較大值
                int withoutItem = dp[i-1][w];
                int withItem = items[i-1].value + dp[i-1][w - items[i-1].weight];
                dp[i][w] = max(withoutItem, withItem);
            }
        }
    }
    
    return dp[n][capacity];
}
