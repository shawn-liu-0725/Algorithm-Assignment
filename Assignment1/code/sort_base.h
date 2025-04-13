#pragma once
#include <vector>
#include <string>

enum class InputType{
    RANDOM,
    SORTED,
    REVERSED,
    DUPLICATED
};

void generate_input(std::vector<int>& arr, int size, InputType type);

bool is_sorted(const std::vector<int>& arr);

void print_array(const std::vector<int>& arr);

template<typename Func>
double measure_time(Func f, std::vector<int>& arr);