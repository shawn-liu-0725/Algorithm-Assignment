/* main.cpp */
#include <iostream>
#include <fstream> 
#include "knapsack_utils.hpp"
#include "knapsack_topdown.hpp"
#include "knapsack_bottomup.hpp"
#include "knapsack_greedy.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main(int argc, char* argv[]) {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    istream* in = &cin;
    ifstream file;

    if (argc > 1) {
        file.open(argv[1]);
        if (!file) {
            cerr << "無法打開檔案: " << argv[1] << std::endl;
            return 1;
        }
        in = &file;
    }

    KnapsackInput input = read_knapsack_input(*in);

    // 分別呼叫三種演算法並取得結果
    int resultTopDown = knapsackTopDown(input.items, input.capacity);
    int resultBottomUp = knapsackBottomUp(input.items, input.capacity);
    int resultGreedy = knapsackGreedy(input.items, input.capacity);

    // 輸出各方法計算的結果
    cout << "自上而下 (Top-Down DP) 結果: " << resultTopDown << endl;
    cout << "自底向上 (Bottom-Up DP) 結果: " << resultBottomUp << endl;
    cout << "貪婪法 (Greedy) 結果: " << resultGreedy << endl;

    return 0;
}
