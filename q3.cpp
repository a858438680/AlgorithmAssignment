#include <iostream>
#include <vector>

int n = 3, W = 50;
int w[3] = {10, 20, 30};
int v[3] = {60, 100, 120};
std::vector<std::vector<int>> s(n + 1, std::vector<int>(W + 1, -1));

int knapsack(int i, int j)
{
    if (s[i][j] < 0)
    {
        int take = 0;
        if (j >= w[i])
            take = knapsack(i - 1, j - w[i]) + v[i];
        int not_take = knapsack(i - 1, j);
        s[i][j] = std::max(take, not_take);
    }
    return s[i][j];
}

int main()
{
    for (size_t i = 0; i <= n; ++i)
    {
        s[i][0] = 0;
    }
    for (size_t i = 0; i <= W; ++i)
    {
        s[0][i] = 0;
    }

    std::cout << knapsack(n, W) << std::endl;
}