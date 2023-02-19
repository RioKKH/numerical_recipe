#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "matrix.hpp"

const std::int32_t N = 5;

int main(void)
{
    double *a;
    double *b;
    a = matrix::dvector(1, N);
    b = matrix::dvector(1, N);
    for (int i = 1; i <= N; ++i)
    {
        a[i] = (double)i / 20.0;
        b[i] = (double)i / 10.0;
    }
    std::cout << "aとbの内積は" << matrix::inner_product(1, N, a, b) << std::endl;

    return 0;
}

