#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "matrix.hpp"

const int L = 3;
const int M = 2;
const int N = 3;

int main(void)
{
    double **a, **b, **c;
    a = matrix::dmatrix(1, L, 1, M); // a[1...L][1...M] L行M列
    b = matrix::dmatrix(1, M, 1, N); // a[1...M][1...N] M行N列
    c = matrix::dmatrix(1, L, 1, N); // a[1...L][1...N] l行N列

    /* 行列 A の定義 */
    for (int i = 1; i <= L; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            a[i][j] = 2.0 * (i + j);
        }
    }

    /* 行列 B の定義 */
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            b[i][j] = 2.0 * (i + j);
        }
    }

    matrix::matrix_product(a, b, c, 1, L, 1, M, 1, N);

    std::cout << "A x Bの結果は次の通り" << std::endl;

    for (int i = 1; i <= L; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }

    matrix::free_dmatrix(a, 1, L, 1, M);
    matrix::free_dmatrix(b, 1, M, 1, N);
    matrix::free_dmatrix(c, 1, L, 1, N);
    return 0;
}

