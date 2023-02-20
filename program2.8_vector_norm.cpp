#include <iostream>
#include <cstdio>
#include <cmath>
#include "matrix.hpp"

const int N = 6;

int main(void)
{
    double *a = matrix::dvector(1, N);

    for (int i = 1; i <= N; ++i)
    {
        a[i] = static_cast<double>(10 - i) / 20.0 * pow(-1.0, i);
    }
    for (int i = 1; i <= N; ++i)
    {
        printf("a[%d] = %f\n", i, a[i]);
    }

    printf("ベクトルaのL1ノルムは%fです\n",     matrix::vector_norm_L1(a, 1, N));
    printf("ベクトルaのL2ノルムは%fです\n",     matrix::vector_norm_L2(a, 1, N));
    printf("ベクトルaの最大値ノルムは%fです\n", matrix::vector_norm_max(a, 1, N));

    matrix::free_dvector(a, 1);

    return 0;
}
