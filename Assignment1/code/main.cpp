#include "merge_sort.h"
#include "quick_sort.h"
#include "utils.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    vector<int> sizes = {1000, 10000, 100000};
    vector<int> thresholds = {5, 10, 20};
    vector<InputType> inputTypes = {
        InputType::RANDOM,
        InputType::SORTED,
        InputType::REVERSED,
        InputType::DUPLICATED
    };

    ofstream out("experiment_results.csv");
    out << "Algorithm,Size,Threshold,InputType,Time(ms),Sorted\n";

    for (int s : sizes) {
        for (int th : thresholds) {
            for (InputType type : inputTypes) {
                vector<int> data;
                generate_input(data, s, type);

                // Merge Sort
                vector<int> copy1 = data;
                double t1 = measure_time([&]() {
                    merge_sort(copy1, 0, copy1.size() - 1, th);
                });
                out << "MergeSort," << s << "," << th << ","
                    << static_cast<int>(type) << "," << t1 << ","
                    << (is_sorted(copy1) ? "Yes" : "No") << "\n";

                // Quick Sort
                vector<int> copy2 = data;
                double t2 = measure_time([&]() {
                    quick_sort(copy2, 0, copy2.size() - 1, th);
                });
                out << "QuickSort," << s << "," << th << ","
                    << static_cast<int>(type) << "," << t2 << ","
                    << (is_sorted(copy2) ? "Yes" : "No") << "\n";
            }
        }
    }

    out.close();
    cout << "實驗完成，結果輸出至 experiment_results.csv\n";
    return 0;
}
