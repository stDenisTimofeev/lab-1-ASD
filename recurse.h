#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

static void printVector(std::vector<int> output_vector)
{
    for (const auto& output_element : output_vector)
        std::cout << output_element << " ";
}

class Recurse {

    short L = 3;  // Количество единиц подряд
    short N = 7;  // Разрядность чисел
    short K = 4;  // Количество единиц

    std::vector<std::vector<int>> result;


public:
    Recurse(int N, int K, int L) : N(N), K(K), L(L)
    {


    }
    void GenerateAll(vector<int> vec, int n = 0, int k = 0, int l = 0);
    void Print();
    vector<vector<int>> Return();
};
