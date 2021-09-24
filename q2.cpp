#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

std::tuple<std::vector<int>, std::vector<int>> bipartite(int *g, int n)
{
    std::vector<int> od(n);
    std::vector<int> indices(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[i * n + j] > 0)
            {
                ++od[i];
            }
        }
        indices[i] = i;
    }
    std::sort(indices.begin(), indices.end(), [&](int a, int b) { return od[a] < od[b]; });
    auto k = std::distance(indices.begin(), indices.end()) / 2;
    auto mid = indices.begin() + k;
    if (n % 2 == 1 && k > od[k])
    {
        return {std::vector<int>{indices.begin(), mid + 1}, std::vector<int>{mid + 1, indices.end()}};
    }
    else
    {
        return {std::vector<int>{indices.begin(), mid}, std::vector<int>{mid, indices.end()}};
    }
}

int main()
{
    int g[5][5] = {
        {0, 1, -1, 1, 1}, {-1, 0, 1, -1, 1}, {1, -1, 0, -1, -1}, {-1, 1, 1, 0, 1}, {-1, -1, 1, -1, 0},
    };

    auto [A, B] = bipartite((int *)g, 5);
    for (size_t i = 0; i < A.size(); ++i)
    {
        std::cout << A[i] << ' ';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < B.size(); ++i)
    {
        std::cout << B[i] << ' ';
    }
    std::cout << std::endl;
}