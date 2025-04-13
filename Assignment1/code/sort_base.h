#pragma once
#include <vector>
#include <string>

using namespace std;

enum class InputType{
    RANDOM,
    SORTED,
    REVERSED,
    DUPLICATED
};

void generate_input(vector<int>& arr, int size, InputType type);

bool is_sorted(const vector<int>& arr);

void print_array(const vector<int>& arr);

template<typename Func>
double measure_time(Func f, vector<int>& arr);