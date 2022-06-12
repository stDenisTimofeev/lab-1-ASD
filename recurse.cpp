#include "Recurse.h"


void Recurse::GenerateAll(vector<int> vec ,int n, int k, int l )
{
	vector<int> tmp1 = vec;
	vector<int> tmp2 = vec;
	tmp1.push_back(0);
	tmp2.push_back(1);
	if (vec.size() == N)
	{
		if (k == K)
		{
			result.push_back(vec);
		}
		return;
	}

	if (k == K)
	{
		GenerateAll(tmp1, n + 1, k, 0);
		return;
	}

	if (l == L)
	{
		GenerateAll(tmp1, n + 1, k, 0);
		return;
	}

	if(n + 1 + K - k  <= N)
	{
		GenerateAll(tmp1, n + 1, k, 0);
	}

	if(n + 1 + K - k - 1 <= N && l + 1 <= L)
	{
		GenerateAll(tmp2, n + 1, k + 1, l + 1);
	}
}

void Recurse::Print()
{
	for (const auto& output_element : result)
	{
		printVector(output_element);
		std::cout << std::endl;
	}
}

vector<vector<int>> Recurse::Return()
{
	return result;
}
