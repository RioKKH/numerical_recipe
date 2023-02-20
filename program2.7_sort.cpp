#include <iostream>
#include <cstdio>
#include <cstdlib>
// #include "myutility.hpp"
#include "matrix.hpp"

const int N = 7;

int main(void)
{
    double a[N] = {1.2, -2.3, -4.2, 5.5, 2.1, 7.2, 3.1};

    // 並べ替え
    qsort(a, N, sizeof(a[0]), matrix::double_comp);
    for (int i = 0; i < N; ++i)
    {
        std::cout << a[i] << std::endl;
    }

    return 0;
}
