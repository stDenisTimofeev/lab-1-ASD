#include "Generator.h"
#include <algorithm>
#include <iostream>


bool Generator::canPut1(int i) {
    return std::accumulate(
            output_vector.begin() + i - m - 1,
            output_vector.begin() + i - 1,
            1, std::multiplies<bool>()
        )==0;
}

void Generator::GenerateAll()
{
    return_vector.push_back(output_vector);

    while (vector_changed)
    {
        vector_changed = false;
        for (short i = n - 1; i > 0; i--)
        {
            if (!(output_vector[i] && !output_vector[i - 1])) continue; // 01
            if (i < m + 1 || i >= m + 1 && canPut1(i))
            {
                output_vector.swap(output_vector[i], output_vector[i - 1]);

                if (i < n - 1)
                {
                    std::vector<bool> tail_vector = getMinTail(m, n - i - 1, std::accumulate(output_vector.begin() + i + 1, output_vector.end(), 0));

                    for (short j = i + 1; j < n; j++)
                        output_vector[j] = tail_vector[j - (i + 1)];
                }

                return_vector.push_back(output_vector);
                vector_changed = true;
                break;
            }

        }
    }

    printVectorOfVector(return_vector);
}

vector<vector<bool>> Generator::Return()
{
    return return_vector;
}
