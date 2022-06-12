#pragma once
#include <iostream>
#include "generator.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;
static void printVector(std::vector<bool> output_vector)
{
    for (const auto& output_element : output_vector)
        std::cout << output_element << " ";
}

static void printVectorOfVector(std::vector<std::vector<bool>> output_vector)
{
    for (const auto& output_element : output_vector)
    {
        printVector(output_element);
        std::cout << std::endl;
    }
}

static std::vector<bool> getMinTail(short m, short n, short k)
{
    std::vector<bool> tail_vector;

    tail_vector.reserve(n);
    tail_vector.resize(n);

    std::generate_n(std::begin(tail_vector), n, [i = 0, m_ = m, n_ = n, k_ = k]()
        mutable
    {
        bool value = false;
        if (n_ - k_ - i <= (k_ / m_ - 1 + (k_ % m_ == 0 ? 0 : 1))
            //&& (n_ - i) % (m_ + 1) <= m_
            && (n_ - i) % (m_ + 1) > 0) {
            value = true;
        }
        i++;
        return value;
    });

    return tail_vector;
}
class Generator {

    short m = 3;  // Количество единиц подряд
    short n = 7;  // Разрядность чисел
    short k = 5;  // Количество единиц

    std::vector<bool> output_vector;

    std::vector<std::vector<bool>> return_vector;
    
    

    bool vector_changed = true;

public:
    Generator(int n, int k) : n(n), k(k)
    {
       output_vector = getMinTail(m, n, k);

    }
    bool canPut1(int i);
    void GenerateAll();
    vector<vector<bool>> Return();
};
