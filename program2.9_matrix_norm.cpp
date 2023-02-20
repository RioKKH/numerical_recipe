#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "matrix.hpp"

const int ROW    = 3;
const int COLUMN = 4;

int main(void)
{
    double **a = matrix::dmatrix(1, ROW, 1, COLUMN); // a[1...ROW][1...COLUMN]

    /* 行列の定義 */
    printf("A=\n");
    for (int i = 1; i <= ROW; ++i)
    {
        for (int j = 1; j <= COLUMN; ++j)
        {
            a[i][j] = 2.0 * (i + j) * pow(-1.0, j);
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }

    printf("A のL1ノルムは%f\n", matrix::matrix_norm_L1(a, 1, ROW, 1, COLUMN));
    printf("A の最大値ノルムは%f\n", matrix::matrix_norm_max(a, 1, ROW, 1, COLUMN));

    matrix::free_dmatrix(a, 1, ROW, 1, COLUMN);

    return 0;
}
