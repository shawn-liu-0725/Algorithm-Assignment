#include "utils.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

void generate_input(vector<int>& arr, int size, InputType type) {
    arr.resize(size);
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(0, size);
    switch (type) {
        case InputType::RANDOM:
            for (int& x : arr) x = dist(rng);
            break;
        case InputType::SORTED:
            for (int i = 0; i < size; ++i) arr[i] = i;
            break;
        case InputType::REVERSED:
            for (int i = 0; i < size; ++i) arr[i] = size - i;
            break;
        case InputType::DUPLICATED:
            for (int& x : arr) x = dist(rng) % 5; 
            break;
    }
}

bool is_sorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i)
        if (arr[i - 1] > arr[i]) return false;
    return true;
}

void print_array(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

double measure_time(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}
