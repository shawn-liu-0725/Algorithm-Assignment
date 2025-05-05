/* knapsack_topdown.cpp */
#include "knapsack_topdown.hpp"
#include <vector>
#include <algorithm>  // for std::max
using namespace std;

// 遞迴輔助函式：計算考慮前 i 件物品、背包容量為 w 時的最大價值
int knapsackTopDownRec(const vector<Item>& items, int i, int w, vector<vector<int>>& memo) {
    if (i == 0 || w == 0) {
        // 如果沒有物品可選，或背包容量為 0，則價值為 0
        return 0;
    }
    if (memo[i][w] != -1) {
        // 若已經計算過 [i][w] 狀態，則直接返回記憶化的結果
        return memo[i][w];
    }
    if (items[i-1].weight > w) {
        // 第 i 件物品無法放入背包（重量超過剩餘容量），只好跳過
        memo[i][w] = knapsackTopDownRec(items, i-1, w, memo);
    } else {
        // 可選擇放入或不放入第 i 件物品，取兩者中的最大值
        int withoutItem = knapsackTopDownRec(items, i-1, w, memo);
        int withItem = items[i-1].value + knapsackTopDownRec(items, i-1, w - items[i-1].weight, memo);
        memo[i][w] = max(withoutItem, withItem);
    }
    return memo[i][w];
}

// 主函式：初始化記憶化表並呼叫遞迴函式
int knapsackTopDown(const vector<Item>& items, int capacity) {
    int n = items.size();
    // 建立 (n+1) x (capacity+1) 的記憶化表，初始值設為 -1（表示未計算）
    vector<vector<int>> memo(n+1, vector<int>(capacity+1, -1));
    // 從考慮所有 n 件物品開始，求最大價值
    return knapsackTopDownRec(items, n, capacity, memo);
}
