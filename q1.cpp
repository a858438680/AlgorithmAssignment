#include <iostream>

bool check(int *a, int n)
{
    if (n == 1)
        return true;
    int possible = 0;
    for (int i = 1; i < n; ++i)
    {
        int idx = possible * n + i;
        if (a[idx])
        {
            possible = i;
        }
    }
    for (int i = 0; i < possible; ++i)
    {
        int idx1 = possible * n + i, idx2 = i * n + possible;
        if (a[idx1] || !a[idx2])
            return false;
    }
    for (int i = possible + 1; i < n; ++i)
    {
        int idx1 = possible * n + i, idx2 = i * n + possible;
        if (a[idx1] || !a[idx2])
            return false;
    }
    return true;
}

int main()
{
    int bm1[4][4] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {0, 0, 1, 0}, {1, 0, 1, 1}};
    int bm2[4][4] = {{0, 1, 1, 0}, {1, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 1, 1}};

    std::cout << check((int *)bm1, 4) << std::endl;
    std::cout << check((int *)bm2, 4) << std::endl;
}