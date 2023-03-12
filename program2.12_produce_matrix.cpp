#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "matrix.hpp"

const int ROW = 3; /* 行の要素数 */
const int COL = 4; /* 列の要素数 */

int main(void)
{
    double **a;
    int i, j;

    a = matrix::dmatrix(1, ROW, 1, COL); /* 行列 a[1...ROW][1...COL] */
    a = matrix::produce_matrix(a, 1, ROW, 1, COL); /* 行列の生成 */

    /* 行列の表示 */
    for (i = 1; i <= ROW; i++)
    {
        for (j = 1; j <= COL; j++)
        {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }
    matrix::free_dmatrix(a, 1, ROW, 1, COL); /* 行列領域の開放 */
    return 0;
}

