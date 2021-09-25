#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int cost[6] = {1, 1, 1, 1, 1, 1};

int ed(const std::string &a, const std::string &b)
{
    int m = a.size(), n = b.size();
    if (m == 0)
    {
        return std::min(cost[5], m * cost[2]);
    }
    std::vector<std::vector<int>> d(m + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        d[0][i] = i * cost[3];
    }
    for (int i = 1; i <= m; ++i)
    {
        d[i][0] = i * cost[2];
    }
    for (int i = 1; i <= std::min(m, n); ++i)
    {
        int j;
        for (j = i; j <= m; ++j)
        {
            int ii = j, jj = i;
            int i = ii, j = jj;
            std::vector<int> dd;
            dd.reserve(5);
            if (a[i - 1] == b[j - 1])
                dd.emplace_back(cost[0] + d[i - 1][j - 1]);
            if (a[i - 1] != b[j - 1])
                dd.emplace_back(cost[1] + d[i - 1][j - 1]);
            dd.emplace_back(cost[2] + d[i - 1][j]);
            dd.emplace_back(cost[3] + d[i][j - 1]);
            if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1])
                dd.emplace_back(cost[4] + d[i - 2][j - 2]);
            d[i][j] = *std::min_element(dd.begin(), dd.end());
        }
        for (int j = 1; j <= n; ++j)
        {
            std::vector<int> dd;
            dd.reserve(5);
            if (a[i - 1] == b[j - 1])
                dd.emplace_back(cost[0] + d[i - 1][j - 1]);
            if (a[i - 1] != b[j - 1])
                dd.emplace_back(cost[1] + d[i - 1][j - 1]);
            dd.emplace_back(cost[2] + d[i - 1][j]);
            dd.emplace_back(cost[3] + d[i][j - 1]);
            if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1])
                dd.emplace_back(cost[4] + d[i - 2][j - 2]);
            d[i][j] = *std::min_element(dd.begin(), dd.end());
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int c = cost[5] + d[i][n];
        if (c < d[m][n])
            d[m][n] = c;
    }
    return d[m][n];
}

int main()
{
    std::cout << ed("algorithm", "altruistic") << std::endl;
}
