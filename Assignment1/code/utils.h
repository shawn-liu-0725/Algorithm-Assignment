#pragma once
#include <vector>
#include <functional>
#include <string>

using namespace std;

enum class InputType {
    RANDOM,
    SORTED,
    REVERSED,
    DUPLICATED
};

void generate_input(vector<int>& arr, int size, InputType type);

bool is_sorted(const vector<int>& arr);

void print_array(const vector<int>& arr);

double measure_time(function<void()> func);
