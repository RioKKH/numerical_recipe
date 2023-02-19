#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "matrix.hpp"

const int M = 2;
const int N = 3;

int main(void)
{
    double **a;
    int i, j;
    a = matrix::dmatrix(1, M, 1, N);
    for (i =1; i <= M; i++)
    {
        for (j = 1; j <= N; j++)
        {
            a[i][j] = (i + j) / 2.0;
        }
    }

    // show matrix
    for (i =1; i <= M; i++)
    {
        for (j = 1; j <= N; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    matrix::free_dmatrix(a, 1, M, 1, N);

    return 0;
}


