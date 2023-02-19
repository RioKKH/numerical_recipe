#include <iostream>
#include "matrix.hpp"

const int N = 5;
using namespace matrix;

int main(void)
{

    double *a;
    int i;

    a = matrix::dvector(1, N);
    for (i = 1; i <= N; i++)
    {
        a[i] = (double)i;
    }

    for (int i = 1; i <= N; i++)
    {
        std::cout << a[i] << std::endl;
    }
    matrix::free_dvector(a, 1);
}

